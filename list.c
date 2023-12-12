#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lNode{
	char info[10];
	struct lNode* next;
	struct lNode* prev;
};


struct lNode* lCreateNode(char data[10]){
	struct lNode* newNode = (struct lNode*)malloc(sizeof(struct lNode));
	if (newNode == NULL){
		return 0;
	}

	strcpy(newNode->info, data);
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void insertInOrder(struct lNode** head, char data[10]) {
    struct lNode* newNode = lCreateNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }
		
		if (strcmp((*head)->info,data) > 0){
			newNode->next = *head;
			(*head)->prev = newNode;
			*head = newNode;
			return;
		}

		struct lNode* current = *head;

		while(current->next != NULL && strcmp(current->next->info,data) < 0) {
			current = current->next;
		}
		
		newNode->next = current->next;
		newNode->prev = current;
		if(current->next != NULL)
			current->next->prev = newNode;
		current->next = newNode;
}

int main(){
	struct lNode* head = NULL;	
	struct lNode* current = head;
	while (current != NULL){
		printf("%s\n", current->info);
		current = current->next;
	}


	return 0;
}
