struct TrieNode {
    unordered_map<char, unique_ptr<TrieNode>> children;
    bool isEnd = false; 
};

class WordDictionary {
public:
    TrieNode root = TrieNode();

    WordDictionary() {}
    
    void addWord(string word) {
        TrieNode* curr = &root;
        int ind = 0;
        for (char &c: word) {
            if (curr->children.find(c) == curr->children.end())
                break;
            ind++;
            curr = curr->children[c].get();
        }
        if (ind == word.size()) return;
        for (int i=ind; i<word.size(); i++) {
            char c = word[i];
            curr->children[c] = make_unique<TrieNode>();
            curr = curr->children[c].get();
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return helper(word, 0, &root);
    }
private:
    bool helper(string& word, int ind, TrieNode* curr) {
        for (int i=ind; i<word.size();i++) {
            char c = word[i];
            if (c == '.') {
                //dispatch search for the remaining of word through all children nodes
                for (auto& n: curr->children) {
                    if (helper(word, i+1, n.second.get()))
                        return true;
                }
                return false;
            }
            if (curr->children.find(c) == curr->children.end())
                return false;
            curr = curr->children[c].get();
            ind++;
        }
        return curr->isEnd;
    }
};
