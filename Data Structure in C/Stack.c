#include<stdio.h>
#include<limits.h>

#define SIZE 5

int stack[SIZE];
int top=-1;

void push(int value){

    if(top==SIZE-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=value;

}

void pop(){

    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    top--;

}

int peek(){

    if(top==-1)
        return INT_MIN;

    return stack[top];

}

int isEmpty(){

    if(top==-1)
        return 1;

    return 0;

}

int isFull(){

    if(top==SIZE-1)
        return 1;

    return 0;

}

void display(){

    if(isEmpty()){
        printf("Stack is Empty");
        return;
    }

    for(int i=top;i>=0;i--)
        printf("%d\n",stack[i]);

}

int main(){

    for(int i=10;i<=60;i+=10){
        printf("%d\t",peek());
        push(i);
    }
     
    display();
    
    for(int i=1;i<=6;i++)
        pop();

    return 0;
}