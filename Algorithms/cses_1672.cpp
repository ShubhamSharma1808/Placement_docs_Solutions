//shortet_routes_2

#include<bits/stdc++.h>
using namespace std;
constexpr long long LLINF = 1e16 + 1;

int main(int argc, char const *argv[])
{
	int n, m, q;
	int u,v;
    long long cost;
	cin>>n>>m>>q;
	long long arr[n][n];
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; ++j)
		{
			i==j ? (arr[i][j]=0) : (arr[i][j]=LLINF);
		}
	}   
    
    for (int i = 0; i < m; ++i)
	{
		cin>>u>>v>>cost;
		u--;v--;
		arr[u][v]=min(arr[u][v],cost);
		arr[v][u]=arr[u][v];
	}
	

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
                arr[j][i]=arr[i][j];
			}
		}
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout<<arr[i][j]<<" ";
	// 	}cout<<endl;
	// }
	while(q--){
		cin>>u>>v;
		u--;v--;
		if(arr[u][v]<LLINF)
			cout<<arr[u][v]<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
