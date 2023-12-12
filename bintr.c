#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintr.h"


struct Node {
	char info[10];
	struct Node* left;
	struct Node* right;
};


struct Node* createNode(char data[10]){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));	
	if (newNode == NULL){
		return 0;
	}
	strcpy(newNode->info, data);
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


struct Node* insert(struct Node* root, char data[10], int *counter){
	if (root == NULL) {
	*counter = *counter + 1;
		return createNode(data);
	}
	
	if (strcmp(root->info, data) < 0) {
		root->right = insert(root->right, data, counter);
	}

	if (strcmp(root->info, data) > 0) {
		root->left = insert(root->left, data, counter);
	}

	return root;
}


void preorderTraversal(struct Node* root, int *counter) {
	if (root != NULL){
		printf("%s\n", root->info);
		*counter = *counter + 1;
		preorderTraversal(root->left, counter);
		preorderTraversal(root->right, counter);
	}
}


struct Node* search(struct Node* root, char data[10], int *counter, int *found){
	if (root == NULL){
		return root;
	}

	if(strcmp(root->info, data) == 0){
			*found = 0;
	return root;	
	}

	int comparator = strcmp(root->info, data);
	*counter = *counter + 1;

	if (comparator < 0){
		return search(root->right, data, counter, found);
	} else {
		return search(root->left, data, counter, found);
	}
}
