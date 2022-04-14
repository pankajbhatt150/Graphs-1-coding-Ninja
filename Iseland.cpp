Islands
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
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
1 
  //Solution
  include<bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>>&edges, vector<bool>&visited, int sv){
    int n=visited.size();
    visited[sv]=true;   
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[i][sv])DFS(edges, visited, i);
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    vector<bool> visited(n, false);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(edges, visited, i);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
