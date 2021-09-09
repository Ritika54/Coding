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
    if(count == 0){
        printf("Element not found");
        return;
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

void delete(int key){
    if(first==NULL){
        printf("linked list is empty");
        return;
    }
    struct node *temp=first,*prev=first;
    if(key==first->data){
        first=first->next;
        free(temp);
        return;
    }
    /*
    struct node *prev=first;
    strct node *temp=first->next;
    while(temp!=NULL){
        if(temp->data == key){
            prev->next=temp->next;
            free(temp);
            printf("%d found and deleted",key);
            return;
        }
        temp=temp->next;
        prev=prev->next;
    }
    printf("Element not found");
    */
    while(temp->data!=key){
            prev=temp;
            temp=temp->next;
            if(temp->next==NULL && temp->data!=key){
                printf("Element not found");
                break;
            }
    }
    if(temp->data==key){
        prev->next=temp->next;
        free(temp);
        return;
    }
}
//|data|address of next|(it's own address)
//|10|200|(100) -> |20|300|(200) -> |30|400|(300) -> |40|NULL|(400)
//first=100
void reverse(){
    if(first==NULL){
        printf("Linked List is empty");
        return;
    }
    if(first->next==NULL){//only one element
        return;
    }
    //more than one element
    struct node *prev=NULL,*ahead=first->next;//ahead=200
    while(ahead!=NULL){//ahead=200,300,400,NULL(out of loop)
        first->next=prev;//first=100/200/300,first->next(earlier)=200/300/400,prev=NULL/100/200,first->next(after assignment)=prev
        prev=first;//prev=100/200/300
        first=ahead;//first=200/300/400
        ahead=ahead->next;//ahead=300/400/NULL
    }
    first->next=prev;//first=400,first->next(earlier)=NULL,prev=300
}

//Finding loop using Flyod's cycle detection algorithm
//|data|address of next|(it's own address)
//|10|200|(100) -> |20|300|(200) -> |30|400|(300) -> |40|500|(400)
//                              \                    /
//                                   |50|200|(500)                        
//first=100
void findLoop(){
    if(first==NULL){
        printf("Linked List is empty");
        return;
    }
    struct node *slow=first,*fast=first;//slow=100,fast=100
    while(slow->next!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;//slow->next=200/300/400/500
        fast=fast->next->next;//fast->next->next=300/500/300/500
        if(slow==fast){//500==500
            printf("LOOP FOUND");
            return;
        }
    }
    printf("Loop Not Found");
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
            case 3: printf("Enter a value ");
                    scanf("%d",&key);
                    delete(key);
                    break;
            case 4: printf("Enter a value ");
                    scanf("%d",&key);
                    search(key);
                    break;
            case 5: reverse();
                    break;
            case 6: findLoop();
                    break;
            case 7: printf("Enter a value ");
                    scanf("%d",&key);
                    insertAtEnd(key);
                    break;
            
            default:return 0;
        }
    }
    return 0;
}
