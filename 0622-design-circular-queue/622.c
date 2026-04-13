#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *queue;
    int  head;
    int  tail;
    int  size;
    int  capacity;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k) {
    MyCircularQueue *myCircularQueue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    myCircularQueue->queue           = (int *)malloc(k * sizeof(int));
    myCircularQueue->capacity        = k;
    myCircularQueue->size            = 0;
    myCircularQueue->head            = 0;
    myCircularQueue->tail            = 0;
    return myCircularQueue;
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue *obj) {
    return obj->size == obj->capacity;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    obj->queue[obj->tail] = value;
    obj->tail             = (obj->tail + 1) % obj->capacity;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    obj->head = (obj->head + 1) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue *obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->queue[obj->head];
}

int myCircularQueueRear(MyCircularQueue *obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    int tail_idx = (obj->tail - 1 + obj->capacity) % obj->capacity;
    return obj->queue[tail_idx];
}

void myCircularQueueFree(MyCircularQueue *obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
