struct TrieNode {
    //unique pointer we don't need to manually release memory like TrieNode*
    unordered_map<char, unique_ptr<TrieNode>> children;
    bool isEnd = false;
};

class PrefixTree {
public:
    TrieNode root;

    PrefixTree() {
        root = TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = &root;
        int idx = 0;
        for (char &c: word) {
            if (curr->children.find(c) == curr->children.end()) 
                break;

            idx++;
            curr =  curr->children[c].get();
        }
        //case: word is a prefix of /the same as an existing word
        if (idx == word.size()) {
            curr->isEnd = true;
            return;
        }
        //case: we need to append the reamining word and share common prefix with another existing word
        // or just totally store a new word
        for (int i=idx; i<word.size(); i++) {
            char c = word[i];
            curr->children[c] = make_unique<TrieNode>();
            curr = curr->children[c].get();
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = &root;
        for (char &c: word) {
            if (curr->children.find(c) == curr->children.end()) 
                return false;
            curr = curr->children[c].get();
        }
        return curr->isEnd; //if isEnd is false meaning it's only a part of another word
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = &root;
        for (char &c: prefix) {
            if (curr->children.find(c) == curr->children.end()) 
                return false;
            curr = curr->children[c].get();
        }
        return true;
    }
};
