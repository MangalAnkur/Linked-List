#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

void insertstart(struct node **s,int data);
void insertlast(struct node **s,int data);
void insertafter(struct node **s,struct node *ptr,int data);
struct node* Find(struct node **s,int data);
int deletefirst(struct node **s);
int deletelast(struct node **s);
int deleteintermediate(struct node **s,struct node *ptr);
void viewlist(struct node **s);
int getfirst(struct node **s);
int getlast(struct node **s);

void insertstart(struct node **s,int data)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->info=data;
    p->prev=NULL;
    p->next=*s;
    *s=p;
}

void insertlast(struct node **s,int data)
{
    struct node *p,*t;
    p=(struct node*)malloc(sizeof(struct node));
    p->info=data;
    p->next=NULL;
    t=*s;
    if(*s==NULL)
    {
      p->prev=NULL;
      *s=p;
    }
    else{
        while(t->next!=NULL)
            t=t->next;
        p->prev=t;
        t->next=p;
    }
}


void insertafter(struct node **s,struct node *ptr,int data)
{
    struct node *p;
    if(ptr==NULL)
        printf("\n Invalid entry");
   else
        {
        p=(struct node*)malloc(sizeof(struct node));
        p->info=data;
        p->prev=ptr;
        p->next=ptr->next;
        if(ptr->next!=NULL)
        {
            ptr->next->prev=p;
            ptr->next=p;
        }
        }
}


struct node* Find(struct node **s,int data)
{
  struct node *t;
  if(*s==NULL)
        return (NULL);
  else
  {
      t=*s;
      while(t!=NULL)
      {
          if(t->info==data)
            return t;
          else
            t=t->next;
      }
      return NULL;
  }
}

int deletefirst(struct node **s)
{
    struct node *t;
    if(*s==NULL)
    {
      printf(" \n List is empty");
        return 0;
    }
    else
    {
          t=(*s);
          (*s)=(*s)->next;
          (*s)->prev=NULL;
          free (t);
          printf("\n first node has deleted");
          return 1;
    }
}

int deletelast(struct node **s)
{
    struct node *t;
    if(*s==NULL)
    {
        printf("\n List is empty");
        return 0;
    }
        t=*s;
        while(t->next!=NULL)
        t=t->next;
        if((*s)->next==NULL)
        *s=NULL;
        else
            t->prev->next=NULL;

        free (t);
        printf("\n Last node has deleted");
        return 1;
}

int deleteintermediate(struct node **s,struct node *ptr)
{
    if(*s==NULL)
    {
        printf ("\n List is empty");
        return 0;
    }
    if(ptr->prev==NULL)
    {
        *s=ptr->next;
        free (ptr);
        printf("\n intermediate node has deleted");
        return 1;
    }
    if(ptr->next==NULL)
    {
        ptr->prev->next=ptr->next;
        free (ptr);
        printf("\n intermediate node has deleted");
        return 1;
    }

    ptr->next->prev=ptr->prev;
    ptr->prev->next=ptr->prev;
    free (ptr);
    printf("\n intermediate node has deleted");
    return 1;
}





void viewlist(struct node **s)
{
    struct node *t;
    if(*s==NULL)
        printf("\n List is empty");
    t=*s;
    while(t!=NULL)
    {
        printf("\n %d ",t->info);
        t=t->next;
    }
}

int getfirst(struct node **s)
{
    if(*s==NULL)
        printf("\n List is empty");
     else
        return ((*s)->info);
}


int getlast(struct node **s)
{
     struct node *t;
    if(*s==NULL)
        printf("\n List is empty");
     t=*s;
    while(t->next!=NULL)
        t=t->next;
    return (t->info);
}

main()
{
    printf("SDFSVSDVsvs");
    struct node *start=NULL;
    struct node *ptr1;
    insertstart(&start,10);

    insertlast(&start,89);
    insertlast(&start,109);
    insertlast(&start,20);
    insertlast(&start,400);
    insertlast(&start,30);
    deletelast(&start);
    insertlast(&start,40);

    insertlast(&start,50);
    viewlist(&start);
    ptr1=Find(&start,20);
    insertafter(&start,ptr1,25);
    viewlist(&start);
    printf(" \n first value is %d ",getfirst(&start));
    printf(" \n last value is %d ",getlast(&start));
    deleteintermediate(&start,Find(&start,20));
   // viewlist(&start);
    deletefirst(&start);
   // viewlist(&start);
    deletelast(&start);
    viewlist(&start);
}


