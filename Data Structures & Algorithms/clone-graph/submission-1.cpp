/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        unordered_map<int, Node*> visited;
        return helper(node, visited);
    }

    Node* helper(Node* node, unordered_map<int, Node*>& visited) {
        Node* copy = new Node();
        copy->val = node->val;
        visited[copy->val] = copy;
        for (Node* n : node->neighbors) {
            if (visited.find(n->val) == visited.end())
                copy->neighbors.push_back(helper(n, visited));
            else
                copy->neighbors.push_back(visited[n->val]);  // use existing Node, aviod cycle to cause infinite loop
        }
        return copy;
    }
};
