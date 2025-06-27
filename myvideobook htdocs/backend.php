<?php
header('Content-Type: application/json');
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST, OPTIONS");
header("Access-Control-Allow-Headers: Content-Type");


error_reporting(E_ALL);
ini_set('display_errors', 1);

set_error_handler(function ($severity, $message, $file, $line) {
    throw new ErrorException($message, 0, $severity, $file, $line);
});

try {
    require_once 'db_connect.php';

  
    if (!file_exists('uploads/profile_photos')) {
        mkdir('uploads/profile_photos', 0755, true);
    }
    if (!file_exists('uploads/book_logos')) {
        mkdir('uploads/book_logos', 0755, true);
    }

    function sanitizeInput($input)
    {
        if ($input === null) return '';
        if (is_array($input)) return array_map('sanitizeInput', $input);
        return trim(htmlspecialchars(strip_tags((string)$input), ENT_QUOTES | ENT_SUBSTITUTE, 'UTF-8'));
    }

    function saveProfilePhoto($base64Image, $userId)
    {
        $uploadDir = 'uploads/profile_photos/';
        if (!preg_match('/^data:image\/(png|jpe?g|gif);base64,/', $base64Image)) return null;

        $imageData = base64_decode(preg_replace('#^data:image/\w+;base64,#i', '', $base64Image));
        $fileName = 'user_' . $userId . '_' . time() . '.png';
        if (file_put_contents($uploadDir . $fileName, $imageData)) return $uploadDir . $fileName;
        return null;
    }

    function saveBookLogo($base64Image, $bookId)
    {
        $uploadDir = 'uploads/book_logos/';
        if (!preg_match('/^data:image\/(png|jpe?g|gif);base64,/', $base64Image)) return null;

        $ext = preg_match('/^data:image\/(jpe?g)/', $base64Image) ? 'jpg' : 'png';
        $imageData = base64_decode(preg_replace('#^data:image/\w+;base64,#i', '', $base64Image));
        $fileName = 'book_' . $bookId . '.' . $ext;
        // $fileName = 'book_' . $bookId . '.' . '.png';
        if (file_put_contents($uploadDir . $fileName, $imageData)) return $uploadDir . $fileName;
        return null;
    }

    function jsonResponse($data, $statusCode = 200)
    {
        http_response_code($statusCode);
        echo json_encode($data);
        exit;
    }


    function extractYouTubeId($url)
    {
        $pattern = '%(?:youtube(?:-nocookie)?\.com/(?:[^/]+/.+/|(?:v|e(?:mbed)?)/|.*[?&]v=)|youtu\.be/)([^"&?/ ]{11})%i';
        preg_match($pattern, $url, $matches);
        return isset($matches[1]) ? $matches[1] : false;
    }

    // GET Requests
    if ($_SERVER['REQUEST_METHOD'] === 'GET' && isset($_GET['action'])) {
        $action = sanitizeInput($_GET['action']);

        switch ($action) {
            case 'get_categories':
                $stmt = $conn->query("select * from categories where logo IS NOT NULL");
                jsonResponse($stmt->fetchAll(PDO::FETCH_ASSOC));
                break;

            case 'get_category_videos':
                if (!isset($_GET['category'])) jsonResponse(['error' => 'Category required'], 400);
                $stmt = $conn->prepare("SELECT * FROM videos WHERE category = ?");
                $stmt->execute([sanitizeInput($_GET['category'])]);
                jsonResponse($stmt->fetchAll(PDO::FETCH_ASSOC));
                break;

            case 'get_user_book':
                if (!isset($_GET['book_id'])) jsonResponse(['error' => 'Book ID required'], 400);
                $stmt = $conn->prepare("SELECT b.*, u.email as author_email FROM books b LEFT JOIN users u ON b.user_id = u.id WHERE b.id = ?");
                $stmt->execute([(int)$_GET['book_id']]);
                $book = $stmt->fetch(PDO::FETCH_ASSOC);
                if (!$book) jsonResponse(['error' => 'Book not found'], 404);
                jsonResponse($book);
                break;

            default:
                jsonResponse(['error' => 'Invalid action'], 400);
        }
    }

    // POST Requests
    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $data = json_decode(file_get_contents('php://input'), true);
        if (json_last_error() !== JSON_ERROR_NONE) jsonResponse(['error' => 'Invalid JSON'], 400);
        $data = sanitizeInput($data);

        if (!isset($data['action'])) jsonResponse(['error' => 'Action required'], 400);

        switch ($data['action']) {
            case 'register':
                if (!isset($data['email']) || !isset($data['password']) || !isset($data['namePassed'])) {
                    jsonResponse(['error' => 'Email , name and password are required'], 400);
                }

                $email = filter_var($data['email'], FILTER_SANITIZE_EMAIL);
                if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
                    jsonResponse(['error' => 'Invalid email address'], 400);
                }

                $password = password_hash($data['password'], PASSWORD_DEFAULT);
                $profilePhoto = null;

                // echo $data['namePassed'];

                $namePassed = $data['namePassed'];

                try {
                    $conn->beginTransaction();

                    $stmt = $conn->prepare("INSERT INTO users (name,email, password) VALUES (?,?, ?)");
                    $stmt->execute([$namePassed, $email, $password]);
                    $userId = $conn->lastInsertId();

                    if (isset($data['profile_photo']) && !empty($data['profile_photo'])) {
                        $profilePhoto = saveProfilePhoto($data['profile_photo'], $userId);
                        if ($profilePhoto) {
                            $stmt = $conn->prepare("UPDATE users SET profile_photo = ? WHERE id = ?");
                            $stmt->execute([$profilePhoto, $userId]);
                        }
                    }

                    $conn->commit();
                    jsonResponse([
                        'success' => true,
                        'user_id' => $userId,
                        'user_name' => $namePassed,
                        'email' => $email,
                        'profile_photo' => $profilePhoto
                    ]);
                } catch (PDOException $e) {
                    $conn->rollBack();
                    jsonResponse(['error' => 'Email already exists'], 400);
                }
                break;

            case 'login':
                if (!isset($data['email']) || !isset($data['password'])) {
                    jsonResponse(['error' => 'Email and password are required'], 400);
                }

                $email = filter_var($data['email'], FILTER_SANITIZE_EMAIL);
                $password = $data['password'];

                $stmt = $conn->prepare("SELECT * FROM users WHERE email = ?");
                $stmt->execute([$email]);
                $user = $stmt->fetch(PDO::FETCH_ASSOC);

                if (!$user) {
                    jsonResponse(['error' => 'Email not registered'], 401);
                }

                if (!password_verify($password, $user['password'])) {
                    jsonResponse(['error' => 'Invalid password'], 401);
                }

                $profilePhoto = $user['profile_photo'] ?? null;

                if (isset($data['profile_photo']) && !empty($data['profile_photo'])) {
                    $newPhotoPath = saveProfilePhoto($data['profile_photo'], $user['id']);
                    if ($newPhotoPath) {
                        $stmt = $conn->prepare("UPDATE users SET profile_photo = ? WHERE id = ?");
                        $stmt->execute([$newPhotoPath, $user['id']]);
                        $profilePhoto = $newPhotoPath;
                    }
                }

                jsonResponse([
                    'success' => true,
                    'user_id' => $user['id'],
                    'email' => $user['email'],
                    'userName_Data' => $user['name'],
                    'profile_photo' => $profilePhoto
                ]);
                break;








            case 'save_book':
                $required = ['user_id', 'title', 'category', 'videos'];
                foreach ($required as $field) {
                    if (!isset($data[$field])) jsonResponse(['error' => "$field required"], 400);
                }

                $userId = (int)$data['user_id'];
                $title = substr($data['title'], 0, 255);
                $category = preg_replace('/[^a-zA-Z0-9_]/', '', $data['category']);

                $authorName = $data['author_name'] ?? null;
              

                $bookCoverColor = $data['book_cover_color'] ?? "linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)";
                $bookTitleColor = $data['book_cover_title'] ?? "#e6c050"; // Default color

             

                $videos = is_array($data['videos']) ? $data['videos'] : [];
                $pageText = isset($data['page_text']) ? $data['page_text'] : [];

                try {
                    $conn->beginTransaction();

                    // Check/create category
                    $stmt = $conn->prepare("SELECT id FROM categories WHERE name = ?");
                    $stmt->execute([$category]);

                  

                    if (!$stmt->fetch()) {
                        $displayName = ucwords(str_replace('_', ' ', $category));
                        $stmt = $conn->prepare("INSERT INTO categories (name, display_name, default_title, default_author, bookCoverColor,titleColor) VALUES (?, ?, ?, ?,?,?)");
                        $stmt->execute([
                            $category,
                            $displayName,
                            $displayName . " Special",
                            "- By Sudha",
                            $bookCoverColor,
                            $bookTitleColor
                        ]);
                    }


                    // error_log("Processing videos: " . print_r($videos, true));

                    // Save videos to videos table
                    foreach ($videos as $videoUrl) {
                        $videoId = extractYouTubeId($videoUrl);

                        // echo $videoId;//FceicupMms//extraction is successfull.

                        if ($videoId) {
                            try {
                                // $stmt = $conn->prepare("INSERT INTO videos (category, title, url) VALUES (?, ?, ?)  ON DUPLICATE KEY UPDATE title = VALUES(title)");//this statement is creating problem.

                                $stmt = $conn->prepare("INSERT IGNORE INTO videos (category, title, url) VALUES (?, ?, ?)");

                                $stmt->execute([$category, $title, $videoId]);
                            } catch (PDOException $e) {
                                error_log("Failed to insert video: " . $e->getMessage());
                            }
                        } else {
                            error_log("Invalid YouTube URL: " . $videoUrl);
                        }
                    }




                    // Save book
                    $stmt = $conn->prepare("INSERT INTO books (user_id, title, category, videos, page_text, author_name,bookCoverColor,titleColor) VALUES (?, ?, ?, ?, ?, ?,?,?)");
                    $stmt->execute([
                        $userId,
                        $title,
                        $category,
                        json_encode($videos),
                        json_encode($pageText),
                        $authorName,
                        $bookCoverColor,
                        $bookTitleColor

                    ]);
                    $bookId = $conn->lastInsertId();

                    // Save book logo if provided
                    $logoPath = null;
                    if (isset($data['user_book_Logo']) && !empty($data['user_book_Logo'])) {
                        $logoPath = saveBookLogo($data['user_book_Logo'], $bookId);
                        if ($logoPath) {
                            $stmt = $conn->prepare("UPDATE books SET logo = ? WHERE id = ?");
                            $stmt->execute([$logoPath, $bookId]);
                        }
                    }



                    $conn->commit();
                    jsonResponse([
                        'success' => true,
                        'book_id' => $bookId,
                        'logo_path' => $logoPath,
                        'bookCoverColor' => $bookCoverColor,
                        'titleColor' => $bookTitleColor
                    ]);
                } catch (PDOException $e) {
                    $conn->rollBack();
                    jsonResponse(['error' => 'Failed to save book: ' . $e->getMessage()], 500);
                }
                break;

            default:
                jsonResponse(['error' => 'Invalid action'], 400);
        }
    }

    jsonResponse(['error' => 'Invalid request'], 400);
} catch (Exception $e) {
    jsonResponse([
        'error' => 'Server error',
        'message' => $e->getMessage()
    ], 500);
}
