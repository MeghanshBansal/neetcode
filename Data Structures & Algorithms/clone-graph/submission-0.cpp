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
        if (node == nullptr) return nullptr;
        Node *root = new Node(node->val);
        unordered_map<Node*, Node*> visited_mapping;
        visited_mapping[node] = root;
        Node* curr = root;
        dfs(node, curr, visited_mapping);
        return root;
    }

    void dfs(Node* original, Node* copy, unordered_map<Node*, Node*> &mp)
    {
        for (Node* neighbour: original->neighbors)
        {
            if (mp.count(neighbour))
                copy->neighbors.push_back(mp[neighbour]);
            else
            {
                Node *temp = new Node(neighbour->val);
                mp[neighbour] = temp;
                copy->neighbors.push_back(temp);
                dfs(neighbour, temp, mp);
            }
        }
    }
};
