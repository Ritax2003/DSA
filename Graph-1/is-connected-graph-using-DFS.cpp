/*Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/
#include <iostream>
using namespace std;
void dfs(bool **graph,int v,bool *visited,int cv){
    visited[cv]=true;
    for(int i =0;i<v;i++){
        if(graph[cv][i] && !visited[i]){
            dfs(graph,v,visited,i);
        }
    }
}
bool isConnected(bool **graph,int v){
    bool * visited = new bool[v];
    dfs(graph,v,visited,0);
    for(int i =0;i<v;i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
   delete[] visited;
}
int main() {
    int v,e;
    cin>>v>>e;
    bool **graph = new bool*[v];
    for(int i =0;i<v;i++){
        graph[i]=new bool[v];
    }
    for(int i =0;i<e;i++){
        int a ,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    cout<<((isConnected(graph,v))?"true":"false");
    for(int i =0;i<v;i++){
        delete[] graph[i];
    }
    delete[] graph;
}