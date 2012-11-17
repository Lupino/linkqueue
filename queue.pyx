cimport cqueue
ERR_NOMEMORY = -1
ERR_INVALIDPARAM = -2
ERR_EMPTYRESULT = -3

cdef class Queue:
    cdef cqueue.LinkQueue *queue
    
    def __cinit__(self):
        self.queue = cqueue.LinkQueueNew()
        ret = cqueue.InitQueue(self.queue)
        if ret == ERR_NOMEMORY:
            raise MemoryError()
        if ret == ERR_INVALIDPARAM:
            raise RuntimeError()
    def __dealloc__(self):
        ret = cqueue.DestoryQueue(self.queue)
        if self.queue is not NULL:
            cqueue.LinkQueueFree(self.queue)
        if ret == ERR_INVALIDPARAM:
            raise RuntimeError()
    def empty(self):
        ret = cqueue.QueueEmpty(self.queue)
        if ret == ERR_INVALIDPARAM:
            raise RuntimeError()
        return ret
    def getHead(self):
        cdef int e
        ret = cqueue.GetHead(self.queue, &e)
        if ret == ERR_INVALIDPARAM:
            raise RuntimeError()
        if ret == ERR_EMPTYRESULT:
            raise IndexError("Queue is empty")
        return e
    def push(self, e):
        ret = cqueue.EnQueue(self.queue, e)
        if ret == ERR_NOMEMORY:
            raise MemoryError()
        if ret == ERR_INVALIDPARAM:
            raise RuntimeError()
    def pop(self):
        cdef int e
        ret = cqueue.DeQueue(self.queue, &e)
        if ret == ERR_INVALIDPARAM:
            raise RuntimeError()
        if ret == ERR_EMPTYRESULT:
            raise IndexError("Queue is empty")
        return e
