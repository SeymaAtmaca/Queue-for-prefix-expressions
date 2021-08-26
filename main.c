#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{

    char metin[15];

    printf("Lutfen prefix idafenizi giriniz : ");
    gets(metin);

    QUEUE* queue1=createQueue();
    QUEUE* queue2=createQueue();

    enqueue(queue1,metin);
    for(int i=0;i>-1;i++)
    {
        if((queue1->count==1 && queue2->count==0)||(queue1->count==0 && queue2->count==1))
            break;
        if(queue1->count>1 && queue2->count==0) // Q1 den Q2 ye kontrollü aktarim
            transfer(queue1,queue2);
        else if(queue2->count>1 && queue2->count ==0 ) //Q2 den Q1 e aktarim
            transfer(queue2,queue1);
    }
}
