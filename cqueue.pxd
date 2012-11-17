cdef extern from "linkqueue.h":

    ctypedef struct QueueNode:
        int data
        QueueNode *next

    ctypedef struct LinkQueue:
        QueueNode *front
        QueueNode *rear
        
    int InitQueue(LinkQueue *queue)

    int QueueEmpty(LinkQueue *queue)
    int GetHead(LinkQueue *queue, int *e)

    int EnQueue(LinkQueue *queue, int e)

    int DeQueue(LinkQueue *queue, int *e)

    int DestoryQueue(LinkQueue *queue)
    LinkQueue * LinkQueueNew()
    void LinkQueueFree(LinkQueue *lq)

