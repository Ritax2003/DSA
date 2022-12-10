/*Code : Dijkstra's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5*/
#include <iostream>
#include<climits>
using namespace std;
int findm(int *wt,bool *visited,int n){
    int minvertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] &&(minvertex==-1 || wt[minvertex]>wt[i])){
            minvertex=i;
        }
    }
    return minvertex;
}
void dijkstra(int **edges,int n){
    bool *visited = new bool[n];
    int *wt = new int[n];
    for(int i=0;i<n;i++){
        wt[i]=INT_MAX;
        visited[i]=false;
    }
    wt[0]=0;
    for(int i=0;i<n;i++){
        int minvertex=findm(wt,visited,n);
        visited[minvertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minvertex][j]!=0 && !visited[j]){
                int dist =edges[minvertex][j]+wt[minvertex];
                if(wt[j]>dist){
                    wt[j]=dist;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<wt[i]<<endl; 
    }
}
int main() {
    int n,e;
    cin>>n>>e;
    int **edges =new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i =0;i<e;i++){
        int s,f,w;
        cin>>s>>f>>w;
        edges[s][f]=w;
        edges[f][s]=w;
    }
    dijkstra(edges,n);
}