#include<stdio.h>
#include<limits.h>

#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;
void enqueue(int val){
    if(rear==SIZE-1){
        printf("queue overflow");
        return;
    }
    if(front == -1)
        front++;
    
    rear = (rear+1) % SIZE;
    queue[rear]=val;
}
int  dequeue(){
    if(rear==-1){
        printf("queue underflow");
        return INT_MIN;
    }
    int val=queue[rear];
    if(front==rear)
        front=rear=-1;
    else
        front= (front + 1) % SIZE;

    return val;
}

int isFull(){
    if((rear + 1) % SIZE == front)
        return 1;
    return 0;
}

int isEmpty(){
    if(front == -1)
        return 1;
    return 0;
}

void reverse(){
    if(!isEmpty()){
        int val = dequeue();
        reverse();
        enqueue(val);
    }
}

void display(){
    if(front == -1)
        return;
    int i;
    for(i=front;i!=rear;i=(i+1)%SIZE)
        printf("%d",queue[i]);
    printf("%d",queue[i]);
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    reverse();
    display();
    return 0;
}