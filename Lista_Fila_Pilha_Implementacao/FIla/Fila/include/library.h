typedef struct _NodeQueue{ //doubly linked list
    int value;
    struct _NodeQueue *next;
    struct _NodeQueue *previous;
} NodeQueue;

typedef struct {
    int quantity;
    NodeQueue *front;
    NodeQueue *back;
} NodeQueueHead;

NodeQueueHead *createHead(void);
NodeQueue *createNode(int value);
void push(NodeQueueHead **head, NodeQueue *newNode);
NodeQueue *pop(NodeQueueHead **head);
void reset(NodeQueueHead **head);
void QueueQueue(NodeQueueHead **head);