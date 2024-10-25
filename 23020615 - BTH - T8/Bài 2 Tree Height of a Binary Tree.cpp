
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        int L = 1;
        int R = 1;
        if (root->left == NULL && root->right == NULL) {
            return 0;
        }
        if (root->left != NULL) {
            L += height(root->left);
        }
        if (root->right != NULL) {
            R += height(root->right);
        }
        return (R > L) ? R : L;
    }

