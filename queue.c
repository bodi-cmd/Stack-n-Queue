#include <stdio.h>

#define CAP 5
typedef struct
{
    int vec[CAP];
    int size;
    int head, tail;
}queue;

void init(queue* q){
    q->size=0;
    q->head=0;
    q->tail=0;
}

void enqueue(queue* q, int key){
        if(q->size<CAP){
        q->vec[q->tail]=key;
        q->size = q->size+1;
        if(q->tail==CAP-1){
            q->tail=0;
        }
        else q->tail= q->tail+1;
    }
        else{
            printf("Coada este plina! ");
        }
}

int dequeue(queue* q){
    if(q->size!=0){
        q->size--;
        int temp = q->vec[q->head];
        if(q->head==CAP-1){
            q->head=0;
        }
        else{
            q->head ++;
        }
        return temp;
    }
    printf("Coada este goala! ");
    return 0;
}

void print(queue q){
    for(int i=q.head;i<q.head+q.size;i++){
        printf("%d ",q.vec[i%CAP]);
    }
}

int main() {

    queue q;
    init (&q);
    enqueue(&q,5);
    enqueue(&q,2);
    dequeue(&q);
    enqueue(&q,3);
    enqueue(&q,4);

    enqueue(&q,7);

    enqueue(&q,8);

    enqueue(&q,8);
    enqueue(&q,8);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    print(q);
    return 0;
}

