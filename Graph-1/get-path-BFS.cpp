/*Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists).
 Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
*/
#include <iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int>* getBFSpath(bool **graph,int v,int start,int end){
    queue<int> pendingv;
    bool *visited = new bool[v];
    pendingv.push(start);
    visited[start]=true;
    bool pathfound=false;
    vector<int> parent(v,-1);
    while(!pendingv.empty() && !pathfound){
        int front = pendingv.front();
        pendingv.pop();
        for(int i =0;i<v;i++){
            if(graph[front][i] && !visited[i]){
                parent[i]=front;
                pendingv.push(i);
                visited[i]=true;
                if(i==end){
                    pathfound=true;
                    break;
                }
            }
        }
    }
    delete[] visited;
    if(!pathfound) return NULL;
    vector<int> *output = new vector<int>();
    int curr = end;
    output->push_back(end);
    while(curr!=start){
        curr=parent[curr];
        output->push_back(curr);
    }
    return output;
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
    int start,end;
    cin>>start>>end;
    vector<int> *output = getBFSpath(graph,v,start,end);
    if(output!=NULL){
        for(int i =0;i<output->size();i++){
            cout<<output->at(i)<<" ";
        }
        delete output;
    }
    for(int i =0;i<v;i++){
        delete[] graph[i];
    }
    delete[] graph;
}