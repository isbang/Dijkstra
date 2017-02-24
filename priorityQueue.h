#define MAX         0x7fffffff  // int max
#define MAX_QUEUE_SIZE	63

#define LEFT_SUB_NODE(X)	(X*2)       // check if left sub node
#define RIGHT_SUB_NODE(X)	(X*2+1)
#define PARENT_NODE(X)		(X/2)


typedef struct _node {    // 큐를 위한 노드
    int priority;  // 우선순위
    void *pData;   // 데이터
}node;

typedef struct _queue {
    node *list[MAX_QUEUE_SIZE]; // using as pointer array
    int tail;   // tail index (init=1)
}queue;


queue* initQueue();
int enqueue(queue *Q, void *pData);
node* dequeue(queue *Q);
node* findNode(queue *Q, void *pData);
