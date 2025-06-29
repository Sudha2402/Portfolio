-- Database: video_book_db
-- Database: GyanSangee


CREATE TABLE `users` (
  `id` int NOT NULL AUTO_INCREMENT,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  UNIQUE KEY `email` (`email`)
);

 Alter table users add column profile_photo blob after  password;
 ALTER TABLE users ADD COLUMN name VARCHAR(255) AFTER id


CREATE TABLE `categories` (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `display_name` varchar(255) NOT NULL,
  `default_title` varchar(255) NOT NULL,
  `default_author` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
);

ALTER TABLE categories ADD COLUMN logo VARCHAR(255) AFTER default_author;
ALTER TABLE categories ADD COLUMN bookCoverColor varchar(255) AFTER logo;
ALTER TABLE categories ADD COLUMN titleColor varchar(255) AFTER bookCoverColor;

update categories set logo="attachments/gyan_sangee.jpg" where id=1;
update categories set logo="attachments/news.png" where id=2;
update categories set logo="attachments/fitness.jpg" where id=3;
update categories set logo="attachments/dance.jpg" where id=4;
update categories set logo="attachments/songs.png" where id=5;
update categories set logo="attachments/funny.jpg" where id=6;
update categories set logo="attachments/comedy.jpg" where id=7;
update categories set logo="attachments/viral.jpg" where id=8;
update categories set logo="attachments/games.jpg" where id=9;
update categories set logo="attachments/devotional.jpg" where id=10;
update categories set logo="attachments/men.jpg" where id=64;
update categories set logo="attachments/shop.png" where id=65;
update categories set logo="attachments/skill.jpg" where id=66;
update categories set logo="attachments/women.jpg" where id=67;
update categories set logo="attachments/sudha.png" where id=68;




update categories set bookCoverColor="linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)" where id=1;

update categories set bookCoverColor="linear-gradient(135deg, #00416A 0%, #005792 100%)" where id=2;
update categories set bookCoverColor="linear-gradient(135deg, #1D976C 0%, #38EF7D 100%)" where id=3;
update categories set bookCoverColor="linear-gradient(135deg, #9C27B0 0%, #E040FB 100%)" where id=4;
update categories set bookCoverColor="linear-gradient(135deg, #FF512F 0%, #DD2476 100%)" where id=5;
update categories set bookCoverColor="linear-gradient(135deg, #FF9A00 0%, #FFD700 100%)" where id=6;
update categories set bookCoverColor=" linear-gradient(135deg, #FF6B6B 0%, #FFA3A3 100%)" where id=7;
update categories set bookCoverColor="linear-gradient(135deg, #6A11CB 0%, #2575FC 100%)" where id=8;
update categories set bookCoverColor="linear-gradient(135deg, #5C258D 0%, #4389A2 100%)" where id=9;
update categories set bookCoverColor="linear-gradient(135deg, #3a1c71 0%, #d76d77 50%, #ffaf7b 100%)" where id=10;
update categories set bookCoverColor="linear-gradient(135deg, #FF0000 0%, #990000 100%)" where id=11;
update categories set bookCoverColor="linear-gradient(135deg, #00C9FF 0%, #92FE9D 100%)" where id=12;




-- Educational (Mystical Library)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #0F2027 0%, #203A43 50%, #2C5364 100%)" WHERE id=1;

-- News (Celestial Herald)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #0F4C81 0%, #3282B8 50%, #BBE1FA 100%)" WHERE id=2;

-- Fitness (Elven Vitality)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #1A3A1A 0%, #4CAF50 50%, #A5D6A7 100%)" WHERE id=3;

-- Dance (Fae Revel)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #6A0D83 0%, #C71585 50%, #FF69B4 100%)" WHERE id=4;

