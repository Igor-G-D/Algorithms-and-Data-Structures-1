typedef struct _node {
    int value;
    struct _node *left;
    struct _node *right;
} TreeNode;

typedef struct _head {
    struct _node *root;
} TreeHead;

TreeHead * createTreeHead ( );
TreeNode * createTreeNode ( int value );
void insertTreeNode ( TreeNode **p, TreeNode *newNode );
void removeTreeNode ( TreeNode **p, int value );
int height( TreeNode *p );
int balancingFactor( TreeNode *p );
TreeNode * deleteHighest(TreeNode ** p);
TreeNode * deleteLowest(TreeNode ** p);
