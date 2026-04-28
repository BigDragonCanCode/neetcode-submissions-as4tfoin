class Solution {
public:
    //a valid tree is:
    //no cycle
    //fully connected (edge = n-1)
    bool helper(int curr, int parent, vector<vector<int>>& adj, unordered_set<int>& visited) {
        //if there's a cycle it's not a valid tree
        if (visited.count(curr)) return false;
        visited.insert(curr);

        // go through all the neighbors
        for (int& a: adj[curr]) {
            if (a == parent) continue; //we don't revisit parent, cause false cycle detection
            if (!helper(a, curr, adj, visited)) return false;
        }
        return true;
    }


    bool validTree(int n, vector<vector<int>>& edges) {
        //construct an adjacency list
        vector<vector<int>> adj(n);
        for (vector<int>& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> visited;
        if(!helper(0, -1, adj, visited)) return false;

        //we can use visited.size() to avoid store count in another var
        return visited.size() == n;
    }
};
