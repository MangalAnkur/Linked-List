#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *last);
struct node* addatbeg(struct node *last,int value);
struct node* addtoempty(struct node *last,int value);
struct node* addatend(struct node *last,int value);
struct node* addafter(struct node *last,int item,int value);
struct node *del(struct node * last,int value);
struct node* createlist(struct node *last);

void display(struct node *last)
{
    struct node *t;
    if(last==NULL)
        printf("\n LIst is empty");
    else
    {
        t=last->next;
        do
        {
            printf("\n %d",t->data);
            t=t->next;
        }while(t!=last->next);
    }
}

struct node* addatbeg(struct node *last,int value)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->next=last->next;
    n->data=value;
    last->next=n;
    return last;
};

struct node* addtoempty(struct node *last,int value)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    last=n;
    n->data=value;
    last->next=last;
    return last;
};

struct node* addatend(struct node *last,int value)
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=value;
    n->next=last->next;
    last->next=n;
    last=n;
    return last;
};

struct node* addafter(struct node *last,int item,int value)
{
    struct node * t,*n;
    t=last->next;
    do
    {
      if(t->data==item)
      {
          n=(struct node *)malloc(sizeof(struct node));
          n->data=value;
          n->next=t->next;
          t->next=n;
          if(t==last)
            last==n;
          return last;
      }
      t=t->next;
    }while(t!=last->next);
    printf ("\n %d is not in the list ",item );
    return 0;
}

struct node *del(struct node * last,int value)
{
    struct node *t,*p,*x;
    if(last==NULL)
    {
        printf ("\n LIST IS EMPTY ");
        return last;
    }
    if(last==last->next && last->data==value)
    {
        t=last;
        last=NULL;
        free(t);
        printf ("\n Value has deleted");
        return last;
    }

    if(last->next->data==value)
    {
        t=last->next;
        last->next=t->next;
        free(t);
        printf ("\n Value has deleted");
        return last;
    }
    p=last->next;
    while(p->next!=last)
    {
        if(p->next->data==value)
        {
            t=p->next;
            p->next=t->next;
            free(t);
            printf ("\n Value has deleted");
            return last;
        }
        p=p->next;
    }
    if(last->data==value)
    {
        x=last;
        p->next = last->next;
        last=p;
        free(x);
        printf ("\nValue has deleted");
        return last;
    }
    printf("\n %d is not found",value);
    return last;
}

struct node* createlist(struct node *last)
{
   int n,i,value ;
   printf("\nHow many values you want to enter ?");
   scanf("%d",&n);
   printf("\nEnter first value");
   scanf("%d",&value);
   last=addtoempty(last,value);
   for(i=2;i<=n;i++)
   {
       printf("\n Enter next value");
       scanf("\n%d",&value);
       last=addatend(last,value);
   }
   return last;
}

main()
{
    int item,value,choice;
    struct node *last=NULL;

    while(1)
    {
       // system("cls");
        printf("\n 1.create list");
        printf("\n 2.Display list");
        printf("\n 3.Add to empty list");
        printf("\n 4.add at begining ");
        printf("\n 5.add at end");
        printf("\n 6.add after");
        printf("\n 7.delete");
        printf("\n 8.exit");
        printf("\n\n Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            last=createlist(last);
            break;
        case 2:
            display(last);
            break;
        case 3:
            printf("\n Enter the value to add in the list");
            scanf("%d",&value);
            last=addtoempty(last,value);
            break;
        case 4:
            printf("\n Enter the value to add in the list");
            scanf("%d",&value);
            last=addatbeg(last,value);
            break;
        case 5:
            printf("\n Enter the value to add in the list");
            scanf("%d",&value);
            last=addatend(last,value);
            break;
        case 6:
            printf("\n Enter item value after which the new value to be inserted");
            scanf("%d",&item);
            printf("\n Enter the value to add in the list");
            scanf("%d",&value);
            last=addafter(last,item,value);
            break;
        case 7:
            printf("\n Enter the value to be deleted");
            scanf("%d",&value);
            last=del(last,value);
            break;
        case 8:
            exit(0);
            break;
        default :
            printf("\n Invalid choice");
        }
    }
}









