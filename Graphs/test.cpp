// a server network is represented as a tree of g_nodes servers indexed from 1 to g_nodes and g_nodes-1 edges where the ith edges connect the servers g_from[i] and g_to[i]. the transfer time between any two connected servers is 1 unit.

// given the graph g, find the maximum time taken to transfer the data between any two servers in the system

int getMaxTime(int g_nodes, vector<int> g_from, vector<int> g_to){
    vector<vector<int>> adj(g_nodes+1);
    for(int i=0;i<g_from.size();i++)
    {
        adj[g_from[i]].push_back(g_to[i]);
        adj[g_to[i]].push_back(g_from[i]);
    }
    
    vector<int> dist(g_nodes+1,INT_MAX);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int it:adj[t])
        {
            if(dist[it]>dist[t]+1)
            {
                dist[it]=dist[t]+1;
                q.push(it);
            }
        }
    }
    
    int res=0;
    for(int i=1;i<=g_nodes;i++)
    {
        if(dist[i]==INT_MAX)
            return -1;
        res=max(res,dist[i]);
    }
    return res;
}

// Path: Graphs\test.cpp
// Compare this snippet from Graphs\BFS.cpp:
// class Solution {
// public:
//     vector<int> bfsOfGraph(int V, vector<int> adj[]) {
//         vector<int> res;
//         vector<bool> vis(V,false);
//         queue<int> q;
//         q.push(0);
//         vis[0]=true;
//         while(!q.empty())
//         {
//             int t=q.front();
//             q.pop();
//             res.push_back(t);
//             for(int it:adj[t])
//             {
//                 if(!vis[it])
//                 {
//                     q.push(it);
//                     vis[it]=true;
//                 }
//             }
//         }
//         return res;
//     }
// };
// given a directed graph. the task is to do breadth first traversal of this graph starting from 0.

// note: one can move from node u to node v only if there's an edge from u to v and find the bfs traversal of the graph starting from the 0th vertex, from left to right according to the graph. also, you should only take nodes directly or indirectly connected from node 0 in consideration.

vector<int> bfsOfGraph(int V, vector<int> adj[]){
    vector<int> res;
    vector<bool> vis(V,false);
    queue<int> q;
    q.push(0);
    vis[0]=true;
    while(!q.empty     vector<vector<int>> adj(g_nodes+1);
    for(int i=0;i<g_from.size();i++)
    {
        adj[g_from[i]].push_back(g_to[i]);
        adj[g_to[i]].push_back(g_from[i]);
    }
    
    vector<int> dist(g_nodes+1,INT_MAX);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int it:adj[t])
        {
            if(dist[it]>dist[t]+1)
            {
                dist[it]=dist[t]+1;
                q.push(it);
            }
        }
    }
    
    int res=0;
    for(int i=1;i<=g_nodes;i++)
    {
        if(dist[i]==INT_MAX)
            return -1;
        res=max(res,dist[i]);
    }
    return res;
}


