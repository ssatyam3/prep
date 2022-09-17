#include <bits/stdc++.h>
using namespace std;

void printBfs(int **edges, int sv, int n, bool *visited){

    queue<int> pv;
    pv.push(sv);
    visited[sv] = true;

    while(!pv.empty()){
        int val = pv.front();
        pv.pop();
        cout << val << " ";
        for(int i=0 ; i<n ; i++){
            if(val == i)
                continue;
            if(edges[val][i] == 1 && !visited[i]){
                pv.push(i);
                visited[i] = true;
            }
        }
    }
}

void bfs(int **edges, int n){
    bool *visited = new bool[n];
    for(int i=0 ; i<n ; i++)
        visited[i]  = false;

    for(int i=0 ; i<n ; i++){
        if(!visited[i]){
            printBfs(edges,i,n,visited);
        }
    }
}

void printDfs(int **edges, int sv, int n, bool *visited){

    cout << sv << " ";
    visited[sv] = true;

    for(int i=0 ; i<n ; i++){
        if(edges[sv][i]==1 && !visited[i]){
            printDfs(edges,i,n,visited);
        }
    }
}

void dfs(int **edges, int n){
    bool *visited = new bool[n];
    for(int i=0 ; i<n ; i++){
        visited[i] = false;
    }

    for(int i=0 ; i<n ; i++){
        if(!visited[i]){
            printDfs(edges,i,n,visited);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n,e;
    cin >> n >> e;

    int **edges = new int*[n];

    for(int i=0 ; i<n ; i++){
        edges[i] = new int[n];
        for(int j=0 ; j<n ; j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0 ; i<n ; i++){
        int fv,sv;
        cin >> fv >> sv;
        edges[fv][sv] = 1;
        edges[sv][fv] = 1;
    }

    cout << "dfs : ";
    dfs(edges,n);
    cout <<  endl;
    cout << "bfs : ";
    bfs(edges,n);

   return 0;
}
