#include <stdlib.h>
typedef struct {
    int   *data;
    int    tail;
    int    size;
    int    capacity;
    double sum;
} MovingAverage;

MovingAverage *movingAverageCreate(int size) {
    MovingAverage *obj = (MovingAverage *)malloc(sizeof(MovingAverage));
    obj->data          = (int *)calloc(size, sizeof(int));
    obj->tail          = 0;
    obj->size          = 0;
    obj->capacity      = size;
    obj->sum           = 0.0;
    return obj;
}

double movingAverageNext(MovingAverage *obj, int val) {
    obj->sum -= obj->data[obj->tail];
    obj->data[obj->tail] = val;
    obj->sum += val;
    obj->tail = (obj->tail + 1) % obj->capacity;
    if (obj->size < obj->capacity)
        obj->size++;
    return obj->sum / obj->size;
}

void movingAverageFree(MovingAverage *obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);

 * movingAverageFree(obj);
*/
