int findPosition(int in[], int element, int n){
        for(int i = 0; i < n; i++){
            if(in[i] == element)
            return i;
        }
        return -1;
}
    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n){
        if(index < 0 || inorderStart > inorderEnd){ 
            return NULL;
        }
        int element = pre[index--];
        Node* root = new Node(element);
        int pos = findPosition(in, element, n);
        //recursive call
        root -> right = solve(in, pre, index, pos + 1, inorderEnd, n);
        root -> left = solve(in, pre, index, inorderStart,pos - 1 ,n);
        
        return root;
}