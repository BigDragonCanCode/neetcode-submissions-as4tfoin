class Solution {
public:
    //return true for cycle
    bool helper(char curr, 
    unordered_map<char, unordered_set<char>>& adj, 
    unordered_map<char, bool>& visited,
    string& result) {
        //visited is initially empty
        //so if we found the entry meaning it's processed
        //true means it's current path, false means it's in previous path
        if (visited.count(curr)) return visited[curr];

        //post-order
        visited[curr] = true;
        for (char n: adj[curr]) {
            if (helper(n, adj, visited, result))
                return true;
        }
        visited[curr] = false;
        result.push_back(curr);
        return false;
    }

    //w1 should be smaller than w2
    string foreignDictionary(vector<string>& words) {

        //construct an adjacency list
        //initialize with all char
        unordered_map<char, unordered_set<char>> adj;
        for (const string& word : words) {
            for (const char& c : word) {
                adj[c];
            }
        }

        for (int i=0; i<words.size()-1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());
            string_view w1p(w1.data(), minLen);
            string_view w2p(w2.data(), minLen);
            //invalid case
            if (w1.size() > w2.size() && w1p == w2p) return "";

            //find the first diff char
            for (int i=0; i<minLen; i++) {
                if (w1[i] != w2[i]) {
                    adj[w1[i]].insert(w2[i]);
                    break;
                }
            }
        }

        //run the helper
        string result;
        unordered_map<char, bool> visited;

        for (auto& a: adj) {
            //go through all the nodes
            //Topological sort only happens on DAG, which cannot have any cycles
            if (helper(a.first, adj, visited, result)) return "";
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
