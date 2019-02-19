#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void dfs(int);
 vector<int> adj[100];
 bool visited[100]={false};

int main()
{
    int n,b,a;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    int x;
    cin>>x;
    dfs(x);
}
void dfs(int s)
{

  if (visited[s])
  {return;}
visited[s] = true;
cout<<s<<"\t";
//int c=0;
//cout<<"for"<<s<<"\t";
//cout<<"adjacents are"<<endl;
vector<int>::iterator i;
for (i=(adj[s]).begin();i!= (adj[s]).end();i++) {
        //c++;
  //  cout<<*i<<endl;
        //if(c==1)
dfs(*i);
}

}
