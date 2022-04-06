Code : BFS Traversal
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Note:
1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print the BFS Traversal, as described in the task.
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
0 1 3 2
  // Solution
  #include <iostream>
#include<queue>
using namespace std;

void print(int** edge, int v, int sv,bool* visited)//sv is starting vertices
{
    queue<int> pendingVertices;
    //now make an array to keep track of visited vertices
    // bool* visited = new bool[v];
    // for(int i=0; i<v; i++)
    //     visited[i]=false;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<" ";
        for(int i=0; i<v; i++)
        {
            if(i==currentVertex)
                continue;
            if(edge[currentVertex][i] == 1 && !visited[i])
            {
               pendingVertices.push(i);
               visited[i] = true; 
            }
                
        }
    }
    //now we find if there are any other parts of graph (for )
    for(int i=0;i<v;i++){
        if(!visited[i]){
            print(edge,v,i,visited);
        }
    }
}


int main() {
    int v,e;
    cin>>v>>e;
    if(v==0)
        return NULL;
    if(e==0)
    {
        for(int i=0; i<v; i++)
            cout<<i<<" ";
        return NULL;
    }
    //now make a matrix
    int **edge = new int*[v];
    for(int i =0;i<v;i++)
    {
        edge[i] = new int[v];
        for(int j=0; j<v; j++)
            edge[i][j] = 0;
    }
    //now ask user to give vertices who have edges btw them
    int f,s;//first second
    for(int i=0; i<e; i++)
    {
        cin>>f>>s;
        edge[f][s]=1;
        edge[s][f]=1;
    }
 	bool* visited = new bool[v];
    for(int i=0; i<v; i++)
        visited[i]=false;
    //call print
    print(edge,v,0,visited);
}
