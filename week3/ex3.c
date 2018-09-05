#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
	struct node_struct *next;
	int data;
} node;

typedef struct linked_list_struct {
	node *head;
} linked_list;

void print_list(linked_list *list) {
	node *curr = list->head;
	while(curr != NULL){
		printf("%d ",curr->data);
		curr = curr->next;
	}
	printf("\n");
}

void insert_node(linked_list *list, int data) {
	if(list->head == NULL){
		list->head = malloc(sizeof(node));
		list->head->data = data;
		list->head->next = NULL;
	}else{
		node *curr = list->head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = malloc(sizeof(node));
		curr->next->data = data;
		curr->next->next = NULL;
	}
}

void delete_node(linked_list *list, int index) {
	node *curr = list->head;
	for(int i = 1; i < index && curr->next != NULL; i++ ){
		curr = curr->next;
	}
	if(curr->next != NULL){
		node* temp = curr->next->next;
		free(curr->next);
		curr->next = temp;
	}else{
		printf("ERROR: There is no element with index %d\n", index);
	}
}

linked_list* create_list() {
	linked_list *list = (linked_list *)malloc(sizeof(linked_list));
	list->head = NULL;
	return list;
}

int main(){
	linked_list *list = create_list();
	insert_node(list, 10);
	insert_node(list, 20);
	insert_node(list, 55);
	print_list(list);
	delete_node(list, 1);
	print_list(list);
	delete_node(list, 1);
	print_list(list);
	delete_node(list, 1);
	print_list(list);
}
