#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	//payload
	int num;

	//reference to next node
	struct node* next;
}nodeT;

void main() {
	nodeT* headerPtr = NULL;
	int menuOpt;
	nodeT* temp;

	//display a choice menu
	printf("Press 1 to add to the start of the list\n");
	printf("Press 2 to display the list\n");
	printf("Press -1 to Exit\n");
	scanf("%d", &menuOpt);

	while (menuOpt != -1)
	{
		if (menuOpt == 1) {
			printf("Add node to the start\n");

			//creating and populating the node
			temp = (nodeT*)malloc(sizeof(nodeT) * 1);
			printf("please enter the number you would like to add:\n");
			scanf("%d", &temp -> num);

			//connecting the node to the list
			temp->next = headerPtr;
			headerPtr = temp;
		}
		else if (menuOpt == 2) {
			temp = headerPtr;
			while (temp != NULL)
			{
				printf("\nthe value of the node is: %d\n", temp -> num);
				temp = temp->next;
			}
		}

		printf("\nPress 1 to add to the start of the list\n");
		printf("Press 2 to display the list\n");
		printf("Press -1 to Exit\n");
		scanf("%d", &menuOpt);
	}
}