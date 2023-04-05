typedef struct _TreeNode {
    int color;
    int value;
    struct _TreeNode * parent;
    struct _TreeNode * left;
    struct _TreeNode * right;
} TreeNode;

typedef struct {
    TreeNode * root;
} TreeHead;