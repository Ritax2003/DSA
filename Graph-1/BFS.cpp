#include <iostream>
#include<queue>
using namespace std;
void bfs(int **edges,int n,int start,bool *visited){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(q.empty()!=1){
        int node =  q.front();
        q.pop();
        cout<<node<<" ";
        
        for(int i =0;i<n;i++){
            if(edges[node][i] && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
int main() {
    int V,E;
    cin>>V>>E;
    int **edges = new int*[V];
    for(int i =0;i<V;i++){
        edges[i]=new int[V];
        for(int j =0;j<V;j++){
            edges[i][j]=0;
        }
    }
    for(int i =0;i<E;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    bool *visited = new bool[V];
    for(int i =0;i<V;i++){
        visited[i]=false;
    }
    for(int i =0;i<V;i++){
        if(visited[i]==false){
            bfs(edges,V,i,visited);
        }
    }
    for(int i =0;i<V;i++){
        delete [] edges[i];
    }
    delete[] edges;
    return 0 ;
}