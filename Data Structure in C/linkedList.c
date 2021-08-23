#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *next;
}*first = NULL;

void insertAtBegin(int key){

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory cannot be allocated\n");
        return;
    }
    temp->data = key;
    temp->next = first;
    first = temp;

}

void insertAtEnd(int key){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data=key;
    newNode->next=NULL;
    
    struct node *temp = first;
    while (temp==NULL){
        temp=newNode;
    }
    
}

void search(int key){
    int count = 0,i=0;
    struct node *temp = first;
    do{
        if(key==temp->data){
            printf("%d Key found at index %d\n",temp->data,i+1);
            count++;
        }
        temp = temp->next;
        i++;
    }while(temp!=NULL);   
    printf("The frequency of key is %d\n",count);
}

void display(){

    if(first == NULL){
        printf("Linked List is Empty\n");
        return;
    }

    //there is at least one element
    struct node *temp = first;
    do {
        printf("%d\t",temp->data);
        temp = temp->next;
    }while(temp!=NULL);

}

int main(){

    int choice,key;
    while(1){

            printf("Press 1 to insert as first element into linked list\n");
            printf("Press 2 to display linked list\n");
            printf("Press 3 to delete element from linked list\n");
            printf("Press 4 to search for element in linked list\n");
            printf("Press 5 to reverse linked list list\n");
            printf("Press 6 to fild loop within linked list\n");
            printf("Press 7 to insert as last element into linked list\n");
            printf("Press any other key to exit\n");
            printf("\n\n\n");

            scanf("%d",&choice);

            switch(choice){
                case 1:printf("Enter element to insert\n");
                       scanf("%d",&key);
                       insertAtBegin(key);
                       break;

                case 2:display();
                        break;

                case 3:

                case 4:printf("Enter element to search\n");
                       scanf("%d",&key);
                       search(key);
                       break;

                case 5:

                case 6:

                case 7:printf("Enter element to insert\n");
                       scanf("%d",&key);
                       insertAtEnd(key);
                       break;

                default: return 0;

            }

            printf("\n\n\n");

    }

    return 0;

}

 

// Assignment: 

// 1. Write the function to search for an element and print the frequency of the element with index position each time it is found.

// 2. Write the function to insert element at the end of the linked list.