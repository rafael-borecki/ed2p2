struct Node* createNode(char data[10]);
struct Node* insert(struct Node* root, char data[10], int *counter);
void preorderTraversal(struct Node* root, int *counter);
struct Node* search(struct Node* root, char data[10], int *counter, int *found);
