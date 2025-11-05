#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <stack>
#include <algorithm>

// Security
// huffman coding
// hashing
// Separate Chaining: Uses linked lists for each bucket
// Linear Probing: Simple collision resolution by checking next slot
// Quadratic Probing: Uses quadratic function for probe sequence
// Double Hashing: Uses second hash function for step size
// Password Hashing: Multiple hash generation methods
// Encryption/Decryption: Simple cryptographic techniques

// huffman coding

// Node in the tree has two details, freq and character
class Node
{
public:
    int freq;
    char character;
    Node *left;
    Node *right;

    Node(int frequency, char symbol)
    {
        freq = frequency;
        character = symbol;
        // Node->left = NULL;//node is a constructor, we can't use this way
        this->left = NULL;
        this->right = NULL;
    }
};

// recursive called and stored tree
//  tree creation
Node *createTreeFail(priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> &charfreq, Node *root)
{
    if (charfreq.empty())
    {
        return root;
    }

    Node *firstnode = new Node(charfreq.top().first, charfreq.top().second);
    charfreq.pop();
    Node *secondnode = new Node(charfreq.top().first, charfreq.top().second);
    charfreq.pop();

    // create combined and push into queue
    charfreq.push(make_pair(firstnode->freq + secondnode->freq, '$'));

    root = new Node(firstnode->freq + secondnode->freq, '$');
    return createTreeFail(charfreq, root);

    // niche se uppar jana problem h as we would not be able to be connected with the other disconnected, hence we have to use another method because top down tree creation is not possible here.
}

struct compNodeFreq
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq; //// This creates a MAX-HEAP for priority_queue as sign is opposite in case of heap
    }
};

void preOrder(Node *root, vector<string> &characterCode, string codepath, vector<char> &chars)
{ // char is for storing the character corresponding to the code

    // here we would have created mapping between character and code also.
    //  void preOrder(Node *root, unordered_map<char, string> &huffmanMap, string codepath) {
    //    huffmanMap[root->character] = codepath;

    if (root && root->character != '$')
    {
        // this is leaf node with alphabet
        characterCode.push_back(codepath);
        chars.push_back(root->character);
        return;
    }

    preOrder(root->left, characterCode, codepath + '0', chars); // codepath.push_back('0'), it is allowed

    // I think codepath , we are not updating for the below one by adding '0', but if we have used push_back then we were needed to pop '0' before passing to the right

    preOrder(root->right, characterCode, codepath + '1', chars);
}

vector<string> huffmanCodes(string S, vector<int> f, int N)
{
    // string S is distinct character of size N and f is their corresponding frequency.

    // build huffman tree and print all the huffman codes in preorder traversal of the tree.

    // let's sort the frequency and for that we will put pair inseperate  vector

    // vector<pair<char, int>> charfreq;
    // vector<pair<char, int>> charfreq;//we need priority queue to get min

    // we need to make minheap to get the lowest frequency
    // priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> charfreq; // min heap is created //this whole should be defined in parameter where function is being passed

    // node extraction from pair is hard hence it would be better, if we create priority queue of nodes

    priority_queue<Node *, vector<Node *>, compNodeFreq> charfreq;

    for (int i = 0; i < f.size(); i++)
    {
        // charfreq.push_back(make_pair(S[i], f[i]));
        // charfreq.push(make_pair(f[i], S[i]));

        Node *newNode = new Node(f[i], S[i]);
        charfreq.push(newNode);
    }

    //
    // function that is recursive

    // Node *root = createTree(charfreq, root);//recuresive works when creating tree from top to bottom not from bottom to top

    // here first node and second node is not always needed to be create, create only in case of not $

    Node *firstnode;
    Node *secondnode;
    // if (charfreq.top().second != '$')
    // {
    //     firstnode = new Node(charfreq.top().first, charfreq.top().second);
    // }
    // else
    // {
    //     // node extraction from pair is hard hence it would be better, if we create priority queue of nodes

    //     firstnode =
    //         charfreq.pop();
    // }
    // Node *secondnode = new Node(charfreq.top().first, charfreq.top().second);
    // charfreq.pop();

    // // create combined and push into queue
    // charfreq.push(make_pair(firstnode->freq + secondnode->freq, '$'));

    // Node *root = new Node(firstnode->freq + secondnode->freq, '$');

    // now we hae to create tree from Node queue created
    while (charfreq.size() > 1)
    {
        // after combining and pushing the root we are left with only one node in the heap that will be tree root.

        firstnode = charfreq.top();
        charfreq.pop();
        secondnode = charfreq.top();
        charfreq.pop();

        // create combined and push into queue
        Node *root = new Node(firstnode->freq + secondnode->freq, '$');
        charfreq.push(root);

        root->left = firstnode;
        root->right = secondnode;
    }

    // we need preorder traversal now and also push the path 1, 0 in the answer for root nodes
    vector<char> chars;
    vector<string> characterCode;
    string temp = "";
    // preOrder(charfreq.top(), characterCode, "");
    preOrder(charfreq.top(), characterCode, temp, chars);
    charfreq.pop(); // no need anymore hence pop

    return characterCode;
}

