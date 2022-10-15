//https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
Node* solve(Node* root, int &k, int node){
      if(root == NULL)
         return NULL;
         
      if (root->data == node)
         return root;
         
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;

        }
        return leftAns;
    }
    
    else if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
            
        }
        return rightAns;
    }
    return NULL;
}