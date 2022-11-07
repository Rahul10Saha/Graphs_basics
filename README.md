# Graphs_basics
Let's start with BFS and DFS traversal of a graph. 

## BFS Traversal

- Using Queue
- Intuition : BFS is analogous to level order traversal. 
```cpp
void bfsOfGraph(int node, vector<int> adj[], int vis[], vector<int> &ans) {
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    
    vector<int> BFS(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])                     //Even if the bfsOfGraph finishes for one component, the loop will continue till V, thus providing a traversal for another component as well.
                bfsOfGraph(i,adj,vis,ans);  
        }
        return ans;
    }
```

- Time Complexity: O(N) + O(2E) //2E because the graph is undirected
- The BFS always works for the disconnected components as well.


## DFS Traversal
- Using: Recursion
- Intuition: Continous traversal from one node's adjacency node to next adjacency node's adjacency node and so on. 

```cpp
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1;
        ls.push_back(node);
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, ls);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int start = 0;
        vector<int> ls;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                dfs(i,adj,vis,ls);
        }
        return ls;
    }
```
- Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.
- Space Complexity: O(3N) //Queue, vis array and dfs stack space.
- Works for disconnected graphs as well.


## Code using the concept of OOPs
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1;
        ls.push_back(node);
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, ls);
            }
        }
    }
    void bfsOfGraph(int node, vector<int> adj[], int vis[], vector<int> &ans) {

        vis[node] = 1;
        queue<int> q;
        q.push(node);
        //vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        //return ans;
    }
public:

    vector<int> BFS(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                bfsOfGraph(i,adj,vis,ans);
        }
        return ans;
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int start = 0;
        vector<int> ls;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                dfs(i,adj,vis,ls);
        }
        return ls;
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector <int> adj[6];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector <int> ans1 = obj.BFS(5, adj);
    vector <int> ans2 = obj.dfsOfGraph(5, adj);
    cout<<"\n BFS Traversal is\n";
    printAns(ans1);
    cout<<endl;
    cout<<"\n DFS Traversal is\n";
    printAns(ans2);

    return 0;
}
```

# Prims's Algorithm

![image](https://user-images.githubusercontent.com/65001893/200225206-7862418f-2c25-4f67-a802-fc3f915d8ab0.png)

