//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
/*
//bruteforce approach
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root){
        if(root == NULL)
            return 0;
        int left = height(root -> left);
        int right = height(root -> right);
        int ans = max(left, right) + 1;
        return ans;
    }
    int diameter(Node* root) {
        if(root == NULL)
            return 0;
        
        int op1 = diameter(root -> left);
        int op2 = diameter(root -> right);
        int op3 = height(root -> left) + height(root -> right) + 1;
        int ans = max(op3, max(op1, op2));
        return ans;
        
    }
};
*/

class Solution {
    private:
    pair<int,int> diameterHeight(Node* root){
        if(root == NULL){
            pair<int,int> p= make_pair(0,0);
            return p;
        }
        pair<int,int> left = diameterHeight(root -> left);
        pair<int,int> right = diameterHeight(root -> right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second, right.second) +1;
        return ans;
    }
  public:
    
    int diameter(Node* root) {
        return diameterHeight(root).first;
    }
};