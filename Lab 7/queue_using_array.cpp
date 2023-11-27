#include<iostream>
using namespace std;
#define n 5
class Queue {
    int* arr;
    int head;
    int tail;
    public:
    Queue() {
        arr = new int[n];
        head = -1;
        tail = -1;
    }
    void ENQUEUE(int);
    void PEEK();
    void DEQUEUE();
    void is_full();
    bool is_empty();
};
void Queue::ENQUEUE(int data) {
    if(tail == n-1) {
        cout << "Queue OverFlow\n" ;
        return;
    }
    tail += 1;
    arr[tail] = data;   
    if(head == -1) {
        head += 1;
    }
}
void Queue::DEQUEUE() {
    if(head > tail || head == -1) {
        cout << "No Element to Dequeue\n";
    }
    head += 1;
}
void Queue::PEEK() {
    if(head > tail || head == -1) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << arr[head];
}
void Queue::is_full() {
    if(tail == n-1) {
        cout << "Queue is Full";
        return;
    }
    else {
        cout << "NOt Full";
        return;
    }
}
bool Queue::is_empty() {
    if(head > tail ) {
        return true;
    }
    return false;
}
main() {
    Queue q1;
    q1.PEEK();
    cout <<"\n" <<q1.is_empty();
}