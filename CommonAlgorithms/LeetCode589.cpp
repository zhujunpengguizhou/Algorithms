/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        Node* current = root;
        if(current == nullptr){
            return {};
        }
        vector<int>ans;
        ans.push_back(current->val);
        vector<Node*> tmp_children = current->children;
        int len = tmp_children.size();
        vector<vector<int>>ans_children(len);
        
        for(int i = 0 ; i < len; i++){
            if(tmp_children[i] != nullptr){
                ans_children[i] = preorder(tmp_children[i]);
            }
        }
        ;
        for(int i = 0 ; i < len; i++){
            ans.insert(ans.end(), ans_children[i].begin(), ans_children[i].end());
        }
        
        return ans;
    }
};