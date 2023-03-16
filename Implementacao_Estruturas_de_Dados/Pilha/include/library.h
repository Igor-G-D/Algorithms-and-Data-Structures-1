typedef struct _NodeStack{
    int value;
    struct _NodeStack *next;
} NodeStack;
typedef struct {
    int quantity;
    NodeStack *next;
} NodeStackHead;
NodeStackHead *createHead(void);
NodeStack *createNode(int value);
void push(NodeStackHead **head, NodeStack *newNode);
NodeStack *pop(NodeStackHead **head);
void reset(NodeStackHead **head);
void listStack(NodeStackHead **head);