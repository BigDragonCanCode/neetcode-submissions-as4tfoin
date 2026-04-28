class Solution {
public:
    //a valid tree is:
    //no cycle
    //fully connected (edge = n-1)
    bool helper(int curr, int parent, int& count, vector<vector<int>>& adj, unordered_set<int>& visited) {
        //if there's a cycle it's not a valid tree
        if (visited.count(curr)) return false;
        visited.insert(curr);
        // go through all the neighbors
        for (int& a: adj[curr]) {
            if (a == parent) continue;
            count++;
            if (!helper(a, curr, count, adj, visited)) return false;
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

        int count = 0;
        unordered_set<int> visited;
        if(!helper(0, -1, count, adj, visited)) return false;
        cout<<count<<" "<<n<<endl;
        return count == n-1;
    }
};
