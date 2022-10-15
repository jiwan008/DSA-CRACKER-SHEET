class Solution{
    private:
    pair<bool,int> isBalanceFast(Node *root){
        if(root == NULL){
            pair<bool,int> p;
            p.first = true;
            p.second = 0;
            return p;
        }
        
        pair<bool,int> left = isBalanceFast(root -> left);
        pair<bool,int> right = isBalanceFast(root -> right);
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second  - right.second) <= 1;
         pair<bool,int> ans;
         if(leftAns && rightAns && diff)
            ans.first = true;
        else
            ans.first = false;
            
        ans.second = max(left.second,right.second) + 1;
        
        return ans;
        
        
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalanceFast(root).first;
    }
};
