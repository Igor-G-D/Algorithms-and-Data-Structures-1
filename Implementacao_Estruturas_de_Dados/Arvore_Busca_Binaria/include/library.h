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
void rotationLL ( TreeNode ** p);
void rotationRR ( TreeNode ** p);
void rotationRL ( TreeNode ** p); 
void rotationLR ( TreeNode ** p); 
void balancingAVL ( TreeNode **p );
void printInOrder ( TreeNode *p );
void printPreOrder ( TreeNode *p );
void printPostOrder ( TreeNode *p );
