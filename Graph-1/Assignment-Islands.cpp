/*Islands

An island is a small piece of land surrounded by water . 
A group of islands is said to be connected if we can reach from any given island to any other island in the same group .
 Given V islands (numbered from 0 to V-1) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 */
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
int getIslands(bool **graph,int v){
    bool *visited = new bool[v];
    int grpcount=0;
    for(int i =0;i<v;i++){
        if(!visited[i]){
            dfs(graph,v,visited,i);
            grpcount++;
        }
    }
    return grpcount;
}
int main() {
   int v,e;
    cin>>v>>e;
    bool **graph = new bool*[v];
    for(int i =0;i<v;i++){
        graph[i]=new bool[v];
    }
    for(int i =0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
        
    }
    cout<<getIslands(graph,v);
    for(int i =0;i<v;i++){
        delete[] graph[i];
    }
    delete[] graph;
}