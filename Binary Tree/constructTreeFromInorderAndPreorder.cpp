class Solution{
    public:
    void createMapping(int in[],int n,map<int,int> &nodeToIndex){
        for(int i = 0; i < n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n,map<int,int> &nodeToIndex){
        if(index >= n || inorderStart > inorderEnd){ 
            return NULL;
        }
        int element = pre[index++];
        Node* root = new Node(element);
        int pos = nodeToIndex[element];
        //recursive call
        root -> left = solve(in, pre, index, inorderStart,pos - 1 ,n,nodeToIndex);
        root -> right = solve(in, pre, index, pos + 1, inorderEnd,n,nodeToIndex);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        map<int,int> nodeToIndex;
        createMapping(in,n,nodeToIndex);
        int index = 0;
        Node* ans = solve(in, pre, index,0,n-1,n,nodeToIndex);
        return ans;
    }
};