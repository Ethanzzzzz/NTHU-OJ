typedef struct _Node {
    int id;
    struct _Node* next;
} Node;

void reverse(Node *node_l, Node *node_r);
