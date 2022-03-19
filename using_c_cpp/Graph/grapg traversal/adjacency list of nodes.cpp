#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n,nodes,b,a;
    cin>>n>>nodes;
    vector<int> adj[10];
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
   // for(std::vector<int>::iterator it=adj.begin();it!=adj.end();++it)
   //bool v[nodes]={false};
   queue<int> q;
    bool visited[nodes]={false};
    int distance[nodes];
    int x;
    cin>>x;
   visited[x] = true;
   distance[x] = 0;
    q.push(x);
    while (!q.empty()) {
     int s = q.front(); q.pop();
       cout<<s<<endl;
            for (int u=1;u<=adj[s].size();u++) {
       if (visited[u]) continue;
         visited[u] = true;
         distance[u] = distance[s]+1;
          q.push(u);
         }
     }


}
