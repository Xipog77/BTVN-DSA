

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        if (root == NULL) {
            Node * newNode = new Node(data);
            return newNode;
        }
        if (data < root->data) {
            if (root->left == NULL) {
                Node * newNode = new Node(data);
                root->left = newNode;
            }
            else {
                insert(root->left, data);
            }
        }
        else {
            if (root->right == NULL) {
                Node * newNode = new Node(data);
                root->right = newNode;
            }
            else {
                insert(root->right, data);
            }
        }
        
        return root;
    }

