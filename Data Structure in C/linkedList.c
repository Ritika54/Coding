#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL;

void insertAtBegin(int key){
    struct node *temp;
    temp =(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory cannot be allocated");
        return;
    }
    temp->data=key;
    temp->next=first;
    first=temp;
}

void display(){
    if(first==NULL){
        printf("Linked list is empty");
        return;
    }
    //there is atleast one element
    struct node *temp=first;
    
    do{
        printf("1  : %d\t",temp->data);
        temp=temp->next;
    }while(temp!=NULL);
}

void search(int key){
    //print index every time it is encountered, print frequency
    if(first==NULL){
        printf("Linked List is empty");
        return;
    }
    int index=1, count=0;
    struct node *temp=first;
    while(temp!=NULL){
        if(temp->data == key){
            printf("Position of %d is %d\n",key,index);
            count++;
        }
        index++;
        temp=temp->next;
    }
    printf("Frequency of %d is %d\n",key,count);
}

void insertAtEnd(int key){
    //first create a newNode 
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=key;
    //if Linked List is empty
    if(first==NULL){
        newNode->next=NULL;
        first=newNode;
        return;
    }
    //if there is atleast one element
    struct node *temp=first;
    while(temp->next!=NULL){
        //printf("data : %d address : %p\n",temp->data,temp->next);
        temp=temp->next;
    }
    temp->next=newNode;
    //printf("data : %d address : %p\n",temp->data,temp->next);

    newNode->next=NULL;
    //printf("data : %d address : %p\n",temp->data,temp->next);    
}

int main()
{
    int n,key;
    while(1){
        printf("\nPress 1 to insert first element in Linked List\n");
        printf("Press 2 to display Linked List\n");
        printf("Press 3 to delete element from Linked List\n");
        printf("Press 4 to search for element in Linked List\n");
        printf("Press 5 to reverse Linked List\n");
        printf("Press 6 to find loop within linked list\n");
        printf("Press 7 to insert as last element in linked list\n");
        printf("Press any other key to exit\n");
        scanf("%d",&n);
        switch(n){
            case 1: printf("Enter a value ");
                    scanf("%d",&key);
                    insertAtBegin(key);
                    break;
                    
            case 2: display();
                    break;
            case 3:break;
            case 4: printf("Enter a value ");
                    scanf("%d",&key);
                    search(key);
                    break;
            case 5:break;
            case 6:break;
            case 7: printf("Enter a value ");
                    scanf("%d",&key);
                    insertAtEnd(key);
                    break;
            
            default:return 0;
        }
    }
    return 0;
}
