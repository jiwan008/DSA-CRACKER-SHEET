class Solution
{
    private:
    pair<bool, int> isSumTreeFast(Node* root){
        if(root == NULL){
           pair<bool,int> p = make_pair(true,0);
           return p;
        }
        if(root -> left == NULL && root -> right == NULL){
            pair<bool,int> p = make_pair(true,root -> data);
            return p;
        }
        
        pair<bool,int> left = isSumTreeFast(root -> left);
        pair<bool,int> right = isSumTreeFast(root -> right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool ans = (root -> data == left.second + right.second) && leftAns && rightAns;
        
        pair<bool,int> p;
        p.first = ans;
        p.second = left.second + right.second + root -> data;
        return p;
        
    }
    public:
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};