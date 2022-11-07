# Graphs_basics
Let's start with BFS and DFS traversal of a graph. 

## BFS Traversal

- Using Queue
- Intuition : BFS is analogous to level order traversal. 

void bfsOfGraph(int node, vector<int> adj[], int vis[], vector<int> &ans) {

```cpp
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

