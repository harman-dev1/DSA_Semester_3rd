#include <iostream>
using namespace std;
#define SIZE 10
#define PRIME 7

int hash_fn(int key) {
    return (key % SIZE);
}

int prime_hash(int key) {
    return (PRIME - (key % PRIME));
}

int double_hashing(int A[], int key) {
    int i = 0;
    int index = hash_fn(key);
    int prime_index = prime_hash(key);
    while (A[(index + (i * prime_index)) % SIZE] != 0) {
        i += 1;
    }
    return (index + (i * prime_index)) % SIZE;
}

void insert(int A[], int key) {
    int index = hash_fn(key);
    if (A[index] != 0) {
        index = double_hashing(A, key);
    }
    A[index] = key;
}

int search(int A[], int key) {
    int index = hash_fn(key);
    int i = 0;
    int prime_index = prime_hash(key);
    while(A[(index + (i * prime_index)) % SIZE] != key) {
        i += 1;
        if((index + (i * prime_index)) % SIZE == index) {
            return -1;
        }
    }
    return ((index + (i * prime_index)) % SIZE);    
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
    insert(A, 25);
    insert(A, 5);
    insert(A, 15);
    insert(A, 35);
    insert(A, 95);
    cout << "Successfull Search" << endl;
    int key = 5;
    int value = search(A,key);
    cout << "key :" << key << ", index:" << value << endl;
    key = 25;
    value = search(A,key);
    cout << "key :" << key << ", index :" << value << endl;
    key = 15;
    value = search(A,key);
    cout << "key :" << key << ", index :" << value << endl;
    key = 35;
    value = search(A,key);
    cout << "key :" << key << ", index :" << value << endl;
    key = 95;
    value = search(A,key);
    cout << "key :" << key << ", index :" << value << endl;

    cout << "UNsuccessfull Search" << endl;
    key = 995;
    value = search(A,key);
    cout << "key :" << key << ", Value :" << value << endl;

    print(A);
}