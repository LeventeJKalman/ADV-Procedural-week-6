#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	//payload
	int num;

	//reference to next node
	struct node* NEXT;
}nodeT;

void main() {
	nodeT* headerPtr = NULL;
	int menuOpt;
	nodeT* temp;

	//display a choice menu
	printf("Press 1 to add to the start of the list\n");
	printf("Press 2 to add to the end of the list\n");
	printf("Press 3 to display the list\n");
	printf("Press -1 to Exit\n");
	scanf("%d", &menuOpt);

	while (menuOpt != -1)
	{
		if (menuOpt == 1)
		{
			printf("Add node at the start\n");
			//Creating and populating the node
			temp = (nodeT*)malloc(sizeof(nodeT*) * 1);
			printf("Please enter the node number\n");
			scanf("%d", &temp->num);
			//Connecting the node to the list
			temp->NEXT = headerPtr;
			headerPtr = temp;
		}
		//adding to the end of the list
		else if (menuOpt == 2) {
			printf("");
		}
		else if (menuOpt == 3) {
			temp = headerPtr;
			while (temp != NULL)
			{
				printf("\nthe value of the node is: %d\n", temp -> num);
				temp = temp->NEXT;
			}
		}

		printf("\nPress 1 to add to the start of the list\n");
		printf("Press 2 to add to the end of the list\n");
		printf("Press 3 to display the list\n");
		printf("Press -1 to Exit\n");
		scanf("%d", &menuOpt);
	}
}