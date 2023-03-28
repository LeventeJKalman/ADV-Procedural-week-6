#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    int key;

    struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

void displayList();
void insertFirst(int key, int data);
void insertLast(int key, int data);
bool isEmpty();
int length();
struct node* find(int key);
struct node* delete(int key);

void main(){
    int menuOpt = 0, key, data;
    
    while (menuOpt != -1) {
        printf("Press 1 to add to the start of the list\n");
        printf("Press 2 to add to the end of the list\n");
        printf("Press 3 to display the list\n");
        printf("Press 4 to search the list\n");
        printf("Press 5 to delete the list\n");
        printf("Press 6 to display the length of the list\n");
        printf("Press -1 to Exit\n");
        scanf("%d", &menuOpt);

        if (menuOpt == 1) {
            printf("\nWhat is the key value that you want to add at the start of the list?\n");
            scanf("%d", &key);
            printf("What is the data value that you want to add at the start of the list?\n");
            scanf("%d", &data);
            insertFirst(key, data);
            printf("New node has been added at the start!\n");
        }
        else if (menuOpt == 2) {
            printf("\nWhat is the key value that you want to add at the end of the list?\n");
            scanf("%d", &key);
            printf("What is the data value that you want to add at the end of the list?\n");
            scanf("%d", &data);
            insertLast(key, data);
            printf("New node has been added at the end!\n");
        }
        else if (menuOpt == 3) {
            displayList();
        }
        else if (menuOpt == 4) {
            printf("What key are you looking for?\n");
            scanf("%d", &key);
            struct node* found = find(key);
            if (found != NULL) {
                printf("Node found: \n");
                printf("(%d,%d)\n", found->key, found->data);
            }
            else {
                printf("No entry with that key has been found?\n");
            }
        }
        else if (menuOpt == 5) {
            printf("What key do you want to delete?\n");
            scanf("%d", &key);
            struct node* deleted = delete(key);
            if (deleted != NULL) {
                printf("Node deleted: \n");
                printf("(%d,%d)\n", deleted->key, deleted->data);
            }
            else {
                printf("No entry with that key has been found?\n");
            }
        }
        else if (menuOpt == 6) {
            printf("The length is: %d\n", length());
        }
        else if(menuOpt != -1){
            printf("Invalid response. Please enter 1, 2, 3, or -1 to exit!\n");
        }
        printf("\n\n");
    }
}

//display the list
void displayList() {
    struct node* ptr = head;
    printf("\n[ ");

    //start from the beginning
    while (ptr != NULL) {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }

    printf(" ]\n");
}

//insert link at the first location
void insertFirst(int key, int data) {
    //create a link
    struct node* link = (struct node*)malloc(sizeof(struct node));

    link->key = key;
    link->data = data;

    //point it to old first node
    link->next = head;

    //point first to new first node
    head = link;
}

//insert at the end
void insertLast(int key, int data){
    struct node* current = head;

    //set current as last node in the list
    while (current->next != NULL) {
        current = current->next;
    }

    //create a node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    //apply variables
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;

    //add as next to the current
    current->next = newNode;
}

//is list empty
bool isEmpty() {
    return head == NULL;
}

int length() {
    int length = 0;
    struct node* current;

    for (current = head; current != NULL; current = current->next) {
        length++;
    }

    return length;
}

//find a link with given key
struct node* find(int key) {

    //start from the first link
    struct node* current = head;

    //if list is empty
    if (head == NULL) {
        return NULL;
    }

    //navigate through list
    while (current->key != key) {

        //if it is last node
        if (current->next == NULL) {
            return NULL;
        }
        else {
            //go to next link
            current = current->next;
        }
    }

    //if data found, return the current Link
    return current;
}

//delete a link with given key
struct node* delete(int key) {

    //start from the first link
    struct node* current = head;
    struct node* previous = NULL;

    //if list is empty
    if (head == NULL) {
        return NULL;
    }

    //navigate through list
    while (current->key != key) {

        //if it is last node
        if (current->next == NULL) {
            return NULL;
        }
        else {
            //store reference to current link
            previous = current;
            //move to next link
            current = current->next;
        }
    }

    //found a match, update the link
    if (current == head) {
        //change first to point to next link
        head = head->next;
    }
    else {
        //bypass the current link
        previous->next = current->next;
    }

    return current;
}