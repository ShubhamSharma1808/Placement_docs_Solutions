/* 
Idea of the soln: looks like dp can be applied but it cant be due to the snakes(my view),so graph is better created
the graph of every position and connected it with weight 1 then added edges for snakes and ladder with edge weight 0 
and then find the shortest dist. between two ends with Dijkstra.
*/

#include <bits/stdc++.h>
using namespace std;
//define INF 1000000007;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int Dijkstra(vector<vii>& g){
    vector<int> dist(31,32);
    priority_queue<ii,vii,greater<ii>> pq;
    int u,v,cost;
    pq.push({1,0});
    dist[1]=0;
    while(!pq.empty()){
        u = pq.top().first;
        cost = pq.top().second;
        pq.pop();
        if(dist[u]!=cost)
            continue;
        //printf("at index: %d with cost: %d\n",u,cost);
        for(auto p: g[u]){
            if(dist[p.first]>dist[u]+p.second){
                dist[p.first] = dist[u]+p.second;
                pq.push({p.first,dist[p.first]});
            }
        }
    }
    return dist[30];
}


int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    vector<vii> g(31);
	    //graph creation(wt=1)
	    for(int i=1;i<30;i++){
	        for(int j=1;j<7;j++){
	            if(i+j<31)  
	                g[i].push_back({i+j,1});
	        }
	    }
	    //adding edges of snakes and ladders(wt=0)
	    while(n--){
	        int u,v;
	        cin>>u>>v;
	        g[u] = vii();
	        g[u].push_back({v,0});
	    }
	    //using dijkstra to find shortest dist.
	   // for(int i=1;i<31;i++){
	   //     cout<<"for index "<<i<<": ";
	   //     for(auto p: g[i]){
	   //         cout<<p.first<<" "<<p.second<<",";
	   //     }cout<<endl;
	   // }
	    cout<<Dijkstra(g)<<endl;
	}
	return 0;
}