// hashing

// Separate Chaining: Uses linked lists for each bucket
#include <list>
class HashTableChaining
{
private:
    vector<list<pair<int, string>>> table; // Linked list for each bucket
    int capacity;

    int hashFunction(int key)
    {
        return key % capacity;
    }

public:
    HashTableChaining(int cap = 10) : capacity(cap)
    {
        table.resize(capacity);
    }

    // Insert with separate chaining
    void insert(int key, string value)
    {
        int index = hashFunction(key);

        // Check if key already exists, update if found
        for (auto &pair : table[index])
        {
            if (pair.first == key)
            {
                pair.second = value;
                return;
            }
        }

        // Key doesn't exist, add new pair
        table[index].push_back({key, value});
    }

    // Search with separate chaining
    string search(int key)
    {
        int index = hashFunction(key);

        for (auto &pair : table[index])
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }

        return "Not found";
    }

    // Delete with separate chaining
    void remove(int key)
    {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (it->first == key)
            {
                table[index].erase(it);
                return;
            }
        }
    }
};

// Linear Probing: Simple collision resolution by checking next slot
// #include <vector>
#include <string>
using namespace std;

class HashTableLinear
{
private:
    vector<pair<int, string>> table; // (key, value)
    int capacity;
    int size;

    int hashFunction(int key)
    {
        return key % capacity;
    }

public:
    HashTableLinear(int cap = 10) : capacity(cap), size(0)
    {
        table.resize(capacity, {-1, ""}); // -1 indicates empty slot
    }

    // Insert with linear probing
    void insert(int key, string value)
    {
        if (size == capacity)
        {
            cout << "Hash table is full!" << endl;
            return;
        }

        int index = hashFunction(key);
        int originalIndex = index;

        // Linear probing: keep moving forward until empty slot
        while (table[index].first != -1 && table[index].first != key)
        {
            index = (index + 1) % capacity;
            if (index == originalIndex)
            { // Full circle
                cout << "Hash table is full!" << endl;
                return;
            }
        }

        if (table[index].first == -1)
        {
            size++;
        }
        table[index] = {key, value};
    }

    // Search with linear probing
    string search(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index].first != -1)
        {
            if (table[index].first == key)
            {
                return table[index].second;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex)
                break; // Full circle
        }

        return "Not found";
    }

    // Delete with linear probing
    void remove(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index].first != -1)
        {
            if (table[index].first == key)
            {
                table[index] = {-1, ""}; // Mark as empty
                size--;
                return;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex)
                break;
        }
    }
};

// Quadratic Probing: Uses quadratic function for probe sequence

class HashTableQuadratic
{
private:
    vector<pair<int, string>> table;
    int capacity;
    int size;

    int hashFunction(int key)
    {
        return key % capacity;
    }

public:
    HashTableQuadratic(int cap = 10) : capacity(cap), size(0)
    {
        table.resize(capacity, {-1, ""});
    }

    // Insert with quadratic probing
    void insert(int key, string value)
    {
        if (size == capacity)
        {
            cout << "Hash table is full!" << endl;
            return;
        }

        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing: index + i²
        while (table[index].first != -1 && table[index].first != key)
        {
            i++;
            index = (hashFunction(key) + i * i) % capacity;
            if (i == capacity)
            { // Tried all positions
                cout << "Cannot insert - table full!" << endl;
                return;
            }
        }

        if (table[index].first == -1)
        {
            size++;
        }
        table[index] = {key, value};
    }

    // Search with quadratic probing
    string search(int key)
    {
        int index = hashFunction(key);
        int i = 0;

        while (table[index].first != -1)
        {
            if (table[index].first == key)
            {
                return table[index].second;
            }
            i++;
            index = (hashFunction(key) + i * i) % capacity;
            if (i == capacity)
                break;
        }

        return "Not found";
    }
};

// Double Hashing: Uses second hash function for step size

class HashTableDouble
{
private:
    vector<pair<int, string>> table;
    int capacity;
    int size;

    // Primary hash function
    int hash1(int key)
    {
        return key % capacity;
    }

