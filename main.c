#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintr.h"
#include "utils.h"


int main(){
	struct Node* root = NULL;
	int treeNodes = 0;
	int listNodes = 0;
	root = loadTree(root, &treeNodes);
	
	execMode(root, treeNodes, listNodes);
	return 0;
}
