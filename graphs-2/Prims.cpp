/*
Code : Prim's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
1 <= Wi <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5
*/
#include <iostream>
#include<climits>
using namespace std;
int findm(int *wt, bool *visited,int n){
    int minvertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] &&(minvertex==-1 || wt[minvertex]>wt[i])){
            minvertex=i;
        }
    }
    return minvertex;
}
void prim(int **edges,int n){
    int *parent = new int[n];
    bool *visited=new bool[n];
    int *wt=new int[n];
    for(int i=0;i<n;i++){
        wt[i]=INT_MAX;
        visited[i]=false;
    }
    wt[0]=0;
    parent[0]=-1;
    for(int i =0;i<n;i++){
        int minvertex = findm(wt,visited,n);
        visited[minvertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minvertex][j]!=0 && !visited[j]){
                if(wt[j]>edges[minvertex][j]){
                    wt[j]=edges[minvertex][j];
                    parent[j]=minvertex;
                }
            }
        }   
    }
    for(int i=1;i<n;i++){
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<wt[i]<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<wt[i]<<endl;
        }
    }

}
int main() {
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];
        for(int i =0;i<n;i++){
            edges[i]=new int[n];
            for(int j=0;j<n;j++){
                edges[i][j]=0;
            }
        }
        for(int i=0;i<e;i++){
            int s,f,w;
            cin>>s>>f>>w;
            edges[s][f]=w;
            edges[f][s]=w;
        }
    prim(edges,n);
}