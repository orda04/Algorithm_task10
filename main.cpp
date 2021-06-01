/*
**********  9th task on  Algorithm course                                    ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date           28.05.2021                                        ****
**********  Modified date  30.05.2021                                        ****
*/

//

//+- Описать очередь с приоритетным исключением  in progress
//DONE● Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.




#include <iostream>
#include <stdbool.h>

//*************************************
//***** очередь и функции для нее
#define SZ 10

typedef struct 
   {
    int pr;
    int dat;
    
    }Node; 
Node* arr[SZ];
int head;
int tail;
int items;

void init()
    {
     for (int i=0;i<SZ;++i)
        {
         arr[i]=NULL;
         }
      head=0;
      tail=0;
      items=0;
    }
void ins(int pr, int dat)
{
   Node *node =(Node*) malloc (sizeof(Node));
   node->dat=dat;
   node->pr=pr;
   int flag;
   if(items==0)
      {
       arr[tail++] = node;
       items++;
       }
   else
      {
         if(items==SZ)
            {
             printf("%s \n", "Queue is full"); 
             return;
            }
          else
            {
              int i=0;
              int idx=0;
              Node *tmp;
              for(i=head; i<tail;++i)
                  {
                   idx=i%SZ;
                   if(arr[idx]->pr>pr)
                       {
                       break;
                       }
                   else 
                       {
                       idx++;
                       }
                  }
              flag =idx%SZ;
              i++;
              while(i<=tail)
                  {
                   idx=i%SZ;
                   tmp=arr[idx];
                   arr[idx]=arr[flag];
                   arr[flag]=tmp;
                   i++;
                  }
                arr[flag]=node;
                items++;
                tail++;
            } 
      }
}

Node* rem()
 {
  if(items==0)
     {
      return NULL;
     }
  else
     {
      int idx=head++%SZ;
      Node *tmp=arr[idx];
      arr[idx]=NULL;
      items--;
      return tmp;
     }
}

void printQueue()
 {
  printf("[");
  for(int i=0;i<SZ;++i)
     {
       if(arr[i]==NULL)
          {
           printf("[*,*");
          }
       else
         {
          printf("[%d,%d]",arr[i]->pr,arr[i]->dat);
         }
       }
    printf("]\n");
 }
//***** очередь и функции для нее
//*************************************


//*************************************
//***** стек и функции для него
#define T int //char
#define SIZE 1000
#define true 1==1
#define false 1!=1

typedef int boolean;
int cursor=-1;

T Stack[SIZE];
boolean push(T data)
   {
     if(cursor<SIZE)
      {
        Stack[++cursor]=data;
        return true;
      }
     else
      {
        printf("%s \n","Stack overflow");
        return false;
      }
   }

T pop()
   {
    if(cursor !=-1)
       {
        return Stack[cursor--];
       }
    else
      {
        printf("%s \n", "stack is empty");
        return -1;
       }
   }

//***** стек и функции для него
//*************************************


int main()
{
//*************************************
//***** очередь и функции для нее
  init();
  ins(1,11);
  ins(3,22);
  ins(4,33);
  ins(2,44);
  ins(3,55);
  ins(4,66);
  ins(5,77);
  ins(1,88);
  ins(2,99);
  ins(6,100);
  printQueue();
  for(int i=0;i<7;++i)
     {
      Node* n=rem();
      printf("pr=%d,dat=%d \n",n->pr,n->dat );
     }
  printQueue();
  ins(1,110);
  ins(3,120);
  ins(6,130);
  printQueue();
  for(int i=0;i<5;++i)
     {
      Node* n=rem();
      printf("pr=%d,dat=%d \n",n->pr,n->dat );

     }
  printQueue();
//***** очередь и функции для нее
//*************************************

//*************************************
//***** стек и функции для него
//push('a');
//push('b');
//push('c');
//push('d');
//push('e');
//push('f');
//push('g');
int x=0;
printf("Please enter you digit (positive int): ");
scanf("%d",&x);

if(x==0)
  {
   printf("\nSo nothing to modify.... 0 is 0\n");
   }
else
  {
    while (x > 0)
       {
         push(x%2);
         x /= 2;
        }
    printf("Your modified digit after function dec into binary will be: ");
    while (cursor!=-1)
       {
        printf("%d" , pop());
       }
}

printf("\n");


//***** стек и функции для него
//*************************************



  return 0;
}
