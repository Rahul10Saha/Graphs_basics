#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

void addEdge(vector <pair<int, int> > adj[], int u,
                                     int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void dijkistra_using_PQ(int V, vector<iPair> adj[], int source)
{
    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
    vector<int> dist(V,INT_MAX);

    dist[source] = 0;
    pq.push({0,source});

    while(!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node])
        {
            int edgeweight = it.second;
            int adjnode = it.first;
            if(dis+edgeweight < dist[adjnode])
            {
                dist[adjnode] = dis + edgeweight;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }

    for(int i=0;i<dist.size();i++)
        cout<<"The distance of node"<<i<<"from"<<source<<"is"<<dist[i]<<endl;
}

void dijkistra_using_set(int V, vector<iPair> adj[], int source)
{
    set<iPair> s;
    vector<int> distance(V,INT_MAX);

    s.insert({0,source});
    distance[source]=0;

    while(!s.empty())
    {
        auto it = *(s.begin());
        int node = it.second;
        int dis = it.first;
        s.erase(it);


        for(auto it: adj[node])
        {
            int adjnode = it.first;
            int adjweight = it.second;
            if(dis+adjweight<distance[adjnode])
            {
                if(distance[adjnode]!=INT_MAX)
                {
                    s.erase({distance[adjnode],adjnode});
                }
                distance[adjnode] = dis + adjweight;
                s.insert({distance[adjnode],adjnode});
            }
        }
    }

    for(int i=0;i<distance.size();i++)
        cout<<"The distance of node"<<i<<"from"<<source<<"is"<<distance[i]<<endl;

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

    dijkistra_using_PQ(V,adj,0);
    dijkistra_using_set(V,adj,0);
    return 0;
}
