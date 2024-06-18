// Approach 1

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int count(struct Node* tree){
        if(tree == NULL){
            return 0;
        }
        
        return 1 + count(tree->left) + count(tree->right);
    }
    
    bool isCBT(struct Node* tree, int index, int totalCount){
        if(tree == NULL){
            return true;
        }
        
        if(index >= totalCount){
            return false;
        }
        else{
            bool left = isCBT(tree->left, 2*index+1, totalCount);
            bool right = isCBT(tree->right, 2*index+2, totalCount);
            
            if(left && right){
                return true;
            }
            else{
                return false;
            }
        }
        
    }
    
    bool maxOrder(struct Node* tree){
        if(tree->left == NULL && tree->right == NULL){
            return true;
        }
        
        if(tree->right == NULL){
            return (tree->data > tree->left->data);
        }
        else{
            bool left = maxOrder(tree->left);
            bool right = maxOrder(tree->right);
            if(left && right && (tree->data > tree->left->data && tree->data > tree->right->data)){
                return true;
            }
            else{
                return false;
            }
        }
    }
    
    bool isHeap(struct Node* tree) {
        // code here
        int totalCount = count(tree);
        
        if(isCBT(tree,0,totalCount) && maxOrder(tree)) return true;
        return false;
    }
};


// Approach 2

bool isHeap(struct Node* tree) {
        // code here
        queue<Node*> q;
        q.push(tree);
        bool nullish = false;
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp->left){
                if(nullish || temp->data < temp->left->data){
                    return false;
                }
                q.push(temp->left);
            }
            else{
                nullish = true;
            }
            
            if(temp->right){
                if(nullish || temp->data < temp->right->data){
                    return false;
                }
                q.push(temp->right);
            }
            else{
                nullish = true;
            }
        }
        return true;
    }
