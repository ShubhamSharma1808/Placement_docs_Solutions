#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<pair<ll,ll>> cache(pow(2,20),{-1,-1});
vector<int> Data;
int n,target;                                   

pair<ll,ll> IntDist(ll cur){
    if(cur==0)
        return {0,0};   
    if(cache[cur].first!=-1)
		return cache[cur]; 
    ll val2, Max=LLONG_MIN, Min=LLONG_MAX;
    pair<ll,ll> tmp;
	for(int i=0;i<=n;i++){
        if(!(cur & (1<<i)))continue;
        for(int j=i+1;j<=n;j++){
            if(!(cur & (1<<j)))continue;
            ll val = cur & ~(1<<i);
            val = val & ~(1<<j);
            tmp = IntDist(val);
            val2 = (Data[n-i] ^ Data[n-j]);   
			Max = max(Max,val2+tmp.second);
            Min = min(Min,val2+tmp.first);
        }
    }
    return cache[cur]={Min,Max};
}

int main(){
    //solve and print your answers here 
    cin>>n;
    Data.assign(n,0);
    for(int i=0;i<n;i++){
       cin>>Data[i]; 
    } 
	//cout<<n<<endl;
	n--;
	//cout<<cache.size()<<" "<<cur<<endl;	
    pair<ll,ll> res = IntDist(pow(2,n+1)-1);
    cout<<res.first<<" "<<res.second;
	return 0; 
}

