//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        map<int,int> mpp;
        
        queue<pair<Node*, int>> q; //root and horizantal distance
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            
            int hd = temp.second;
            
            //if one value is present for a horizontal then do nothing
            
            if(mpp.find(hd) == mpp.end())
                mpp[hd] = frontNode -> data;
            
            if(frontNode -> left)
                q.push(make_pair(frontNode -> left, hd - 1));
            if(frontNode -> right)
                q.push(make_pair(frontNode -> right, hd + 1));
        }
        
        for(auto i : mpp){
            ans.push_back(i.second);
    }
    return ans;
    }

};