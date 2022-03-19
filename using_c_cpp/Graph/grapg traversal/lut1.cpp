#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n,b,a;
    cin>>n;
    vector<int> adj[100];
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    queue<int> q;//taking queue that will contain all nodes
    bool visited[100]={false};
    int distance[100]={0};//for maintaining distances of node from the starting node//
    int x;
    cin>>x;//taking input for starting node//
    visited[x] = true;//an array to count visiting//
    distance[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        cout<<"NODE-"<<s<<"\tDISTANCE"<<distance[s]<<endl;
        vector<int>::iterator i;
          for (i=(adj[s]).begin();i!= (adj[s]).end();i++)
             {
               if (visited[*i]) continue;
               visited[*i] = true;
               distance[*i] = distance[s]+1;
               q.push(*i);
             }
     }


}