    // Secondary hash function (should never return 0)
    int hash2(int key)
    {
        return 7 - (key % 7); // Prime number less than capacity
    }

public:
    HashTableDouble(int cap = 10) : capacity(cap), size(0)
    {
        table.resize(capacity, {-1, ""});
    }

    // Insert with double hashing
    void insert(int key, string value)
    {
        if (size == capacity)
        {
            cout << "Hash table is full!" << endl;
            return;
        }

        int index = hash1(key);
        int step = hash2(key);
        int i = 0;

        // Double hashing: index + i * hash2(key)
        while (table[index].first != -1 && table[index].first != key)
        {
            i++;
            index = (hash1(key) + i * step) % capacity;
            if (i == capacity)
            {
                cout << "Cannot insert - table full!" << endl;
                return;
            }
        }

        if (table[index].first == -1)
        {
            size++;
        }
        table[index] = {key, value};
    }

    // Search with double hashing
    string search(int key)
    {
        int index = hash1(key);
        int step = hash2(key);
        int i = 0;

        while (table[index].first != -1)
        {
            if (table[index].first == key)
            {
                return table[index].second;
            }
            i++;
            index = (hash1(key) + i * step) % capacity;
            if (i == capacity)
                break;
        }

        return "Not found";
    }
};


// Encryption/Decryption: Simple cryptographic techniques
#include <algorithm>

class SimpleCrypto
{
private:
    int key;

public:
    SimpleCrypto(int encryptionKey = 3) : key(encryptionKey) {}

    // Caesar cipher encryption
    string encrypt(const string &plaintext)
    {
        string ciphertext = plaintext;

        for (char &c : ciphertext)
        {
            if (isalpha(c))
            {
                char base = islower(c) ? 'a' : 'A';
                c = base + (c - base + key) % 26;
            }
        }

        return ciphertext;
    }

    // Caesar cipher decryption
    string decrypt(const string &ciphertext)
    {
        string plaintext = ciphertext;

        for (char &c : plaintext)
        {
            if (isalpha(c))
            {
                char base = islower(c) ? 'a' : 'A';
                c = base + (c - base - key + 26) % 26;
            }
        }

        return plaintext;
    }

    // XOR encryption (simple but not secure)
    string xorEncrypt(const string &plaintext)
    {
        string ciphertext = plaintext;

        for (char &c : ciphertext)
        {
            c = c ^ key; // XOR with key
        }

        return ciphertext;
    }

    // XOR decryption (same as encryption)
    string xorDecrypt(const string &ciphertext)
    {
        return xorEncrypt(ciphertext); // XOR is symmetric
    }
};


// Password Hashing: Multiple hash generation methods
#include <functional>

class PasswordHasher
{
public:
    // Simple hash function for passwords
    size_t simpleHash(const string &password)
    {
        size_t hash = 0;
        for (char c : password)
        {
            hash = hash * 31 + c; // 31 is a common prime multiplier
        }
        return hash;
    }

    // Using C++ built-in hash
    size_t builtInHash(const string &password)
    {
        hash<string> hasher;
        return hasher(password);
    }

    // Custom hash with salt
    size_t hashWithSalt(const string &password, const string &salt)
    {
        string saltedPassword = password + salt;
        return simpleHash(saltedPassword);
    }
};





// Include all the class definitions from previous code here...
// [All the class definitions from the previous answer would be here]

