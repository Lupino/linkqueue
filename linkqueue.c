#include "linkqueue.h"
int InitQueue(LinkQueue *queue){
    QueueNode *q;
    if(!queue) return ERR_INVALIDPARAM;
    
    q = (QueueNode*)malloc(sizeof(QueueNode));
    if(!q) return ERR_NOMEMORY;
    q->next = NULL;
    queue->front = q;
    queue->rear = q;
    return 0;
}

int QueueEmpty(LinkQueue *queue){
    if(!queue) return ERR_INVALIDPARAM;
    return (queue->front == queue->rear);
}

int GetHead(LinkQueue *queue, datatype *e){
    QueueNode *q;
    if(!queue) return ERR_INVALIDPARAM;
    if(queue->front == queue->rear) return ERR_EMPTYRESULT;
    
    q = queue->front->next;
    *e = q->data;
    return 0;
}

int EnQueue(LinkQueue *queue, datatype e){
    QueueNode *q;
    if(!queue) return ERR_INVALIDPARAM;
    
    q = (QueueNode*)malloc(sizeof(QueueNode));
    if(!q) return ERR_NOMEMORY;
    
    q->data = e;
    q->next = NULL;
    queue->rear->next = q;
    queue->rear = q;
    return 0;
}

int DeQueue(LinkQueue *queue, datatype *e){
    QueueNode *q;
    if(!queue) return ERR_INVALIDPARAM;
    if(queue->front == queue->rear) return ERR_EMPTYRESULT;
    
    q = queue->front->next;
    queue->front->next = q->next;
    if(queue->rear == q)queue->rear = queue->front;
    
    *e = q->data;
    
    free(q);
    
    return 0;
}

int DestoryQueue(LinkQueue *queue){
    if(!queue) return ERR_INVALIDPARAM;
    while(queue->front){
        queue->rear = queue->front->next;
        free(queue->front);
        queue->front = queue->rear;
    }
    return 0;
}

LinkQueue * LinkQueueNew(){
    LinkQueue *lq;
    lq = (LinkQueue*)malloc(sizeof(LinkQueue));
    return lq;
}
void LinkQueueFree(LinkQueue *lq){
    free(lq);
}
//int main(){return 0;}
