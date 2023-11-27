#include<iostream>
using namespace std;

void DFS(int m[][7], int i) {
    static int visited[7] {0};
    if(visited[i] == 0) {
        cout << i << " ";
        visited[i] = 1;
        for(int j = 1; j < 7; j++) {
            if(m[i][j] == 1 && visited[j] == 0) {
                DFS(m,j);
            }
        }
    }
}

main() {
    int m[7][7] = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0}, 
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    DFS(m,4);
}