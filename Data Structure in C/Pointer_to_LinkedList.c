#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main()
{
    struct node *n1,*n2,*n3;
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    //n1->data is same as (*n1).data
    n1->data=10;
    n2->data=20;
    n3->data=30;
    //cannot use *n2 because n1->next expects arguement of type struct node* and *n2 would be of type struct node
    n1->next=n2;
    n2->next=n3;
    n3->next=NULL;
    printf("data %d address %p\n",n1->data,n1->next);
    printf("data %d address %p\n",n2->data,n2->next);
    printf("data %d address %p\n",n3->data,n3->next);
    return 0;
}
