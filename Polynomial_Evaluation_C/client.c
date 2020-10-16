#include <stdio.h>
#include "poly.h"
int main() {
	int n,x,coeff;
    long long int value;
	List* list = list_initialize();

    scanf("%d", &n);
    for(int i=0;i<n+1;i++)
    {
        scanf("%d",&coeff);
        insert_at_end(list,coeff);
    }
    scanf("%d",&x);

    value = evaluate(list,x);
    printf("%lld \n",value);
    
    list_destroy(list);
	return 0;
}

List* list_initialize() {
	List* list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->number_of_nodes = 0;
	return list;
}

void list_destroy (List *list)
{
	Node *t, *u=NULL;
	t=list->head;
	while (t != NULL){
		u=t;
		t=t->link;
		free(u);
	}
	free(list);
}
