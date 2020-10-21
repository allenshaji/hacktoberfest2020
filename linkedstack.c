#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *next;

};
struct stack *top=NULL;

void push()
{
    int val;
    struct stack *ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    printf("enter the data:");
    scanf("%d",&val);
    ptr->data = val;
    if(top==NULL)
    {
        ptr->next =  NULL;
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
}

void pop()
{
    struct stack *ptr;
    ptr=top;
    if(top==NULL)
        printf("stack underflow\n");
    else
    {
        top = top->next ;
        printf("%d will be deleted\n",ptr->data);
        free(ptr);
    }
}

void peek()
{
    if(top==NULL)
        printf("\nstack underflow");
    else
        printf("\n%d",top->data);
}

void disp()
{
    struct stack *ptr;
    ptr=top;
    if(top==NULL)
        printf("stack underflow");
    else
    {
        while(ptr!=NULL )
        {
            printf("<-%d",ptr->data);
            ptr=ptr->next;
        }

    }

}

void main()
{
    int n;
    do
    {
        printf("\n 1.PUSH");
        printf("\n 2.POP");
        printf("\n 3.PEEK");
        printf("\n 4.EXIT\n");
        scanf("%d",&n);
        system("CLS");
        switch(n)
        {
        case 1:
                push();
                disp();
                break;
        case 2:
                pop();
                disp();
                break;
        case 3:
                peek();
        }
    }while(n!=4);
}
