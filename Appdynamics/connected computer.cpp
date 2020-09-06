#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

int vertex;
int dfs(vector<vi>& g, vi& visited, int node){
    visited[node] = 1;
    int edges = g[node].size();
    vertex++;
    for (auto v: g[node])
    {
        if(visited[v])continue;
        edges += dfs(g,visited,v);  
    }
    return edges;
}

int main(){
    int n,e,u,v;
    cin>>n>>e;
    vector<vi> g(n,vi());
    for(int i=0;i<e;i++){        
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ii> component;
    vi visited(n);
    int edges;
    for(int i=0;i<n;i++){
        if(!visited[i]){
           vertex=0;
           edges = dfs(g,visited,i);
           component.push_back({vertex,edges/2});
        }
    }
    //for(auto i: component)cout<<i.first<<", "<<i.second<<endl;
    
    int available=0,required = component.size()-1;
    for(auto p: component){
        if(p.second > p.first - 1) 
            available += p.second-(p.first-1);
    }
    if(available<required)cout<<"-1";
    else cout<<required;
    return 0;
}