#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void dfs(int);
 vector<int> adj[200];
 bool visited[200]={false};

int main()
{
    int n,b,a,nod[200],ind=0,q;
    cin>>n>>q;
    int f=0,temp=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(a!=temp)
            f=0;
        if(f==0)
        {
            nod[ind]=a;
            temp=a;
            f=1;
            ind++;
        }
        adj[a].push_back(b);
    }
    vector<int>::iterator i;
    int node_c=1;
    for(int j=0;j<ind;j++)
    {

       for (i=(adj[nod[j]]).begin();i!= (adj[nod[j]]).end();i++) {
          if(visited[*i]==false)
          {
           // cout<<"\nNode of component "<<node_c<<" is/are :";
           dfs(*i);
           node_c++;
          }
       }
    }
    //cout<<node_c;
    if(node_c>2)
    cout<<"NO";
    else
    cout<<"YES";

}
void dfs(int s)
{

  if (visited[s])
  {return;}
visited[s] = true;
//cout<<s<<"\t";
//cout<<"for"<<s<<"\t";
//cout<<"adjacents are"<<endl;
vector<int>::iterator i;
for (i=(adj[s]).begin();i!= (adj[s]).end();i++) {
  //  cout<<*i<<endl;
        //if(!visited[i])
   dfs(*i);
  }
}

