
//https://practice.geeksforgeeks.org/problems/level-order-traversal/1
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      vector<int> v;
      queue<Node*> pendingNodes;
      pendingNodes.push(node);
      while(!pendingNodes.empty()){
          Node* front = pendingNodes.front();
          v.push_back(front -> data);
          pendingNodes.pop();
          if(front -> left)
            pendingNodes.push(front -> left);
          if(front -> right)
            pendingNodes.push(front -> right);
      }
      return v;
      
    }
};