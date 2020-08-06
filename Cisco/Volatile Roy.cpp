#include<bits/stdc++.h>
using namespace std;
bool prime[19] = {0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0};
vector<pair<int,int>> swaps{{0,1},{0,3},{1,2},{1,4},{2,5},{3,4},{3,6},{4,5},{4,7},{5,8},{6,7},{7,8}};
std::map<std::vector<int>, int> data;

void choices(){
	queue<pair<vector<int>,int>> Que;
	std::vector<int> v{1,2,3,4,5,6,7,8,9};
	Que.push(make_pair(v,1));
	data[v]=1;
	while(!Que.empty()){
		v = Que.front().first;
		int count = Que.front().second;
		Que.pop();
// 		for(int i: v)cout<<i<<" ";
// 		cout<<count<<endl;
		for(auto p: swaps){
		   	vector<int> v2 =v;
		    if(prime[v2[p.first]+v2[p.second]]){
		        swap(v2[p.first],v2[p.second]);
    		    if(!data[v2]){
    		        Que.push(make_pair(v2,count+1));
    		        data[v2]=count+1;
    		    }
		    }
		}
	}
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	choices();
	while(t--){
	    vector<int> v(9);
        for(int i=0;i<9;i++)
            cin>>v[i];
        if(data[v])
            cout<<data[v]-1<<endl;
        else
            cout<<"-1"<<endl;
	}
	return 0;
}
