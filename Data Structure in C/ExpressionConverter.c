
/*
1.POSTFIX expression validation and evaluation

2.PREFIX expression validation and evaluation
Assume that each operand as 1 digit number.

3. reverse a stack(using another stack)

4. reverse a stack(without using another stack)
(using recursion)
*/

#include<stdio.h>
#include<limits.h>
#define SIZE 10

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

void reverse(){
    int arr[SIZE];
    for (int i = 0;isEmpty(); i++)
    {
        arr[i]=peek();
        pop();
    }
    for (int i = 0; i < SIZE; i++)
    {
        stack[i]=arr[i];
    }
}

int postfix(char *str){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='0' && str[i]<='9'){
            push(str[i]-'0');
        }
        else{
            int op2=peek();
            pop();
            int op1=peek();
            pop();
            if(op1 == INT_MIN){
                return -1;
            }  
            
            switch(str[i]){
                case '+':push(op1 + op2);
                        break;
                case '-':push(op1 - op2);
                        break;
                case '*':push(op1 * op2);
                        break;
                case '/':push(op1 / op2);
                        break;

                default: return -1;
            }

        }
    }
    int result =peek();
    pop();
    if(isEmpty())
        return result;
    return -1;

}

int prefix(char *str){
    int length,i;
    for (length = 0; str[length]!='\0'; length++);
        
    for(i=length-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){
            push(str[i]-'0');
        }
        else{
            int op2=peek();
            pop();
            int op1=peek();
            pop();
            if(op1 == INT_MIN){
                return -1;
            }  
            
            switch(str[i]){
                case '+':push(op1 + op2);
                        break;
                case '-':push(op1 - op2);
                        break;
                case '*':push(op1 * op2);
                        break;
                case '/':push(op1 / op2);
                        break;

                default: return -1;
            }

        }
    }
    int result =peek();
    pop();
    if(isEmpty())
        return result;
    return -1;

}

//TO INSERT AT THE BOTTOM OF STACK
void insertBottom(int val){

    if(isEmpty()){
        push(val);
    }
    else{
        int temp=peek();
        pop();
        insertBottom(val);
        push(temp);
    }

}

//STACK REVERSE WITHOUT USING ANOTHER STACK
void stackRev(){

    if(isEmpty())
        return;

    int temp=peek();
    pop();
    stackRev();
    insertBottom(temp);

}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    stackRev();
    display();
    return 0;
}