-- Songs (Siren's Melody)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #1E1E3F 0%, #9D50BB 50%, #E74292 100%)" WHERE id=5;

-- Funny (Goblin Mischief)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #FF8C00 0%, #FFD700 50%, #FF6347 100%)" WHERE id=6;

-- Comedy (Pixie Jest)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #FF5252 0%, #FF9E80 50%, #FFEB3B 100%)" WHERE id=7;

-- Viral (Arcane Storm)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #4B0082 0%, #9400D3 50%, #00BFFF 100%)" WHERE id=8;

-- Games (Dragon's Hoard)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #3A1C71 0%, #D76D77 50%, #FFAF7B 100%)" WHERE id=9;

-- Devotional (Angelic Light)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #3E065F 0%, #700B97 50%, #8E05C2 100%)" WHERE id=10;

-- Live (Phoenix Fire)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #B22222 0%, #FF4500 50%, #FF8C00 100%)" WHERE id=11;

-- Kids (Unicorn Sparkle)
UPDATE categories SET bookCoverColor="linear-gradient(135deg, #00B4D8 0%, #90E0EF 50%, #CAF0F8 100%)" WHERE id=12;


-- For "Educational" (dark background):  
UPDATE categories SET titleColor="#FFD700" WHERE id=1;  
-- For "Kids" (light background):  
UPDATE categories SET titleColor="#FF00FF" WHERE id=12;  









update categories set titleColor="#e6c050" where id=1;
update categories set titleColor="#FFFFFF" where id=2;
update categories set titleColor="#000000" where id=3;
update categories set titleColor="#FFFFFF" where id=4;
update categories set titleColor="#FFFFFF" where id=5;
update categories set titleColor="#000000" where id=6;
update categories set titleColor="#000000" where id=7;
update categories set titleColor="#FFFFFF" where id=8;
update categories set titleColor="#FFFFFF" where id=9;
update categories set titleColor="#FFFFFF" where id=10;
update categories set titleColor="#FFFFFF" where id=11;




-- For "Educational" (dark background):  
-- UPDATE categories SET titleColor="#FFD700" WHERE id=1;  
-- For "Kids" (light background):  
UPDATE categories SET titleColor="#FF00FF" WHERE id=12;  






UPDATE categories SET 
    default_title = 'Kids World',
    default_author = '- By Children''s Storyteller',
    bookCoverColor = 'linear-gradient(135deg, #FF9E80 0%, #FF7043 50%, #FF5722 100%)',
    titleColor = '#FFFFFF'
WHERE id = 63;

UPDATE categories SET 
    default_title = 'Men''s Lifestyle',
    default_author = '- By Lifestyle Expert',
    bookCoverColor = 'linear-gradient(135deg, #1565C0 0%, #1976D2 50%, #42A5F5 100%)',
    titleColor = '#FFFFFF'
WHERE id = 64;

UPDATE categories SET 
    default_title = 'Shopping Guide',
    default_author = '- By Shopping Guru',
    bookCoverColor = 'linear-gradient(135deg, #7B1FA2 0%, #9C27B0 50%, #BA68C8 100%)',
    titleColor = '#FFFFFF'
WHERE id = 65;

UPDATE categories SET 
    default_title = 'Skill Builder',
    default_author = '- By Master Trainer',
    bookCoverColor = 'linear-gradient(135deg, #00838F 0%, #0097A7 50%, #00ACC1 100%)',
    titleColor = '#FFFFFF'
WHERE id = 66;

UPDATE categories SET 
    default_title = 'Women''s World',
    default_author = '- By Lifestyle Coach',
    bookCoverColor = 'linear-gradient(135deg, #C2185B 0%, #E91E63 50%, #F06292 100%)',
    titleColor = '#FFFFFF'
WHERE id = 67;

UPDATE categories SET 
    default_title = 'Sudha''s Collection',
    default_author = '- By Sudha and Friends',
    bookCoverColor = 'linear-gradient(135deg, #5C6BC0 0%, #3949AB 50%, #283593 100%)',
    titleColor = '#FFFFFF'
WHERE id = 68;





INSERT INTO categories (id, name, display_name, default_title, default_author, logo, bookCoverColor, titleColor) VALUES
(1, 'educational', 'Educational', 'Future Ready', '- By Sudha Kumari', 'attachments/educational.jpg', 'linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)', '#FFD700'),
(2, 'news', 'News', 'News Digest', '- By Greatest of great', 'attachments/news.png', 'linear-gradient(135deg, #0F4C81 0%, #3282B8 50%, #BBE1FA 100%)', '#FFFFFF'),
(3, 'fitness', 'Fitness', 'Fitness Guide', '- By Fitness Expert', 'attachments/fitness.jpg', 'linear-gradient(135deg, #1A3A1A 0%, #4CAF50 50%, #A5D6A7 100%)', '#000000'),
(4, 'dance', 'Dance', 'Dance Moves', '- By Dance Master', 'attachments/dance.jpg', 'linear-gradient(135deg, #6A0D83 0%, #C71585 50%, #FF69B4 100%)', '#FFFFFF'),
(5, 'songs', 'Songs', 'Music Collection', '- By Music Lover', 'attachments/songs.png', 'linear-gradient(135deg, #1E1E3F 0%, #9D50BB 50%, #E74292 100%)', '#FFFFFF'),
(6, 'funny', 'Funny', 'Laugh Factory', '- By Comedy Central', 'attachments/funny.jpg', 'linear-gradient(135deg, #FF8C00 0%, #FFD700 50%, #FF6347 100%)', '#000000'),
(7, 'comedy', 'Comedy', 'Comedy Specials', '- By Stand-up Artist', 'attachments/comedy.jpg', 'linear-gradient(135deg, #FF5252 0%, #FF9E80 50%, #FFEB3B 100%)', '#000000'),
(8, 'viral', 'Viral', 'Viral Videos', '- By Internet', 'attachments/viral.jpg', 'linear-gradient(135deg, #4B0082 0%, #9400D3 50%, #00BFFF 100%)', '#FFFFFF'),
(9, 'games', 'Games', 'Game Highlights', '- By Gamer', 'attachments/games.jpg', 'linear-gradient(135deg, #3A1C71 0%, #D76D77 50%, #FFAF7B 100%)', '#FFFFFF'),
(10, 'devotional', 'Devotional', 'Spiritual Journey', '- By Devotee', 'attachments/devotional.jpg', 'linear-gradient(135deg, #3E065F 0%, #700B97 50%, #8E05C2 100%)', '#FFFFFF'),
(11, 'live', 'Live Videos', 'Live Moments', '- By Live Streamer', 'attachments/live.jpg', 'linear-gradient(135deg, #B22222 0%, #FF4500 50%, #FF8C00 100%)', '#FFFFFF'),
(12, 'kids', 'Kids', 'Kids World', '- By Children''s Storyteller', 'attachments/kids.jpg', 'linear-gradient(135deg, #FF9E80 0%, #FF7043 50%, #FF5722 100%)', '#FFFFFF'),
(13, 'men', 'Men', 'Men''s Lifestyle', '- By Lifestyle Expert', 'attachments/men.jpg', 'linear-gradient(135deg, #1565C0 0%, #1976D2 50%, #42A5F5 100%)', '#FFFFFF'),
(14, 'shop', 'Shop', 'Shopping Guide', '- By Shopping Guru', 'attachments/shop.png', 'linear-gradient(135deg, #7B1FA2 0%, #9C27B0 50%, #BA68C8 100%)', '#FFFFFF'),
(15, 'skill', 'Skill', 'Skill Builder', '- By Master Trainer', 'attachments/skill.jpg', 'linear-gradient(135deg, #00838F 0%, #0097A7 50%, #00ACC1 100%)', '#FFFFFF'),
(16, 'women', 'Women', 'Women''s World', '- By Lifestyle Coach', 'attachments/women.jpg', 'linear-gradient(135deg, #C2185B 0%, #E91E63 50%, #F06292 100%)', '#FFFFFF'),
(17, 'sudha', 'Sudha', 'Sudha''s Collection', '- By Sudha and Friends', 'attachments/sudha.png', 'linear-gradient(135deg, #5C6BC0 0%, #3949AB 50%, #283593 100%)', '#FFFFFF');














CREATE TABLE `videos` (
  `id` int NOT NULL AUTO_INCREMENT,
  `category` varchar(255) NOT NULL,
  `title` varchar(255) NOT NULL,
  `url` varchar(255) NOT NULL,
  `duration` int NOT NULL COMMENT 'in seconds',
  PRIMARY KEY (`id`),
  KEY `category` (`category`)
);
-- INSERT IGNORE INTO videos (category, title, url) VALUES (?, ?, ?)




CREATE TABLE `books` (
  `id` int NOT NULL AUTO_INCREMENT,
  `user_id` int NOT NULL,
  `title` varchar(255) NOT NULL,
  `category` varchar(255) NOT NULL,
  `videos` text NOT NULL COMMENT 'JSON array of video URLs',
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `user_id` (`user_id`)
);
ALTER TABLE books ADD COLUMN author_name VARCHAR(255) AFTER category;
ALTER TABLE books ADD COLUMN logo VARCHAR(255) AFTER author_name;
ALTER TABLE books ADD COLUMN page_text TEXT AFTER videos;
ALTER TABLE books ADD COLUMN bookCoverColor varchar(255) AFTER logo;
ALTER TABLE books ADD COLUMN titleColor varchar(255) AFTER bookCoverColor;










-- Insert default categories
INSERT INTO `categories` (`name`, `display_name`, `default_title`, `default_author`) VALUES ('educational', 'Educational', 'Gyan Sangee', '- By Sudha Kumari'),
('news', 'News', 'News Digest', '- By Greatest of great'),
('fitness', 'Fitness', 'Fitness Guide', '- By Fitness Expert'),
('dance', 'Dance', 'Dance Moves', '- By Dance Master'),
('songs', 'Songs', 'Music Collection', '- By Music Lover'),
('funny', 'Funny', 'Laugh Factory', '- By Comedy Central'),
('comedy', 'Comedy', 'Comedy Specials', '- By Stand-up Artist'),
('viral', 'Viral', 'Viral Videos', '- By Internet'),
('games', 'Games', 'Game Highlights', '- By Gamer'),
('devotional', 'Devotional', 'Spiritual Journey', '- By Devotee'),
('live', 'Live Videos', 'Live Moments', '- By Live Streamer'),
('kids', 'kid Videos', 'kids video', '- By kid ...');





mysql> select * from categories;
+----+-------------+--------------+-------------------+------------------------+-----------------------------+----------------------------------------------------------------+------------+
| id | name        | display_name | default_title     | default_author         | logo                        | bookCoverColor                                                 | titleColor |
+----+-------------+--------------+-------------------+------------------------+-----------------------------+----------------------------------------------------------------+------------+
|  1 | educational | Educational  | Future Ready      | - By Sudha Kumari      | attachments/educational.jpg | linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)              | #FFD700    |
|  2 | news        | News         | News Digest       | - By Greatest of great | attachments/news.png        | linear-gradient(135deg, #0F4C81 0%, #3282B8 50%, #BBE1FA 100%) | #FFFFFF    |
|  3 | fitness     | Fitness      | Fitness Guide     | - By Fitness Expert    | attachments/fitness.jpg     | linear-gradient(135deg, #1A3A1A 0%, #4CAF50 50%, #A5D6A7 100%) | #000000    |
|  4 | dance       | Dance        | Dance Moves       | - By Dance Master      | attachments/dance.jpg       | linear-gradient(135deg, #6A0D83 0%, #C71585 50%, #FF69B4 100%) | #FFFFFF    |
|  5 | songs       | Songs        | Music Collection  | - By Music Lover       | attachments/songs.png       | linear-gradient(135deg, #1E1E3F 0%, #9D50BB 50%, #E74292 100%) | #FFFFFF    |
|  6 | funny       | Funny        | Laugh Factory     | - By Comedy Central    | attachments/funny.jpg       | linear-gradient(135deg, #FF8C00 0%, #FFD700 50%, #FF6347 100%) | #000000    |
|  7 | comedy      | Comedy       | Comedy Specials   | - By Stand-up Artist   | attachments/comedy.jpg      | linear-gradient(135deg, #FF5252 0%, #FF9E80 50%, #FFEB3B 100%) | #000000    |
|  8 | viral       | Viral        | Viral Videos      | - By Internet          | attachments/viral.jpg       | linear-gradient(135deg, #4B0082 0%, #9400D3 50%, #00BFFF 100%) | #FFFFFF    |
|  9 | games       | Games        | Game Highlights   | - By Gamer             | attachments/games.jpg       | linear-gradient(135deg, #3A1C71 0%, #D76D77 50%, #FFAF7B 100%) | #FFFFFF    |
| 10 | devotional  | Devotional   | Spiritual Journey | - By Devotee           | attachments/devotional.jpg  | linear-gradient(135deg, #3E065F 0%, #700B97 50%, #8E05C2 100%) | #FFFFFF    |
| 11 | live        | Live Videos  | Live Moments      | - By Live Streamer     | attachments/live.jpg        | linear-gradient(135deg, #B22222 0%, #FF4500 50%, #FF8C00 100%) | #FFFFFF    |
| 12 | kids        | Kids         | Kids Special      | - By Sudha             | attachments/kids.jpg        | linear-gradient(135deg, #00B4D8 0%, #90E0EF 50%, #CAF0F8 100%) | #FF00FF    |
+----+-------------+--------------+-------------------+------------------------+-----------------------------+----------------------------------------------------------------+------------+
12 rows in set (0.00 sec)



INSERT INTO categories (name, display_name, default_title, default_author, logo, bookCoverColor, titleColor) VALUES
('educational', 'Educational', 'Future Ready', '- By Sudha Kumari', 'attachments/educational.jpg', 'linear-gradient(135deg, #0a0a2a 0%, #1a1a5a 100%)', '#FFD700'),
('news', 'News', 'News Digest', '- By Greatest of great', 'attachments/news.png', 'linear-gradient(135deg, #0F4C81 0%, #3282B8 50%, #BBE1FA 100%)', '#FFFFFF'),
('fitness', 'Fitness', 'Fitness Guide', '- By Fitness Expert', 'attachments/fitness.jpg', 'linear-gradient(135deg, #1A3A1A 0%, #4CAF50 50%, #A5D6A7 100%)', '#000000'),
('dance', 'Dance', 'Dance Moves', '- By Dance Master', 'attachments/dance.jpg', 'linear-gradient(135deg, #6A0D83 0%, #C71585 50%, #FF69B4 100%)', '#FFFFFF'),
('songs', 'Songs', 'Music Collection', '- By Music Lover', 'attachments/songs.png', 'linear-gradient(135deg, #1E1E3F 0%, #9D50BB 50%, #E74292 100%)', '#FFFFFF'),
('funny', 'Funny', 'Laugh Factory', '- By Comedy Central', 'attachments/funny.jpg', 'linear-gradient(135deg, #FF8C00 0%, #FFD700 50%, #FF6347 100%)', '#000000'),
('comedy', 'Comedy', 'Comedy Specials', '- By Stand-up Artist', 'attachments/comedy.jpg', 'linear-gradient(135deg, #FF5252 0%, #FF9E80 50%, #FFEB3B 100%)', '#000000'),
('viral', 'Viral', 'Viral Videos', '- By Internet', 'attachments/viral.jpg', 'linear-gradient(135deg, #4B0082 0%, #9400D3 50%, #00BFFF 100%)', '#FFFFFF'),
('games', 'Games', 'Game Highlights', '- By Gamer', 'attachments/games.jpg', 'linear-gradient(135deg, #3A1C71 0%, #D76D77 50%, #FFAF7B 100%)', '#FFFFFF'),
('devotional', 'Devotional', 'Spiritual Journey', '- By Devotee', 'attachments/devotional.jpg', 'linear-gradient(135deg, #3E065F 0%, #700B97 50%, #8E05C2 100%)', '#FFFFFF'),
('live', 'Live Videos', 'Live Moments', '- By Live Streamer', 'attachments/live.jpg', 'linear-gradient(135deg, #B22222 0%, #FF4500 50%, #FF8C00 100%)', '#FFFFFF'),
('kids', 'Kids', 'Kids Special', '- By Sudha', 'attachments/kids.jpg', 'linear-gradient(135deg, #00B4D8 0%, #90E0EF 50%, #CAF0F8 100%)', '#FF00FF');





CREATE TABLE bookmark (
    bookmarkID INT AUTO_INCREMENT PRIMARY KEY,
    userID INT NOT NULL,
    bookID INT DEFAULT 0,
    CategoryName VARCHAR(255) DEFAULT NULL,
    bookmarkPage INT NOT NULL,
    UNIQUE KEY unique_bookmark (userID, bookID, CategoryName)
);






INSERT INTO videos (category, url) VALUES 
("comedy","https://youtube.com/shorts/vuFR0KE8taY?feature=shared"),
("comedy","https://youtube.com/shorts/UrvB4gwldwk?feature=shared"),
("comedy","https://youtube.com/shorts/aOhS1EYNUwc?feature=shared"),
("comedy","https://youtube.com/shorts/NA_QL3KTSbY?feature=shared"),
("comedy","https://www.youtube.com/watch?v=bnWXOK1RT1o&list=PLRMn9rNUNDYiV50UxKqiUv2oIxCRHDDwq&index=5"),
("comedy","https://youtube.com/shorts/MTxD8Xu20gQ?feature=shared"),
("comedy","https://youtu.be/ZNZdX24GFTo?si=9a4y4KZj_rJ4D2M9"),
("comedy","https://youtube.com/shorts/TjgstEOOiVs?feature=shared"),
("comedy","https://youtube.com/shorts/P9z7RCopH1c?feature=shared"),
("comedy","https://www.youtube.com/watch?v=2HI3nxFk2eg&list=PLRMn9rNUNDYiV50UxKqiUv2oIxCRHDDwq"),
("comedy","https://www.youtube.com/watch?v=iqt29njco3M&list=PLRMn9rNUNDYiV50UxKqiUv2oIxCRHDDwq&index=2"),
("comedy","https://www.youtube.com/watch?v=4bj4AB_Cj3A&list=PLRMn9rNUNDYiV50UxKqiUv2oIxCRHDDwq&index=3"),
("comedy","https://www.youtube.com/watch?v=1TFOSQLsYHQ&list=PLRMn9rNUNDYiV50UxKqiUv2oIxCRHDDwq&index=6"),
("comedy","https://www.youtube.com/watch?v=pyX68CbhKu0&list=PLRMn9rNUNDYiV50UxKqiUv2oIxCRHDDwq&index=7"),
("comedy","https://www.youtube.com/watch?v=Ax2trB3XJSI"),












INSERT INTO videos (category,title, url) VALUES 
("dance","dance Collection","V1QRnfYL3Xg"),
("dance","dance Collection","GUSCX-b9oCI"),
("dance","dance Collection","qns-uNCQRDY"),
("dance","dance Collection","EH0avw5jnOk"),
("dance","dance Collection","28cjdWMdf4s"),
("dance","dance Collection"," Cb2UeDmZQMk"),
("dance","dance Collection","dIGMYpzf7kQ");







INSERT INTO videos (category, url) VALUES ("devotional","https://youtu.be/iw_yxT2lthU?si=034U_L-F-XJ1D6wG"),
("devotional","https://youtu.be/q3Mp1c5ZLEU?feature=shared"),
("devotional","https://www.youtube.com/watch?v=kd_p2bERQwk&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=11"),
("devotional","https://youtu.be/m1_xBTe2aIw?si=-lq-Q5hq3nxFvCLD"),
("devotional","https://youtu.be/oTZJszwWjQo?si=tpKEm_XeVpARrnbU"),
("devotional","https://youtu.be/Bvn0MdJHeSc?si=7pRImZTlGyGzTb8K"),
("devotional","https://youtu.be/mjYPoIkySkA?si=jaiECUnTB2-uOvFR"),
("devotional","https://youtu.be/HrXEOXtCIks?si=XtkyNhO6DQmmONgv"),
("devotional","https://youtu.be/4DHRnrQQi-I?si=f4i6lQ9RP0JI-nlV"),
("devotional","https://youtu.be/CZ8oGg7AIms?si=WbNnsbnTDyZqjOq0"),
("devotional","https://youtube.com/shorts/Ch0RKo-7bU4?si=IrMX8fKERmPdToSI"),





INSERT INTO videos (category, url) VALUES ("educational","https://youtu.be/4vxZMQ5yCRw?feature=shared"),
https://youtube.com/shorts/5toLxPmN3-4?feature=shared 
("educational","https://www.youtube.com/watch?v=luBZbLbc6OI&
list=PLRMn9rNUNDYizrutLFNGA9bpgkBVxPC7w"),
https://youtube.com/shorts/s2BIVFea6Wo?feature=shared 
("educational","https://youtu.be/UimDsh9ec4Q?si=RWjPWk5gYhqroZjH"),
("educational","https://www.youtube.com/watch?v=WgZIxElMIE0&list=PLRMn9rNUNDYizrutLFNGA9bpgkBVxPC7w&index=10"),
("educational","https://youtube.com/shorts/jDoKiEnRs9M?si=z_9wJb4Alz-03tHs"),
("educational","https://youtu.be/6l6YR2oE_rU?si=cgCUyZfS0nwP-zZU"),
("educational","https://youtube.com/shorts/2Zi83rMnmqE?si=N0lfe4Gm38F-W4fZ"),
("educational","https://youtube.com/shorts/Vit5_-YuN7s?si=8kT8OEp-uq7yNaly"),
("educational","https://youtu.be/xoLz55CWRBY?feature=shared"),
("educational","https://youtu.be/zVfyrKaM5xw?si=u_d4h77MsQY6tzaW"),
("educational","https://youtu.be/fRdF8yFt84g?feature=shared"),
("educational","https://youtu.be/N54bHAD30as?si=T16UWxl9EEDiMQNm"),
("educational","https://youtu.be/4vxZMQ5yCRw?feature=shared"),
("educational","https://youtu.be/63qF2vK0GbQ?feature=shared"),
("educational","https://youtube.com/shorts/OM--VJasDHU?si=hnWMuqV8DY6EcQKE"),
("educational","https://youtu.be/AHrLRq1Gzr4?si=AW2zYI74TMBUSypW"),
("educational","https://youtu.be/QaULcbe8idU?si=2a83P21rKfBnWplc"),
("educational","https://youtu.be/ZdjI9xFbHwk?si=VfPrsAEOrlS03gsp"),
("educational","https://youtu.be/2Ewtpx_2YpY?si=fiHOs0tRbtsgPo6A"),
("educational","https://www.youtube.com/watch?v=qfeIrElqZIU&list=PLRMn9rNUNDYizrutLFNGA9bpgkBVxPC7w&index=4"),
("educational","https://youtube.com/shorts/BqGwNq5ASyI?si=8QG3SFnk5BmJKuKf"),
("educational","https://youtube.com/shorts/kVXRj1h12Ik?si=ddx8Xo59gj6e2-3o"),
("educational","https://youtube.com/shorts/XC4vypGBKb4?si=KcYhDiP_vBcnxQbl"),

("educational","https://youtube.com/shorts/I3UCKmKCI0Q?si=7XxbjCxSD2eTOy_y"),
("educational","https://youtu.be/5PP_j5-T4gs?si=BKaHy5_AUU2nZD27"),
("educational","https://youtube.com/shorts/2ol328ICUOM?si=bG-qgR_7xVWzEwbD"),
("educational","https://youtu.be/b88NUI_6NWA?si=EmVCTFU8b7DBCeE-"),
("educational","https://youtube.com/shorts/3mdcqYAHPYA?si=OjQXmLT3iAROpLbk"),
("educational","https://youtube.com/shorts/FzxRLE8Ci-o?si=xPvR32PyNvjVvIpx"),
("educational","https://youtube.com/shorts/TdcfCOmt354?si=wqbjaoaj_Q4IsIsf"),
("educational","https://www.youtube.com/watch?v=cCj4o6csFqg&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=7"),
("educational","https://www.youtube.com/watch?v=QHCXTR7mDbY&list=PLRMn9rNUNDYizrutLFNGA9bpgkBVxPC7w&index=2"),
("educational","https://youtube.com/shorts/Ak8CXTbconw?si=0kMNrgrHI3WXBX55"),
("educational","https://www.youtube.com/watch?v=7EKIVfxkNI8&list=PLRMn9rNUNDYizrutLFNGA9bpgkBVxPC7w&index=5"),
("educational","https://www.youtube.com/watch?v=6wRiSb3bne8&list=PLRMn9rNUNDYizrutLFNGA9bpgkBVxPC7w&index=8"),
("educational","https://youtube.com/shorts/XC4vypGBKb4?si=KcYhDiP_vBcnxQbl"),
("educational","https://youtube.com/shorts/_QIw0-7-jA8?si=rYXe2-5N1z4BMdxW"),
("educational","https://youtube.com/shorts/pcYTHShyJVY?si=zPFgVgCZjiqumwt6"),
("educational","https://youtube.com/shorts/d9v3p_EeNkQ?si=ydElI7Qd_GZc498c"),
("educational","https://youtube.com/shorts/UFncJw3waZg?si=56hAWsGujn1xV5bK"),
("educational","https://youtube.com/shorts/W13bAax8AMU?si=FlgDUJ3Vr_SoHtRd"),
https://youtube.com/shorts/yucr1H8hEsE?feature=shared 





INSERT INTO videos (category, url) VALUES 
("Fitness","https://www.youtube.com/watch?v=JpOPRVOO3cM&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=5"),
("Fitness","https://www.youtube.com/watch?v=IT94xC35u6k"),
("Fitness","https://www.youtube.com/watch?v=-hSma-BRzoo"),





INSERT INTO videos (category, url) VALUES ("funny","https://youtube.com/shorts/Mw9ASj66Gz0?feature=shared"),
https://youtube.com/shorts/QeggHJo9uGs?feature=shared 
("funny","https://youtube.com/shorts/fUMqrVF3a6Q?feature=shared"),
https://youtube.com/shorts/2yUT1GjLz7M?feature=shared 
("funny","https://youtu.be/jLS41mEn_-0?feature=shared"),
("funny","https://youtube.com/shorts/1p1_Q3wA_tw?feature=shared"),
("funny","https://youtu.be/SjR41eEnkbY?si=JEiyuBzLkhn8Ovuy"),
https://youtube.com/shorts/mVaMCt0pnB8?feature=shared 
https://youtube.com/shorts/ZqBAWTpzD24?feature=shared 
https://youtube.com/shorts/pdokRpvEqQY?feature=shared 
https://youtube.com/shorts/j7nV1iDAl1E?feature=shared 
https://youtube.com/shorts/h7CRhrmI6D4?feature=shared 
https://youtube.com/shorts/J5-tfnLcn_M?feature=shared 


INSERT INTO videos (category, url) VALUES ("games","https://www.youtube.com/watch?v=Y_4aIWb6ViI&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=21"),
("games","https://www.youtube.com/watch?v=musCkKPz1no&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4"),
("games","https://www.youtube.com/watch?v=qfuvLRl9nVU&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=12"),
("games","https://www.youtube.com/watch?v=58nIIYJAGNY&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=2"),
("games","https://www.youtube.com/watch?v=b8U2DfUyuRo&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=3"),
("games","https://www.youtube.com/watch?v=BvrZCxKIzHY&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=4"),
("games","https://www.youtube.com/watch?v=JpOPRVOO3cM&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=5"),
("games","https://www.youtube.com/watch?v=lN4BmHi1j7o&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=6"),
("games","https://www.youtube.com/watch?v=WwJRpnA60fg&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=7"),
("games","https://www.youtube.com/watch?v=3gDClzKGK2g&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=8"),
("games","https://www.youtube.com/watch?v=o4cuvIEHni8&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=9"),
("games","https://www.youtube.com/watch?v=OJmZACZXJ_Q&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=10"),
("games","https://www.youtube.com/watch?v=2x67Tgl-5Xs&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=11"),
("games","https://www.youtube.com/watch?v=b9f-QdVAsaY&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=13"),
("games","https://www.youtube.com/watch?v=E0Cfm_wM5Y8&list=PLRMn9rNUNDYi9g6VTtU9WNQpmSYlvcJc4&index=14"),

















INSERT INTO videos (category, url) VALUES
https://youtu.be/r1MOsyaNkZk?si=PK_1n63Cm8em5kmW 
https://youtu.be/tUjOL_Nk6uo?si=_-E7vXMo1maP7Lo4
https://youtu.be/6HqZLdwdBIY?si=1_td8malXqQRSujC
https://youtu.be/aFad3hWO1LY?si=vpsKLmrXCIsx-_Lo
https://youtu.be/VG3arGjg0Hk?si=00SIlzOQZAflcR3z
https://youtu.be/GqsaSD_0MKc?si=Pc4ZiTHbQmcIHaHm
https://youtu.be/pblltg0r1Ug?si=Nq6DXa4G4NLLjfm1
https://youtu.be/3QzT1sq6kCY?si=Lz1Iq09AB4bPH3mD
("kids","https://youtube.com/shorts/Hs43bG4FAC4?feature=shared"),
("kids","CcAO9IwVB88"),
("kids","https://youtube.com/shorts/I_-sAxhqpa8?feature=shared "),
https://youtu.be/-q5cgUnGino?si=GsEyhA2n35pv9DbA
("kids","https://youtube.com/shorts/4FZNsVk41UY?feature=shared"),
https://youtu.be/dfueGxYy-_E?si=1Eh-iLtWnh-dqJrX
("kids","https://youtube.com/shorts/VRTDvqA6UmM?feature=shared"),
https://youtu.be/Bx0o0dd_z2E?si=-qnQEKuXx-6Xgh8S
("kids","https://youtube.com/shorts/x3CtTFRr64E?feature=shared"),
("kids","https://youtube.com/shorts/O2tb16U-v_0?feature=shared"),
https://youtu.be/QCz7nWn1qkM?si=9Qc2Qm4IbphlyX15
("kids","https://youtu.be/hkAi4sJUh_E?feature=shared"),
("kids","https://youtube.com/shorts/XLnM8SpadGU?si=YTDcLo4DqyhdDqZs"),
https://youtube.com/shorts/Mdiiima0U5g?feature=shared 



INSERT INTO videos (category, url) VALUES ("live","https://youtu.be/j317AoA0_8I?si=8wJIUYvZjTqOm5qQ"),
("shop","https://youtu.be/43SkRj7sz4w?feature=shared"),


INSERT INTO videos (category, url) VALUES ("men","https://www.youtube.com/watch?v=WuTriLNYEqk&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=14"),
("men","https://www.youtube.com/watch?v=mN_1rXiVqB4&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=11"),
 ("men","https://youtu.be/8Ehq0O58AkY?feature=shared"),
 ("men","https://www.youtube.com/watch?v=iBAorDJDrJY&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=15"),
 ("men","https://www.youtube.com/watch?v=bHcXVeR3rWU&list=PLRMn9rNUNDYgn1Q0NmrAhQb-d-b_--NVZ&index=2"),




INSERT INTO videos (category, url) VALUES ("news","https://youtu.be/OqYXuLQJdZY?si=lZ9iFu15hWSlSvR-"),
("news","https://www.youtube.com/watch?v=uTHk3Au7xZE&list=PLRMn9rNUNDYizrutLFNGA9bpgkBVxPC7w&index=6"),
("news","https://www.youtube.com/watch?v=IZgQNYefBro&list=PLRMn9rNUNDYizrutLFNGA9bpgkBVxPC7w&index=7"),



INSERT INTO videos (category, url) VALUES ("shop","https://www.youtube.com/watch?v=oWvyOMVv888&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=13"),
 ("shop","https://youtu.be/43SkRj7sz4w?feature=shared"),
("shop","https://www.youtube.com/watch?v=xLFzSZODfWg&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT"),
("shop","https://www.youtube.com/watch?v=E9mIsQ7F9RM&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=2"),
("shop","https://youtube.com/shorts/jjIyttgIgNc?si=tW5ohN1FwER6vr9_"),
("shop","https://youtube.com/shorts/Bs6WxQxSW-I?si=qw7uY4iy_clRToVt"),
("shop","https://youtube.com/shorts/OGxeA93WrzE?si=H8xB0jW8R_ZGm-jf"),
("shop","https://youtube.com/shorts/F3ee0iYL3ME?si=YEUe4sIQUM6L2KUy"),
("shop","https://youtu.be/GqeMCUAk5m4?si=Z3KK8RVlOd2lmJBQ"),
("shop","https://youtu.be/Lra5J9b84aE?feature=shared"),
("shop","https://youtube.com/shorts/btoAz1-1P-A?si=cZTwqJGWxzcAHU2Q"),
("shop","https://youtu.be/mQn9ur-DdnE?si=Q-ysz_cEvZYQSzVQ"),
("shop","https://youtu.be/dFX810z_HDE?si=CUhaUpvERVCTJ2JS"),
("shop","https://www.youtube.com/watch?v=USUZxVsLutI&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK"),
("shop","https://www.youtube.com/watch?v=fLdQCGuPPho&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=3"),








INSERT INTO videos (category, url) VALUES ("skills","https://youtu.be/UN8q-Sy9mzQ?feature=shared"),
("skills","https://youtu.be/iGpGeuKr-Hg?si=qjHzySeZlkGccHkq"),
("skills","https://www.youtube.com/watch?v=7Zy0Ut7l59k&list=PLRMn9rNUNDYgn1Q0NmrAhQb-d-b_--NVZ&index=5"),
("skills","https://www.youtube.com/watch?v=Qt3QSWrUJT4&list=PLRMn9rNUNDYizrutLFNGA9bpgkBVxPC7w&index=3"),
("skills","https://www.youtube.com/watch?v=mxpiExkGYd8&list=PLRMn9rNUNDYgn1Q0NmrAhQb-d-b_--NVZ"),
("skills","https://www.youtube.com/watch?v=bHcXVeR3rWU&list=PLRMn9rNUNDYgn1Q0NmrAhQb-d-b_--NVZ&index=2"),
("skills","https://www.youtube.com/watch?v=PRMAhDNOSEo&list=PLRMn9rNUNDYgn1Q0NmrAhQb-d-b_--NVZ&index=3"),
("skills","https://www.youtube.com/watch?v=F2974FKgetw&list=PLRMn9rNUNDYgn1Q0NmrAhQb-d-b_--NVZ&index=4"),
("skills","https://www.youtube.com/watch?v=4o5jmaoztgs&list=PLRMn9rNUNDYgn1Q0NmrAhQb-d-b_--NVZ&index=6"),




INSERT INTO videos (category, url) VALUES ("songs","https://youtu.be/-oJGctkpi-k?si=63rnbdhjcuFEqugL"),
("songs","https://www.youtube.com/watch?v=g_N0XjS1lbo&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=13"),
("songs","https://youtu.be/JyDdDESUX04?si=umhp6rrvKvwA9FHI"),
("songs","https://youtube.com/shorts/cQI3NOSiJHo?si=aOoeKH6wRzQATp3E"),
("songs","https://www.youtube.com/watch?v=HEW_4K6TlfQ&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=2"),
("songs","https://www.youtube.com/watch?v=L1U_44h0y3Y&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=3"),
("songs","https://www.youtube.com/watch?v=Rb__siF42ss&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=4"),
("songs","https://www.youtube.com/watch?v=3Rar1BLm9y8&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=5"),
("songs","https://www.youtube.com/watch?v=HxSLH8vDuDA&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=9"),
("songs","https://www.youtube.com/watch?v=3y8JlrO2Tz0&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=6"),
("songs","https://www.youtube.com/watch?v=pD0N8iAZ8DA&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=7"),
("songs","https://www.youtube.com/watch?v=2HdSxSHjoKY&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=8"),
("songs","https://www.youtube.com/watch?v=JSYQWGZSRWs&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=10"),
("songs","https://www.youtube.com/watch?v=RpkJ9sMJmpI&list=PLRMn9rNUNDYhEuBNmSB52Re6e1_WtXvzT&index=12"),
("songs","https://youtube.com/shorts/wDt3WkUzU3k?si=lmxik-kRz1O8S8y1"),
("songs","https://youtube.com/shorts/UF3IZGOSD3Y?si=DTEjN-yAiy8SEy41"),








INSERT INTO videos (category, url) VALUES ("viral","https://youtube.com/shorts/zqi4tKAu-MM?feature=shared"),
 ("viral","https://www.youtube.com/watch?v=MZOHp1Zj8wk&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=12"),
 ("viral","https://www.youtube.com/watch?v=ri79mqPulqk&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=22"),
 ("viral","https://www.youtube.com/watch?v=jBwFo-V0CX4&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=20"),
("viral","https://www.youtube.com/watch?v=c6nNEQ5B0tA&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=3"),
("viral","https://youtu.be/S_aRpzGwVMA?si=CfmfM4CqYiW045P9"),
("viral","https://www.youtube.com/watch?v=m26H3i7MwA8&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_"),
("viral","https://www.youtube.com/watch?v=FYMbiFLU9FQ&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=2"),
("viral","https://www.youtube.com/watch?v=iZjZNQ6sNnY&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=4"),
("viral","https://www.youtube.com/watch?v=TVCU0pfRMcs&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=5"),
("viral","https://www.youtube.com/watch?v=b3i8UZHWJG0&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=6"),
("viral","https://www.youtube.com/watch?v=Fs2wz1VxYiY&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=17"),
("viral","https://www.youtube.com/watch?v=45gMd36cuJQ&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=8"),
("viral","https://www.youtube.com/watch?v=L_BhjEI7Sy8&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=19"),
("viral","https://www.youtube.com/watch?v=D4eknCvXFwA&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=9"),
("viral","https://www.youtube.com/watch?v=b_KsCyE_Pgo&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=13"),
("viral","https://www.youtube.com/watch?v=6P8zz_MJ91c&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=11"),
("viral","https://www.youtube.com/watch?v=V61Iv9sBjMI&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=18"),
("viral","https://youtube.com/shorts/bPjoQvbR6Yw?si=eyPWmo7CbaniXxqI"),




INSERT INTO videos (category, url) VALUES ("women","https://youtu.be/X-MwBDN4Cg8?feature=shared"),
 ("women","https://youtu.be/CURZAV_sh9c?si=zqvg1VlcN4-NiBbO"),
 https://youtube.com/shorts/bPvhM5-Sb0U?feature=shared 
("women","https://youtu.be/rDamwEXwyRg?feature=shared"),
("women","https://youtu.be/wvNBENttlxY?si=Dm1ZvuyfA4h1vCqW"),
("women","https://youtu.be/8aWxaTXv6v0?si=kDTeSCCFjioxslUc"),
https://youtube.com/shorts/ZCcm5sGMbTI?feature=shared 
("women","https://youtube.com/shorts/HYFOa1xVeJk?si=is6f3QUme8TiFHez"),
("women","https://youtube.com/shorts/rnuXiVmkyNs?si=rOZcKAcbNurr1isB"),
("women","https://youtu.be/l2BxFiMpMZI?si=F3S47ckknVpBWSq2"),
("women","https://youtu.be/Gx3_x6RH1J4?feature=shared"),
("women","https://youtu.be/ddGeTD4XHcE?si=_SgHjxqaW7hLNnNa"),
("women","https://youtu.be/oERpLiqGB08?feature=shared"),
("women","https://youtube.com/shorts/xGqgBseRnts?si=r79hnzDWVJLMR8sl"),
("women","https://youtube.com/shorts/e2eji92YLV8?si=iay76hFayU5LSDcV"),
("women","https://youtube.com/shorts/QZGiutwjGrQ?si=WCCC39CCybtZLfZj"),
("women","https://youtube.com/shorts/_MGaAI0Hbo4?si=Es_jPw0pnbCtQiUA"),
("women","https://youtu.be/Hw0zRW4_yvY?si=8KObZW_YWLbexdna"),
("women","https://youtu.be/mhuNOvk89k0?si=UNMrzM3PeITYcY87"),
("women","https://youtu.be/b9wVr4HofdY?si=wLzgP6mv9kfGyoJ9"),
("women","https://youtu.be/4WbCCfdd570?si=EkaLF9GA_SSwEiUO"),
("women","https://youtube.com/shorts/6VojLClqQbE?si=fE8exjUDQXp4lX6o"),
("women","https://youtube.com/shorts/9vCwrw5NBl4?si=8vzXcCtZ4ixivtGt"),
("women","https://youtu.be/1xQmPH67Ung?si=Hhl8M6Jhq3VNSuYc"),
("women","https://youtu.be/3vcq-n6DMZs?si=cUv4ynH7i2aQRRLs"),
("women","https://youtu.be/sAb2It4DwRE?si=uptcbzAvAyRoXdeb"),
("women","https://youtu.be/6CZFTfI6xnw?si=0fhUGuNJGiQ9jXEl"),
("women","https://youtu.be/-6ljEfcraKo?si=78ThLH4RCNUr32tb"),
("women","https://youtube.com/shorts/wJtpQi0ScZc?feature=shared "),
("women","https://youtu.be/5ARLJgoFfo0?si=nrsYjmyKKUm0IOg6"),
("women","https://youtu.be/SE6liX3rZBs?si=FBIkaRY7IZGDsrqX"),
("women","https://youtu.be/_3jJgH5LP2c?si=Hv5CU5RksGfuLvjQ"),
("women","https://youtu.be/WQi-6OmSY38?si=xwMSGBgA0OW0ykfC"),
("women","https://youtu.be/JwiQOeF_pD4?si=a14N7M9-0EsOf7L0"),
("women","https://www.youtube.com/watch?v=iv5yPvTBPAQ&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=8"),
("women","https://youtu.be/nlGTvuJngAQ?si=tv_kM8UQILHeY06z"),
("women","https://www.youtube.com/watch?v=IJKFq9JieWs&list=PLRMn9rNUNDYgKeL8atJg1OyrOign8W1t_&index=10"),
("women","https://www.youtube.com/watch?v=nD1tTpCBakQ&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=10"),
("women","https://www.youtube.com/watch?v=F4K-X4kfpOo&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=7"),
("women","https://www.youtube.com/watch?v=c1qy-KR7uXQ&list=PLRMn9rNUNDYizrutLFNGA9bpgkBVxPC7w&index=11"),
("women","https://www.youtube.com/watch?v=DzJHjNXXilw&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=4"),
("women","https://www.youtube.com/watch?v=u0QO54tFdwI&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=5"),
("women","https://www.youtube.com/watch?v=I_-sAxhqpa8&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=9"),
("women","https://www.youtube.com/watch?v=RqBiw79XLjo&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=6"),
("women","https://www.youtube.com/watch?v=eRvZJZkr6S8&list=PLRMn9rNUNDYiObnfMebkGdUtEPr4cioCK&index=12"),
("women","https://youtube.com/shorts/6VojLClqQbE?si=fE8exjUDQXp4lX6o"),
("women","https://youtube.com/shorts/IUYABH4H-0Y?si=En_oLxGSgzo4As1G"),
("women","https://youtube.com/shorts/9vCwrw5NBl4?si=8vzXcCtZ4ixivtGt"),




-- Story Trial:


-- https://www.youtube.com/watch?v=esbUJEKaD7w

-- Story

Tia: Family tofu, wake up it's time to go to school 
Tofu: but Tia the school bus arrives at 8 a.m. 
Tia: tofu doesn't you remember you have to go to a school picnic today the school bus will arrive a little early today 
Tofu: for that school picnic. Oh yes, I forgot about it but can I sleep for 5 minutes  please ...
Tia: you will miss the bus tofu come on get up.
Tia: okay tofu please hurry out you're wasting your time, you will not be able to make it to the school picnic otherwise.
Tofu: I still have half an hour to catch the bus 
Tia: tofu time management is very important to achieve things in life
Tofu: now what does that mean Tia 
Tia: I'll tell you a quick story as you get ready
Tofu: okay 
Tia: Time is precious.

Story:
Once upon a time a boy named Oliver went for a hiking trip with a group of other people Oliver wasted a lot of time and hence, he missed a lot of things always. 
Coach: Boys let's go or we'll miss the beautiful sunset at the top of the mountain 
Boys: Yes sir, let's go 
Oliver: Coach, I need some time to get ready 
Couch: You should have been ready by now Oliver come back fast we're waiting for you 
Oliver: uh yes sir
Coach: Oliver, please hurry up. you're wasting your time and everybody else's time too. We can't wait for you anymore.
Oliver: I'm here, let's go.

Everybody is climbing the mountain while Oliver is lagging behind as he's wasting his time

Couch: Where is Oliver. I can't see him Student: Coach he's resting there 
Couch: Oliver, hurry up.

Oliver gets up and walks towards the group slowly. Everybody starts moving too as they assured, Oliver is behind them as everybody is climbing the mountain. Oliver loses track of the group again because he was wasting his time. He starts panicking as he was lost. He somehow finds his way and reaches the top of the mountain but when he reaches the sun had already set and everybody was walking down the mountain. Everybody else looked so happy as they had watched such a beautiful sunset but Oliver starts crying as he missed it.
Story ends...

Time is precious, it waits for no one.

Tia: Once you start managing your time correctly you will achieve a lot of beautiful things in life.

Tofu: that was a great story. Tia, I will manage my time and make it to the picnic Tia: Yes tofu, now come fast or you will miss your school bus.






-- https://www.youtube.com/watch?v=Y5EL8g2u11M
The Fisherman and His Wife | Bedtime Stories for Kids in English | Fairy Tales

A kind-hearted fisherman who loves his wife one day catches an unusual golden fish. It is said that fish grant wishes, but his wife's selfishness escalates. He was a fisherman who gave his wife everything she wanted and wished for her happiness, but is that true happiness? Can the fisherman and his wife regain their happy lives?




-- https://www.youtube.com/watch?v=p3dzClZN0Tg

Mangita and Larina 💚 | Bedtime Stories for Kids in English | Fairy Tales

Two sisters, Mangita and Larina lives in a small cottage. Mangita is a very hardworking and kind hearted girl. On the other hand Larina is a selfish girl. One day, Larina sees an old woman by the river. The old woman asks her for help, but instead of helping Larina harms the old woman. When Mangita finds the old woman, she helps her immediately!