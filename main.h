#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true (1)
#define false (0)


typedef struct node
{
    char dataPtr;
    struct node* next;
}QUEUE_NODE;

typedef struct
{
    QUEUE_NODE* front;
    QUEUE_NODE* rear;
    int count;
}QUEUE;

QUEUE* createQueue(void)
{
    QUEUE* queue;
    queue=(QUEUE*)malloc(sizeof(QUEUE));
    if(queue)
    {
        queue->front=NULL;
        queue->rear=NULL;
        queue->count=0;
    }

    return queue;
}

void transfer(QUEUE* queue1, QUEUE* queue2)
{
    while(queue1->count!=0)
    {
        if(control(queue1)==1) rearrange(queue1);
        char itemPtr=dequeue(queue1);
        queueEkle(queue2,itemPtr);
        printf("\n queue1 in front u : %c,count:%d count q2: %d ",queue1->front->dataPtr,queue1->count,queue2->count);
    }
}

int search(char character)
{
    char dizi[4]={'/','*','+','-'};
    for(int i=0;i<4;i++)
    {
        if(character==dizi[i])
            return 0;
    }
        return 1;
}


char dequeue(QUEUE* queue)
{
    QUEUE_NODE* deleteLoc;
    char itemPtr;

    if(!queue->count)
        return false;

    itemPtr=queue->front->dataPtr;
    deleteLoc=queue->front;

    if(queue->count==1)
        queue->rear=queue->front=NULL;
    else
        queue->front=queue->front->next;
       // printf("d");
        free(deleteLoc);

    (queue->count)--;
    return itemPtr;
}



bool queueEkle (QUEUE* queue,char itemPtr)
{
    QUEUE_NODE* newPtr=(QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));

    if(!newPtr)
        return false;
    newPtr->dataPtr=itemPtr;
    newPtr->next=NULL;


    if(queue->count==0)
        queue->front=newPtr;
    else queue->rear->next=newPtr;

    (queue->count)++;
    queue->rear=newPtr;
    return true;
}



void enqueue(QUEUE* queue1,char* dizi)
{
    int boyut=strlen(dizi);
        for(int i=0;i<boyut;i++)
        {
            char character=dizi[i];
            queueEkle(queue1,character);
        }
}

int control(QUEUE* queue)
{
    if(search(queue->front->dataPtr)==0 && search(queue->front->next->dataPtr)==1 && search(queue->front->next->next->dataPtr)==1) // operatör opreand operand
        return 1;
    return 0;
}



void rearrange(QUEUE* queue)
{
    int val1=(int)queue->front->next->dataPtr-48;
    int val2=(int)queue->front->next->next->dataPtr-48;
        if(queue->front->dataPtr=='+')
                queue->front->dataPtr=(char)(val1+val2);
        else if(queue->front->dataPtr=='-')
        {
            if(val1>val2) queue->front->dataPtr=(char)(val1-val2);
            else queue->front->dataPtr=(char)(val2-val1);
        }
        else if(queue->front->dataPtr=='*')
            queue->front->dataPtr=(char)(val1*val2);
        else
        {
            if(val1>val2) queue->front->dataPtr=(val1/val2);
            else queue->front->dataPtr=(val2/val1);
        }
        (queue->count)-=2;

    queue->front->next=queue->front->next->next->next;
    printf("\n Q front data: %d , next data : %d %c\n",queue->front->dataPtr,queue->front->next->dataPtr,queue->front->next->dataPtr);

}
