#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


typedef pair<int, int> iPair;


void addEdge(vector <pair<int, int> > adj[], int u,
                                     int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}


void primMST(int V,vector<iPair> adj[])
{
    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
    vector<int> vis(V,0);
    pq.push({0,0});
    int sum =0;
    while(!pq.empty())
        {

            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if(vis[node]==1)continue;
            vis[node] =1;
            sum+=wt;
            for(auto it: adj[node])
            {
                int adjnode = it.first;
                int adjwt = it.second;
                if(!vis[adjnode])
                pq.push({adjwt,adjnode});
            }
        }
    cout<<"The sum is"<<sum;
}

int main()
{
    int V = 7;
    vector<iPair > adj[V];
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 1, 4, 1);
    addEdge(adj, 1, 5, 4);
    addEdge(adj, 2, 4, 3);
    addEdge(adj, 2, 6, 7);
    addEdge(adj, 3, 4, 5);
    addEdge(adj, 3, 6, 8);
    addEdge(adj, 4, 5, 9);


    primMST(V,adj);

    return 0;
}
