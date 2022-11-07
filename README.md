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
