#include<stdio.h>
#include<stdlib.h>
struct Number 
{
	int n;
	struct Number *next;
};
typedef struct Number node;

void countprime(node *h)
{
	node *i;
	int c=0;
	for(i=h;i!=NULL;i=i->next)
	{
		if(isprime(i->n))
			c++;
	}
	printf("%d ",c);
}
void frequency(node *h, int x)
{
	node *i;
	int c=0;
	for(i=h;i!=NULL;i=i->next)
	{
		if(i->n==x)
			c++;
	}
	printf("%d occurs %d times\n",x,c);
}
int isprime(int x)
{
	int i=0;
	int c=0;
	for(i=1;i<=x;i++)
	{
		if(x%i==0)
			c++;
	}
	if(c==2)
		return 1;
	else
		return 0;
}
node* push(node *h, int x)
{
	node *temp;
	node *p;
	temp=(node*)malloc(sizeof(node));
	temp->n=x;
	temp->next=NULL;
	if(h==NULL)
	{
		h=temp;
	}
	else
	{
		p=h;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
	return h;
}
void display(node *h)
{
	node *i;
	for(i=h;i!=NULL;i=i->next)
	printf("%d ",i->n);
	printf("\n");
}
node * delfirst(node *h)
{
	node *p;
	if(h==NULL)
		printf("Empty\n");
	else if(h->next==NULL)
	{
		h=NULL;
		free(h);
	}
	else
	{
		p=h;
		h=h->next;
		p->next=NULL;
		free(p);
	}
	return h;
}
node *dellast(node *h)
{
	node *i;
	if(h==NULL)
		printf("Empty\n");
	else if(h->next==NULL)
	{
		h=NULL;
		free(h);
	}
	else
	{
		for(i=h;(i->next)->next!=NULL;i=i->next)
		{
		}
		i->next=NULL;
	}
	return h;
}
int no_of_nodes(node *h)
{
	int c=0;
	node *i;
	for(i=h;i!=NULL; i=i->next)
		c++;
	return c;
}
node * delnth(node *h, int x)
{
	node *i;
	int k=1;
	node *j;
	if(x<=0 && x>no_of_nodes(h))
	{
		printf("Node not Present\n");
	}
	else
	{
		i=h;
		if(x==1)
		{
			free(i);
		}
		else{
		for(k=1;k<(x-1);k++)
		{
			i=i->next;
		}
		j=i->next;
		i->next=j->next;
		j->next=NULL;
		free(j);}
	}
	return h;
}
void display1(node *h)
{
	node *i=h;
	if(i->next==NULL)
	{
		printf("%d ",i->n);
		return;
	}
	else
	{
		i=i->next;
		display1(i);
		printf("%d ",i->n);
		return;
	}
}
node *insertfirst(node *h, int x)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->n=x;
	
	if(h==NULL)
	{
		h=temp;
		h->next=NULL;
	}
	else
	{
		temp->next=h;
		h=temp;
	}
	return h;
}
node *asc2(node *h)
{
	node *i,*j,*s;
	int t;
	for(i=h;i->next!=NULL;i=i->next)
	{
		s=i;
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(s->n>j->n)
				s=j;
		}
		t=i->n;
		i->n=s->n;
		s->n=t;
	}
	return h;
}
node *asc1(node *h)
{
	node *i=h;
	node *j=h;
	int x=0;
	
	for(i=h;i!=NULL;i=i->next)
	{
		for(j=h;j->next!=NULL;j=j->next)
		{
			if(j->n > (j->next)->n)
			{
				x=j->n;
				j->n=(j->next)->n;
				(j->next)->n=x;
			}
		}
	}
	return h;
}
node * insertlast(node * h,int x)
{
	node *temp;
	node *i;
	temp=(node*)malloc(sizeof(node));
	temp->n=x;
	
	if(h==NULL)
	{
		h=temp;
		h->next=NULL;
	}
	else
	{
		for(i=h;i->next!=NULL;i=i->next);
		i->next=temp;
		temp->next=NULL;
	}
	return h;
}
node * insert_before_nth_position(node *h, int x, int p)
{
	node *temp; node *i; int k=1; node *m;
	temp=(node*)malloc(sizeof(node));
	temp->n=x;
	
	if(p==1)
	{
		temp->next=h;
		h=temp;
	}
	else
	{
		i=h;
		for(k=1;k<(p-1);k++)
		{
			i=i->next;
		}
		m=i->next;
		i->next=temp;
		temp->next=m;
	}
	return h;
}
void smallar(node *h)
{
	int sm=h->n;
	int lar=h->n;
	node *i=h->next;
	for(i=h->next;i!=NULL;i=i->next)
	{
		if(i->n<sm)
			sm=i->n;
		if(i->n>lar)
			sm=i->n;
	}
	printf("\nSmallest=%d\nLargest=%d",lar,sm);
}
node * crop1(node *h)
{
	
	int z=0;
	node *i;
	node *t=NULL;
	for(i=h;i!=NULL;i=i->next)
	{
		z=i->n;
	}
	h=dellast(h);
	t=(node*)malloc(sizeof(node));
	t->n=z;
	t->next=h;
	h=t;
	return h;
}
node *crop2(node *h)
{
	node *i=h;
	int z=i->n;
	h=push(h,z);
	h=delfirst(h);
	return h;	
}
void main()
{
	node *head;
	int no=0;
	int ch=1;
	int t=0;
	head=NULL;
	do
	{
		if(ch==1)
		{
			printf("Enter a Number\n");
			scanf("%d",&no);
			fflush(stdin);
			head=push(head,no);
		}
		else if(ch==2)
		{
			printf("Do you want to print the List from front to end or from end to front\n");
			scanf("%d",&ch);
			fflush(stdin);
			if(ch==1)
				display(head);
			else
				display1(head);
			ch=2;
		}
		else if(ch==3)
		{
			printf("If you want to delete from front press 1. If you want to delete from Rear press 2. If you want to remove from nth position press 3\n");
			scanf("%d",&ch);
			fflush(stdin);
			if(ch==1)
				head=delfirst(head);
			else if(ch==2)
				head=dellast(head);
			else
			{
				printf("Enter the value of n\n");
				scanf("%d",&t);
				fflush(stdin);
				head=delnth(head,t);
			}
			ch=3;
		}
		else if(ch==4)
			countprime(head);
		else if(ch==5)
		{
			printf("If you want to insert before the first press 1. If you want to enter after last press 2. If you want to enter in the nth position press 3\n");
			scanf("%d",&ch);
			fflush(stdin);
			if(ch==1)
			{
				printf("Enter The Number\n");
				scanf("%d",&no);
				fflush(stdin);
				head=insertfirst(head,no);
			}
			else if(ch==2)
			{
				printf("Enter The Number\n");
				scanf("%d",&no);
				fflush(stdin);
				head=insertlast(head,no);
			}
			else if(ch==3)
			{
				printf("Enter the nth position");
				scanf("%d",&t);
				fflush(stdin);
				printf("Enter The Number\n");
				scanf("%d",&no);
				fflush(stdin);
				head=insert_before_nth_position(head,no,t);
			}
			ch=5;
		}
		else if(ch==6)
		{
			scanf("%d",&no);
			fflush(stdin);
			frequency(head,no);
		}
		else if(ch==7)
		{
			smallar(head);
		}
		else if(ch==8)
		{
			printf("Enter 1 to use Bubble Sort\nEnter 2 to use Selection Sort\n");
			scanf("%d",&ch);
			fflush(stdin);
			if(ch==1)
				head=asc1(head);
			else if(ch==2)
				head=asc2(head);
			ch=8;
		}
		else if(ch==9)
		{
			printf("To Crop the Last Node Press 1\nTo Crop the first node Press 2\n");
			scanf("%d",&ch);
			fflush(stdin);
			if(ch==1)
			{
				head=crop1(head);
			}
			else if(ch==2)
			{
				head=crop2(head);
			}
			ch=9;
		}
		printf("\nDo You want to continue Entering? If yes press 1.\nIf you want to display the values press 2.\nIf you want to delete a value press 3.\nIf you want to count number of prime in the List press 4.\nIf you want to insert a number press 5.\nIf you want to count the frequency of a particular Number press 6.\nIf you want to know the Smallest and Largest Element of the List press 7.\nTo Sort the List in Ascending Order Press 8.\nTo Crop Enter 9\nIf you want to Exit press 10.\n");
		scanf("%d",&ch);
		fflush(stdin);
	}while(ch!=10);
}
