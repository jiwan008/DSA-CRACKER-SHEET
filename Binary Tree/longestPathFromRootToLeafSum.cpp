pair<int,int> heightSum(Node *root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = heightSum(root -> left);
        pair<int,int> right = heightSum(root -> right);
        
        int leftHeight = left.first;
        int rightHeight = right.first;
        int leftSum = left.second;
        int rightSum = right.second;
        
        int sum = 0;
        if(rightHeight > leftHeight){
            sum += rightSum + root -> data;
        }
        else if(rightHeight < leftHeight){
            sum += leftSum + root -> data;
        }
        else{
            sum+= max(leftSum,rightSum) + root -> data;
        }
        
        int height = 1 + max(leftHeight,rightHeight);
        pair<int,int> ans;
        ans.first = height;
        ans.second = sum;
        return ans;
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        return heightSum(root).second;
    }
};