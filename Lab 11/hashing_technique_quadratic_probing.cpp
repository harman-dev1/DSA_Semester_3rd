#include <iostream>
using namespace std;
#define SIZE 10

int hash_fn(int key) {
    return key % SIZE;
}

int quadratic_probing(int A[], int key) {
    int i = 0;
    int index = hash_fn(key);
    while (A[(index + (i*i)) % SIZE] != 0) {
        i += 1;
    }
    return ((index + i*i) % SIZE);
}

void insert(int A[], int key) {
    int index = hash_fn(key);
    if (A[index] != 0) {
        index = quadratic_probing(A, key);
    }
    A[index] = key;
}

int search(int A[], int key) {
    int index = hash_fn(key);
    int i = 0;
    while(A[(index+i*i) % SIZE] != key) {
        i += 1;
        if(i >= 10) {
            return -1; 
        }
    }
    return (index+i) % SIZE;    
}

void print(int A[]) {
    for(int i = 0;i <10; i++) {
        if(A[i] != 0) {
            cout << "index :" << i << ", " << A[i] << " ";
        }
    }
    cout << endl;
}

main() {
    int A[10];
    for (int i = 0; i < 10; i++) {
        A[i] = 0;
    }
    insert(A, 19);
    insert(A, 9);
    insert(A, 29);
    insert(A, 39);

    cout << "Successfull Search" << endl;
    int key = 39;
    int value = search(A,key);
    cout << "key :" << key << ", Value :" << value << endl;
    key = 9;
    value = search(A,key);
    cout << "key :" << key << ", Value :" << value << endl;
    key = 19;
    value = search(A,key);
    cout << "key :" << key << ", Value :" << value << endl;
    key = 29;
    value = search(A,key);
    cout << "key :" << key << ", Value :" << value << endl;

    cout << "UNsuccessfull Search" << endl;
    key = 319;
    value = search(A,key);
    cout << "key :" << key << ", Value :" << value << endl;

    print(A);
}