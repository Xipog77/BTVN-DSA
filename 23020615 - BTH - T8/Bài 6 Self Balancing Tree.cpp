/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(node* root) {
        // Write your code here.
        if (root == nullptr) return -1;
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

node * left(node * root) {
    node * newNode = root->right;
    root->right = newNode->left;
    newNode->left = root;
    
    root->ht = height(root);
    newNode->ht = height(newNode);
    return newNode;
}

node * right(node * root) {
    node * newNode = root->left;
    root->left = newNode->right;
    newNode->right = root;
    
    root->ht = height(root);
    newNode->ht = height(newNode);
    return newNode;
}

node * left_right(node * root) {
    root->left = left(root->left);
    return right(root);
}

node * right_left(node * root) {
    root->right = right(root->right);
    return left(root);
}

node * insert(node * root,int val)
{
    if (root == nullptr) {
        node * newNode = new node;
        newNode->ht = 0;
        newNode->val = val;
        return newNode;
    }
    
    if (root->val > val) {
        root->left = insert(root->left,val);
    }
    else {
        root->right = insert(root->right,val);
    }
    root->ht = height(root);
    
      int balanceFactor = height(root->left) - height(root->right);
    
    // Thêm nút con mới gây mất cân bằng (xác định bới balanceFactor), vì thế kiểm tra
    // bằng cách so sánh với val (giá trị mới thêm vào)
    
    // Left-Left
    if (balanceFactor > 1 && val < root->left->val) {
        return right(root);
    }

    // Left-Right
    if (balanceFactor > 1 && val > root->left->val) {
        return left_right(root);
    }

    // Right-Right
    if (balanceFactor < -1 && val > root->right->val) {
        return left(root);
    }

    // Right-Left
    if (balanceFactor < -1 && val < root->right->val) {
        return right_left(root);
    }

    return root;
    
}