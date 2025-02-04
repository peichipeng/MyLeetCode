class TrieNode {
private:
    TrieNode* links[26];
    bool isEnd;

public:
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        isEnd = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        isEnd = true;
    }

    bool isEndOfWord() {
        return isEnd;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            char currentChar = word[i];
            if (!node->containsKey(currentChar)) {
                node->put(currentChar, new TrieNode());
            }
            node = node->get(currentChar);
        }
        node->setEnd();
    }
    
    TrieNode* searchPrefix(const string& word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++){
            char currLetter = word[i];
            if (node->containsKey(currLetter)) {
                node = node->get(currLetter);
            } else {
                return nullptr;
            }
        }
        return node;
    }
    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->isEndOfWord();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = searchPrefix(prefix);
        return node != nullptr;
    }

    ~Trie() {
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */