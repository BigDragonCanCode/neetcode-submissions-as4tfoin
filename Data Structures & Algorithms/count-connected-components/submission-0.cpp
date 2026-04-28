class Solution {
public:
    void helper(int curr, unordered_set<int>& visited, vector<vector<int>>& adj) {
        if (visited.count(curr)) return;
        visited.insert(curr);
        for (int& n: adj[curr]) {
            helper(n, visited, adj);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        //construct an adjacency list
        vector<vector<int>> adj(n);
        for (vector<int>& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> visited;
        int count = 0;
        for (int i=0; i<n; i++) {
            if (visited.count(i)) continue;
            helper(i, visited, adj);
            count++;
        }
        return count;
    }
};
