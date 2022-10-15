//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
class Solution {
    void leftTraversal(Node* root, vector<int> &v){
        if(root == NULL)
            return;
        if(root -> left == NULL && root-> right == NULL)
            return;
        v.push_back(root -> data);
        
        if(root -> left)
            leftTraversal(root -> left, v);
        else
            leftTraversal(root -> right, v);
    }
    
    void leafTraversal(Node* root, vector<int> &v){
        if(root == NULL)
            return;
        if(root -> left == NULL && root -> right == NULL){
            v.push_back(root -> data);
            return;
        }
        leafTraversal(root -> left,v);
        leafTraversal(root -> right,v);
    }
    
    void rightTraversal(Node* root, vector<int> &v){
        if(root == NULL)
            return;
        if(root -> left == NULL && root-> right == NULL)
            return;
            
        if(root -> right)
            rightTraversal(root -> right,v);
        else
            rightTraversal(root -> left,v);
            
        v.push_back(root->data);
        
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> v;
        v.push_back(root -> data);
        leftTraversal(root -> left, v);
        
        leafTraversal(root -> left,v);
        leafTraversal(root -> right,v);
        
        rightTraversal(root -> right,v);
        
        return v;
    }
};

