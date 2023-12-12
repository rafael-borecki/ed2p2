#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintr.h"


char* readFile() {
	FILE *file = fopen("arq1.txt", "r");
	
	if (file == NULL) {
		exit(EXIT_FAILURE);
	}
	
	fseek(file, 0, SEEK_END);
	long file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	char *text = (char*) malloc(file_size + 1);
	if (text == NULL) {
		exit(EXIT_FAILURE);
	}

	size_t data_read = fread(text, 1, file_size, file);
	if (data_read != file_size) {
		exit(EXIT_FAILURE);
	}
	
	text[file_size] = '\0';

	fclose(file);

	return text;

}

struct Node* loadTree(struct Node* root, int *counter){
	char *text = readFile();
	char *token = strtok(text, "\n");
	while (*token != 'x'){
		root = insert(root, token, counter);
		token = strtok(NULL, "\n");
	}
	struct Node* loaded = root;
	return loaded;
}


void execMode(struct Node* root, int treeNodes, int listNodes){
	char execution_mode[12];
	int preorderCounter = 0;

	int treeSearch = 0;
	int listSearch = 0;
	int searchRes = -1;

	fgets(execution_mode, 11, stdin);
	
	if(execution_mode[0] == '0'){
		printf("NL:%d NA:%d", listNodes, treeNodes);
	}

	if(execution_mode[0] == '1'){
		search(root, execution_mode+2, &treeSearch, &searchRes);
		printf("SL: %d, NL:%d NA:%d", searchRes, listSearch, treeSearch);
	}

	if(execution_mode[0] == '2'){
		
	}

	if(execution_mode[0] == '3'){
		preorderTraversal(root, &preorderCounter);
	}
		
}