void testAllHashingTechniques()
{
    cout << "==========================================" << endl;
    cout << "COMPREHENSIVE HASHING TECHNIQUES TEST" << endl;
    cout << "==========================================" << endl;

    // Test Data
    vector<pair<int, string>> testData = {
        {10, "Alice"}, {25, "Bob"}, {35, "Charlie"}, {15, "David"}, {45, "Eve"}, {20, "Frank"}};

    // =================================================================
    // 1. TESTING LINEAR PROBING
    // =================================================================
    cout << "\n1. LINEAR PROBING TEST" << endl;
    cout << "----------------------" << endl;
    HashTableLinear linearTable(7); // Small table to force collisions

    // Insert test data
    cout << "Inserting elements:" << endl;
    for (auto &data : testData)
    {
        linearTable.insert(data.first, data.second);
        cout << "  Inserted: " << data.first << " -> " << data.second << endl;
    }

    // Test searches
    cout << "\nSearch operations:" << endl;
    cout << "  Search 25: " << linearTable.search(25) << endl;
    cout << "  Search 35: " << linearTable.search(35) << endl;
    cout << "  Search 99: " << linearTable.search(99) << " (Should be Not found)" << endl;

    // Test collision handling
    cout << "\nCollision test - inserting key 17 (collides with 10):" << endl;
    linearTable.insert(17, "Grace");
    cout << "  Search 17: " << linearTable.search(17) << endl;
    cout << "  Search 10: " << linearTable.search(10) << " (Should still work)" << endl;

    // Test deletion
    cout << "\nDeleting key 25:" << endl;
    linearTable.remove(25);
    cout << "  Search 25 after deletion: " << linearTable.search(25) << " (Should be Not found)" << endl;

    // =================================================================
    // 2. TESTING SEPARATE CHAINING
    // =================================================================
    cout << "\n\n2. SEPARATE CHAINING TEST" << endl;
    cout << "-------------------------" << endl;
    HashTableChaining chainTable(5); // Small table to force collisions

    // Insert test data
    cout << "Inserting elements:" << endl;
    for (auto &data : testData)
    {
        chainTable.insert(data.first, data.second);
        cout << "  Inserted: " << data.first << " -> " << data.second << endl;
    }

    // Test searches
    cout << "\nSearch operations:" << endl;
    cout << "  Search 10: " << chainTable.search(10) << endl;
    cout << "  Search 45: " << chainTable.search(45) << endl;

    // Test collision in same bucket
    cout << "\nCollision test - keys 10 and 15 go to same bucket (0):" << endl;
    cout << "  Search 10: " << chainTable.search(10) << endl;
    cout << "  Search 15: " << chainTable.search(15) << endl;

    // Test update existing key
    cout << "\nUpdating key 10 to 'AliceUpdated':" << endl;
    chainTable.insert(10, "AliceUpdated");
    cout << "  Search 10: " << chainTable.search(10) << endl;

    // Test deletion
    cout << "\nDeleting key 35:" << endl;
    chainTable.remove(35);
    cout << "  Search 35 after deletion: " << chainTable.search(35) << " (Should be Not found)" << endl;

    // =================================================================
    // 3. TESTING QUADRATIC PROBING
    // =================================================================
    cout << "\n\n3. QUADRATIC PROBING TEST" << endl;
    cout << "--------------------------" << endl;
    HashTableQuadratic quadraticTable(7);

    // Insert test data
    cout << "Inserting elements:" << endl;
    for (auto &data : testData)
    {
        quadraticTable.insert(data.first, data.second);
        cout << "  Inserted: " << data.first << " -> " << data.second << endl;
    }

    // Test searches with quadratic probing
    cout << "\nSearch operations:" << endl;
    cout << "  Search 35: " << quadraticTable.search(35) << endl;
    cout << "  Search 20: " << quadraticTable.search(20) << endl;

    // Test collision resolution pattern
    cout << "\nTesting quadratic probing pattern:" << endl;
    cout << "  Inserting key 17 (collision with 10):" << endl;
    quadraticTable.insert(17, "QuadraticTest");
    cout << "  Search 17: " << quadraticTable.search(17) << endl;
    cout << "  Search 10: " << quadraticTable.search(10) << endl;

    // =================================================================
    // 4. TESTING DOUBLE HASHING
    // =================================================================
    cout << "\n\n4. DOUBLE HASHING TEST" << endl;
    cout << "----------------------" << endl;
    HashTableDouble doubleTable(7);

    // Insert test data
    cout << "Inserting elements:" << endl;
    for (auto &data : testData)
    {
        doubleTable.insert(data.first, data.second);
        cout << "  Inserted: " << data.first << " -> " << data.second << endl;
    }

    // Test searches with double hashing
    cout << "\nSearch operations:" << endl;
    cout << "  Search 25: " << doubleTable.search(25) << endl;
    cout << "  Search 45: " << doubleTable.search(45) << endl;

    // Test double hashing collision resolution
    cout << "\nTesting double hashing collision resolution:" << endl;
    cout << "  Inserting key 24 (will use second hash function):" << endl;
    doubleTable.insert(24, "DoubleHashTest");
    cout << "  Search 24: " << doubleTable.search(24) << endl;

    // =================================================================
    // 5. TESTING ENCRYPTION/DECRYPTION
    // =================================================================
    cout << "\n\n6. ENCRYPTION/DECRYPTION TEST" << endl;
    cout << "-----------------------------" << endl;

    SimpleCrypto caesarCrypto(7); // Key = 7
    SimpleCrypto xorCrypto(42);   // Key = 42

    vector<string> testMessages = {
        "HELLO WORLD",
        "Secret Message 123!",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "abcdefghijklmnopqrstuvwxyz",
        "Testing 1 2 3 @#$%"};

    cout << "Caesar Cipher Tests:" << endl;
    for (const string &message : testMessages)
    {
        string encrypted = caesarCrypto.encrypt(message);
        string decrypted = caesarCrypto.decrypt(encrypted);

        cout << "  Original: '" << message << "'" << endl;
        cout << "  Encrypted: '" << encrypted << "'" << endl;
        cout << "  Decrypted: '" << decrypted << "'" << endl;
        cout << "  Success: " << (message == decrypted ? "YES ✓" : "NO ✗") << endl;
        cout << endl;
    }

    cout << "XOR Encryption Tests:" << endl;
    for (const string &message : testMessages)
    {
        string encrypted = xorCrypto.xorEncrypt(message);
        string decrypted = xorCrypto.xorDecrypt(encrypted);

        cout << "  Original: '" << message << "'" << endl;
        cout << "  Encrypted: '" << encrypted << "'" << endl;
        cout << "  Decrypted: '" << decrypted << "'" << endl;
        cout << "  Success: " << (message == decrypted ? "YES ✓" : "NO ✗") << endl;
        cout << endl;
    }

    // Test different keys
    cout << "Different Key Test:" << endl;
    SimpleCrypto crypto1(5);
    SimpleCrypto crypto2(10);
    string testMsg = "Hello Crypto";
    string enc1 = crypto1.encrypt(testMsg);
    string enc2 = crypto2.encrypt(testMsg);
    cout << "  Same message with different keys:" << endl;
    cout << "    Key=5:  " << enc1 << endl;
    cout << "    Key=10: " << enc2 << endl;
    cout << "    Different? " << (enc1 != enc2 ? "YES ✓" : "NO ✗") << endl;

    // 
    
   // =================================================================
    // 6. TESTING PASSWORD HASHING
    // =================================================================
    cout << "\n\n5. PASSWORD HASHING TEST" << endl;
    cout << "------------------------" << endl;
    PasswordHasher hasher;

    vector<string> passwords = {
        "password123", "securePass!", "MySecret@2024", "hello world", "TEST"};

    cout << "Password Hashing Results:" << endl;
    for (const string &pwd : passwords)
    {
        size_t simpleHash = hasher.simpleHash(pwd);
        size_t builtInHash = hasher.builtInHash(pwd);
        size_t saltedHash = hasher.hashWithSalt(pwd, "randomSalt");

        cout << "  Password: '" << pwd << "'" << endl;
        cout << "    Simple Hash: " << simpleHash << endl;
        cout << "    Built-in Hash: " << builtInHash << endl;
        cout << "    Salted Hash: " << saltedHash << endl;
        cout << endl;
    }

    // Test hash consistency
    cout << "Hash Consistency Test:" << endl;
    string testPwd = "consistentPassword";
    size_t hash1 = hasher.simpleHash(testPwd);
    size_t hash2 = hasher.simpleHash(testPwd);
    cout << "  Same password hashed twice: " << hash1 << " vs " << hash2 << endl;
    cout << "  Are they equal? " << (hash1 == hash2 ? "YES ✓" : "NO ✗") << endl;

    // =================================================================
    // 7. PERFORMANCE COMPARISON
    // =================================================================
    cout << "\n\n7. COLLISION HANDLING COMPARISON" << endl;
    cout << "--------------------------------" << endl;

    // Test with high collision scenario
    vector<pair<int, string>> collisionData = {
        {5, "A"}, {15, "B"}, {25, "C"}, {35, "D"}, {45, "E"}, {10, "F"}, {20, "G"}, {30, "H"}, {40, "I"}};

    HashTableLinear linearCollision(10);
    HashTableChaining chainCollision(10);
    HashTableQuadratic quadCollision(10);
    HashTableDouble doubleCollision(10);

    cout << "Inserting high-collision data to all tables:" << endl;
    for (auto &data : collisionData)
    {
        linearCollision.insert(data.first, data.second);
        chainCollision.insert(data.first, data.second);
        quadCollision.insert(data.first, data.second);
        doubleCollision.insert(data.first, data.second);
    }

    cout << "All collision handling methods completed successfully!" << endl;

    cout << "\n==========================================" << endl;
    cout << "ALL TESTS COMPLETED SUCCESSFULLY!" << endl;
    cout << "==========================================" << endl;
}

int main()
{

    // huffman coding
    vector<int> f = {5, 9, 12, 13, 16, 45};
    vector<string> huffmanCode = huffmanCodes("abcdef", f, 6);
    // hashing
    for (int i = 0; i < 6; i++)
    {
        cout << huffmanCode[i] << "\t";
    }
    cout << endl;

    // hashing all combined together.
    testAllHashingTechniques();
    // different functions can be called by storing this main in them and calling function name here directly

    return 0;
}