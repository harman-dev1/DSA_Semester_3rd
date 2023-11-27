#include<iostream>
using namespace std;
#define n 2

class Stack{
    int *arr;
    int top;
    public:
    Stack(){
        top = -1;
        arr = new int[n];
    }
    void Push(int);
    void pop();
    void Top();
    bool Empty();
};
void Stack:: Push(int value){
    if(top == n-1){
        cout << "Stack OverFlow";
        return;
    }
    top += 1;
    arr[top] = value;
}

void Stack::pop(){
    if(top == -1){
        cout << "No Element To POP";
        return;
    }
    top--;
}
void Stack::Top(){
    if(top == -1){
        cout << "Stack is Empty";
        return;
    }
    cout << arr[top];
}

bool Stack::Empty(){
    return top == -1;
}
main(){
    Stack s1;
    s1.Push(6);
    s1.Push(7);
    s1.pop();
    s1.pop();
    s1.Top();
}