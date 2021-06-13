/*
**********  10th task on  Algorithm course                                   ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date           28.05.2021                                        ****
**********  Modified date  30.05.2021 and 10.06.2021                         ****
*/

//
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef struct Node
{
    int dat;
    struct Node *next;
 }Node;
typedef struct
{
    Node *head;
    int size;
}List;
void init (List *lst)
{
    lst->head =NULL;
    lst->size=0;
}
void ins(List* lst, int data)
{
 Node *New=(Node*)malloc(sizeof(Node));
 New->dat=data;
 New->next=NULL;

 Node *current = lst->head;
 if(current==NULL)
      {
         lst->head=New;
         lst->size++;
         return;
       }
 else
      {
       while(current->next!=NULL)
           {
             current=current->next;
           }
       current->next=New;
       lst->size++;
       }
}

Node* rm(List *lst, int data)
{
    Node *current =lst->head;
    Node *parent=NULL;
    if(current==NULL)
       {
        return NULL;
       }
    while (current->next != NULL && current->dat != data)
       {
        parent=current;
        current=current->next;
       }
     if(current->dat !=data)
       {
         return NULL;
       }
     if (current==lst->head)
       {
         lst->head=current->next;
         lst->size--;
         return current;
        }
      parent->next = current->next;
      lst->size--;
      return current;
}
void printNode (Node *n)
  {
     if(n==NULL)
        {
         printf("[]");
         return;
        }
     printf("%d ", n->dat);
  }
void printList(List *lst)
  {
   Node * current =lst->head;
    if (current ==NULL)
       {
        printNode(current);
       }
    else
       {
        do
           {
            printNode(current);
            current=current->next;
           }
        while (current!=NULL);
    }
    printf("SIZE: %d \n",lst->size);
}

void copyLST(List* lst, List *lst1)
{
    Node *current = lst->head;
    Node *current1=lst1->head;

 if(current==NULL)
    {
      printf("original list was not founded");
      return;
    }
 else
   {
        while(current!=NULL)
        {
            if(lst1->head==NULL)  // copying very first member
             {
                  Node *New1=(Node*)malloc(sizeof(Node));
                  New1->dat=current->dat;
                  New1->next=NULL;

                  lst1->head=New1;
                  lst1->size++;
                  current1=lst1->head;
                  current=current->next;

                }
              else  // all others in copy
               {
                  Node *New1=(Node*)malloc(sizeof(Node));
                  New1->dat=current->dat;
                  New1->next=NULL;
                  current1->next=New1;
                  lst1->size++;
                  current=current->next;
                  current1=current1->next;
                }

         }

    }
}
int checkSortLST(List* lst)
{

   bool Posflag =true;
   bool Negflag=true;
   Node * current =lst->head;
   int tmp;
    if (current ==NULL)
        {
         printf("You have no data in list... nothing to check");
         return 0;
        }
     else
       {
         for(int i=1;i<lst->size;i++)
            {
               tmp=current->dat;
               current=current->next;
                if(tmp==current->dat)
                   {
                    continue;

                    }
                else
                    {
                        if(tmp<current->dat)
                            {
                            Negflag=false;
                            //current=current->next;
                            }
                         else
                           {
                            Posflag=false;
                           }
                   }
                if(Negflag!=true&&Posflag!=true)
                    {
                      return -1;
                     }
           printf("\ntmp= %d,next=%d,posflag=%d,negdlag=%d\n",tmp,current->dat,Posflag,Negflag);
               // i++;
           }

        }
    if (Posflag)
       {
        return 2;
       }
   if (Negflag)
         {
        return 1;
       }
}

int main()
{
    int n;
 List *lst=(List*)malloc(sizeof(List));
 List *lst1=(List*)malloc(sizeof(List));
 init(lst);
 init(lst1);
 printList(lst);
 n=checkSortLST(lst);


 printf("\nInserting number 1 as a first member\n");
 ins(lst, 3);
 printList(lst);
 printf("\nInserting number 2 as a second member\n");
 ins(lst, 2);
 printList(lst);
 printf("\nInserting number 3 as a third member\n");
 ins(lst, 1);
 printList(lst);
 printf("\nInserting number 4 as a fourth member\n");
 ins(lst, 0);
 printList(lst);
 printf("\nInserting number 5 as a fifth member\n");
 ins(lst, 0);
 printList(lst);
 printf("\ncopying all data....\n");
  copyLST(lst,lst1);
  printf("\nPrinting lst1\n");
  printList(lst1);
  n=checkSortLST(lst);
 printf("\nN=%d\n",n);
  if(n==2)
  {
     printf("\nsorted.... growing\n");
    }
 if(n==1)
  {
     printf("\nsorted....falling\n");
    }
 if(n<0)
  {
     printf("\nUnsorted...\n");
    }
     return 0;
}
