//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
/*
time complexity : o(n)
space complexity : o(n)
*/
class Solution{
    public:
    int height(struct Node* node){
        if(node == NULL)
        return 0;
        
        int leftHeight = height(node -> left);
        int rightHeight = height(node -> right);
        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }
};