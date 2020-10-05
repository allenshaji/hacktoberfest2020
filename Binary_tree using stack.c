#include <stdio.h>
#include <malloc.h>

//shravani paraswar
struct BTree
{
	int data;
	struct BTree *lChild;
	struct BTree *rChild;
};
#define MAX_NODES 		10
struct Stack
{
	int Top;
	struct BTree *items[MAX_NODES];
	
};
#define NODEALLOC (struct BTree*)malloc(sizeof(struct BTree))
struct BTree *GetNewNode(int data)
{
	struct BTree *NewNode;
	
	NewNode = NODEALLOC;
	NewNode->data = data;
	NewNode->lChild = NULL;
	NewNode->rChild = NULL;
	
	return(NewNode);
};

void initstack (struct Stack *ptr);
int isempty(struct Stack *ptr);
int isfull(struct Stack *ptr);
void push (struct Stack *ptr,struct BTree *NodePtr);
int pop(struct Stack *ptr,struct BTree **NodePtr);

void initstack (struct Stack *ptr)
{
	ptr -> Top = -1;	
}

int isempty(struct Stack *ptr)
{
	if (ptr->Top == -1)
		return(1);
	else
		return(0);	
}
  
int isfull(struct Stack *ptr)
{
	if (ptr->Top == MAX_NODES-1)
		return(1);
	else
		return(0);
}

void push (struct Stack *ptr, struct BTree *NodePtr)
{
	if (isfull(ptr))
	{
		printf("stack overflow\n");
	}
	else
	{
		ptr->Top = ptr->Top+1;
		ptr->items[ptr->Top] = NodePtr;
	}
}

int pop(struct Stack *ptr,struct BTree **NodePtr)
{
	int flag;
	if (isempty(ptr))
	{	
		printf("stack underflow\n");
		flag = 0;
	}
	else
	{
		*NodePtr = ptr->items[ptr->Top];
		ptr->Top--;
		flag == -1;
	}
	return(flag);
}

struct BTree *CreateBtree(int n)
{
	struct BTree *current , *Root =NULL , *lChild ,*rChild;
	int cnt=0, data=0;
	struct Stack S1;
	initstack(&S1);
	char ch ='Y' ;
	printf("enter the data for root node\n");
	scanf("%d",&data);
	Root=GetNewNode(data);
	
    current=Root ;
    lChild=rChild=NULL;
    
    printf("current is %d \n",current->data);
    
    cnt=1;
	while(cnt<n)
	{
		
     	printf("does  %d have a left child \n",current->data);
		ch=getche();
		
		if(ch=='Y'||'y')
		{
			printf("enter data of left child\n");
			scanf("%d",&data);
			lChild=GetNewNode(data);
			current->lChild=lChild;
			//	push(&S1,lChild);
			cnt++;
			
		}
		printf("does it  have a right child %d : \n",current->data );
			ch=getche();
			if(ch=='Y'||'y')
			{
			   printf("enter data of right  child \n");
			scanf("%d",&data);
			rChild=GetNewNode(data);
			current->rChild=rChild;
			push(&S1,rChild);
			cnt++;	
			}
		if(current->lChild)
		    current=lChild;
		else
		 pop(&S1,&current);
	}
	return(Root);
		 
		
	}

struct BTree *Delbtree(struct BTree *Root)
{
	if(Root)
	{
		if(Root->lChild)
		Root->lChild=Delbtree(Root->lChild);
		if(Root->rChild)
		Root->rChild=Delbtree(Root->rChild);
		
		free(Root);
		Root=NULL;
		printf("tree deleted");
		
	}
	return(Root);
	
	
}

int CountNode(struct BTree *T)
{
	int cnt=0;
	if(T)
	{
		cnt++;
		cnt+=CountNode(T->lChild);
		cnt+=CountNode(T->rChild);
		
	}
	return(cnt);
}

void Reclnorder(struct BTree *Root)
{
	if(Root)
	{
		Reclnorder(Root->lChild);
		printf("%d\t",Root->data);
		Reclnorder(Root->rChild);
		
	}
}

void 	main(void)
{
	struct BTree *Root;
	
	Root=CreateBtree(2);
	Reclnorder(Root);  //Display a btree
	Root=Delbtree(Root);
	Reclnorder(Root);    //tree is not displayed as the tree is deleted;
	
	getch();
	
	
//	Test();
	
}
