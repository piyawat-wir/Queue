#include "Node.h"

typedef struct
{
    order *headPtr, *tailPtr;
    int size;
} Queue;


void enqueue(Queue *Q,  int orderNum, int orderAmount)
{

    NodePtr new_node;

    new_node = (NodePtr) malloc(sizeof(Node));
    if (new_node)
    {
        new_node->order_number = orderNum;
        new_node->q = orderAmount;
        new_node->nextPtr = NULL;

        if(Q->headPtr == NULL)
        {
            Q->headPtr = new_node;
        }
        else
        {
            Q->tailPtr->nextPtr = new_node;
        }
        Q->tailPtr = new_node;
        Q->size++;
    }


}

order dequeue(Queue *Q)
{
    order value = {0, 0};
    NodePtr t;

    if(Q->size>0)
    {
        t=Q->headPtr;
        value=*t;

        Q->headPtr=t->nextPtr;
        if(Q->size==1) Q->tailPtr=NULL;
        Q->size--;

        free(t);
    }

    return value;

}
