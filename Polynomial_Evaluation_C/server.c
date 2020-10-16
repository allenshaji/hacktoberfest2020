#include "server.h"
void insert_at_end(List *list, int data) 
{
	Node * head=list->head;
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data=data;
    temp->link=NULL;
    if(head==NULL)
    {
        list->head=temp;
        list->number_of_nodes=1;
        return;
    }
    
    while(head->link!=NULL)
    {
        head=head->link;
    }
    head->link=temp;
    list->number_of_nodes=list->number_of_nodes+1;
    return;
}

long long int evaluate(List *list, int x)
{
     Node * head=list->head;
    double sum=0;
    int count=list->number_of_nodes;
    while(head!=NULL)
    {
        int c=list->number_of_nodes;
        sum+=pow(x,c-count)*head->data;
        head=head->link;
        count--;
    }
    return (long long int)sum;
    


}
