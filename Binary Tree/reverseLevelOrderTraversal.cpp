//https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> v;
      queue<Node*> pendingNodes;
      pendingNodes.push(root);
      while(!pendingNodes.empty()){
          Node* front = pendingNodes.front();
          v.push_back(front -> data);
          pendingNodes.pop();
          if(front -> right)
            pendingNodes.push(front -> right);
          if(front -> left)
            pendingNodes.push(front -> left);
      }
      reverse(v.begin(), v.end());
      return v;
}