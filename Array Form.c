//Queue using array
#include<stdio.h>
#include<stdlib.h>
int front=0;
int end=0;
int a[10];
void push(int x)
{
	if(end==10)
	{
		printf("There is no more spaces, try option two to clear some spaces\n");
	}
	else
	{
		a[end]=x;
		end++;
	}
}
int pop()
{
	int z=-999;
	int i=0;
	if(front==end)
	{
		printf("It's Empty, try option 1 to push few datas\n");
	}
	else
	{
		z=a[front];
		for(i=front;i<end-1;i++)
			a[i]=a[i+1];
		end=end-1;
	}
	return z;
}
void display()
{
	int i=0;
	if(top!=end)
	{
		for(i=front;i<end;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	else
	{
		printf("Empty Queue\n");
	}
}
void main()
{
	int x,c=1;
	while(c!=4)
	{
		if(c==1)
		{
			printf("Enter Number to be pushed\n");
			scanf("%d",&x);
			fflush(stdin);
			push(x);
		}
		else if(c==2)
		{
			x=pop();
			if(x!=-999)
				printf("Popped Number => %d\n",x);
		}
		else if(c==3)
		{
			display();
		}
		printf("Options\n1:Push\n2:Pop\n3:Display\n4:Exit\n");
		scanf("%d",&c);
		fflush(stdin);
	}
}
