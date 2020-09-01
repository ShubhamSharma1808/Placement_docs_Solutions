#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g,revg,compg;
vector<int> visited,top_sort,mapping;
 
void TopSort_g(int u){
	visited[u]=1;
	for (auto v: g[u])
		if(!visited[v])
			TopSort_g(v);
	top_sort.push_back(u);
}
 
void Traverse(int u, int num){
	visited[u]=1;
	mapping[u]=num;
	for (auto v: revg[u])
		if(!visited[v])
			Traverse(v,num);
}
 
int main(int argc, char const *argv[])
{
	int v,e;
	cin>>v>>e;
	int k[v+1];
	g.resize(v+1,vector<int>());
	revg.resize(v+1,vector<int>());
	visited.assign(v+1,0);
	for(int i=1;i<=v;i++)
		cin>>k[i];
	
	int u,v1;
	/*
	Graph and reverse graph created for finding component graph
	*/
	for(int i=0;i<e;i++){
		cin>>u>>v1;
		g[u].push_back(v1);
		revg[v1].push_back(u);
	}
 
	for(int i=1;i<=v;i++)
		if(!visited[i])
			TopSort_g(i);
	
	visited.assign(v+1,0);
	mapping.resize(v+1);
	int num=1;
 
    // for(int i=0;i<v;i++)
    //     cout<<top_sort[i]<<" ";
    // cout<<endl;
	for(int i=v;i>0;i--){
        int u = top_sort.back();
        top_sort.pop_back();
		if(visited[u])continue;
		Traverse(u,num);
		num++;
	}	
	// for(int i: mapping)
	// 	cout<<i<<" ";
	
	vector<long long> value(num,0),sum(num,0);
	vector<int> indeg(num,0);
	/*
	making component grpah 
	*/
    compg.resize(num,vector<int>());
    for(int i=1;i<=v;i++)
    	for(int j: g[i])
    		if(mapping[i]!=mapping[j]){
    			compg[mapping[i]].push_back(mapping[j]);
    			indeg[mapping[j]]++;
    		}
    
    for(int i=1;i<=v;i++){
    	value[mapping[i]] += k[i];
    }
    
    visited.assign(num,0);
    
    for(int i=1;i<num;i++)
    	if(indeg[i]==0)
    		sum[i]=value[i];
 	/*
	ek aur tarika hai , jo component graph ki mapping krte hai to wo jo no ata hai component ka wo already top. sort ke form mr hota sort krne ke baad
	to alg se indeg nikalkr bar bar krne ki zarrorat ni. 
	*/
    for(int i=1;i<num;i++){
    	if(indeg[i]==0 && !visited[i]){
    		visited[i]=1;
    		for(int j: compg[i]){
    			sum[j] = max(sum[j],sum[i]+value[j]);
    			indeg[j]--;
    		}
    	}
    }
 
    for(int i=1;i<num;i++){
    	sum[0]=max(sum[0],sum[i]);
    }
    cout<<sum[0];
    return 0;
}
