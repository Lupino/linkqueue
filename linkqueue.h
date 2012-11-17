#include<malloc.h>
#define ERR_NOMEMORY -1
#define ERR_INVALIDPARAM -2
#define ERR_EMPTYRESULT -3

typedef int datatype;

typedef struct node{
    datatype data;
    struct node *next;
} QueueNode;

typedef struct{
    QueueNode *front;
    QueueNode *rear;
}LinkQueue;

int InitQueue(LinkQueue *queue);

int QueueEmpty(LinkQueue *queue);
int GetHead(LinkQueue *queue, datatype *e);

int EnQueue(LinkQueue *queue, datatype e);

int DeQueue(LinkQueue *queue, datatype *e);

int DestoryQueue(LinkQueue *queue);

LinkQueue * LinkQueueNew();
void LinkQueueFree(LinkQueue *lq);
