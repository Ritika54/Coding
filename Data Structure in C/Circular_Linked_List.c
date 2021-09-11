#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL;

//|data|address of next|(it's own address)
//|10|200|(100) -> |20|300|(200) 
//    \                    /
//        |30|100|(300)                                                   
//first=100
//here we want to insert at first
//|data|address of next|(it's own address)
//|40|100|(400) -> |10|200|(100) -> |20|300|(200) 
//    \                          /
//        |30|400|(300)                                                   
//first=400

void insertAtBegin(int key){//40
    struct node *new;
    new =(struct node*)malloc(sizeof(struct node));//400
    if(new==NULL){
        printf("Memory cannot be allocated");
        return;
    }
    new->data=key;//40
    if(first==NULL){
        first=new;
        new->next=first;
        return;
    }
    //we need to find last element, since we are inserting at first so last->next needs to changed to this first
    struct node *last=first;//100
    while(last->next!=first){//last->next=200/300/100(out of loop)
        last=last->next;//200/300
    }
    new->next=first;//100
    fisrt=new;//400
    last->next=new;//400
}

void display(){
    if(first==NULL){
        printf("Linked list is empty");
        return;
    }
    //there is atleast one element
    struct node *temp=first;
    
    do{
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=first);
}

void search(int key){
    //print index every time it is encountered, print frequency
    if(first==NULL){
        printf("Linked List is empty");
        return;
    }
    int index=1, count=0;
    struct node *temp=first;
    while(temp->next!=first){
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
//|data|address of next|(it's own address)
//|10|200|(100) -> |20|300|(200) -> |30|400|(300)
//    \                             /
//             |40|100|(400)                                                   
//first=100

void insertAtEnd(int key){
    //first create a newNode 
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=key;
    //if Linked List is empty
    if(first==NULL){
        newNode->next=newNode;
        first=newNode;
        return;
    }
    //if there is atleast one element
    struct node *last=first;//100
    while(last->next!=first){//last->next=200/300/100(out of loop)
        last=last->next;//last(after assignment)=200/300
    }
    temp->next=newNode;//400
    newNode->next=first;//100
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

int main()
{
    int n,key;
    while(1){
        printf("\nPress 1 to insert first element in Linked List\n");
        printf("Press 2 to display Linked List\n");
        printf("Press 3 to delete element from Linked List\n");
        printf("Press 4 to search for element in Linked List\n");
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
            case 7: printf("Enter a value ");
                    scanf("%d",&key);
                    insertAtEnd(key);
                    break;
            
            default:return 0;
        }
    }
    return 0;
}
