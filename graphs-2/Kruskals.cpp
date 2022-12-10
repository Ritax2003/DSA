/*
Kruskal's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5
*/
#include <iostream>
#include<algorithm>
using namespace std;
class edges{
    public:
    int src,dest,wt;
};
bool compare(edges e1,edges e2){
    return e1.wt<e2.wt;
}
int findp(int *parent,int v){
  if (v == parent[v]){
    return v;
  }
    return findp(parent,parent[v]);
}
void kruskals(edges *input,int n,int e){
    sort(input,input+e,compare);
    int *parent=new int[n];
    for(int i =0;i<n;i++){
        parent[i]=i;
    }
    edges *output=new edges[n-1];
    int count=0,i=0;
    while(count!=n-1){
        edges curr=input[i];
        int sp = findp(parent,curr.src);
        int dp = findp(parent,curr.dest);
        if(sp!=dp){
            output[count]=curr; count++;
            parent[sp]=dp;
        }
        i++;
    }
    for(int i =0;i<n-1;i++){
        if(output[i].src<output[i].dest){
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].wt<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].wt<<endl;
        }
    }
}
int main() {
   int n,e;
   cin>>n>>e;
   edges *input = new edges[e];
   for(int i=0;i<e;i++){
       int s,d,w;
       cin>>s>>d>>w;
       input[i].src=s;
       input[i].dest=d;
       input[i].wt=w;
   }
   kruskals(input,n,e);
}