/*
 * Create Component Graph, for each SCC its appropriate cost.
 * DP on DAG.
 */
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> pll;
#define sz(x) int(x.size())
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define rep(i, begin, end) for(__typeof(end) i=begin; i<end; i++)
#define per(i, begin, end) for(__typeof(end) i=begin; i>=end; i--)
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
constexpr int INF = 1e9 + 1;
constexpr ll LLINF = 1e18 + 1;
 
//#define LOCAL
 
#ifdef LOCAL
#define dbg(...) DEBUG(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...)
#endif
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void DEBUG(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void DEBUG(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; DEBUG(s.substr(s.find(',') + 2), args...);}
 
 
template<typename T>
T gcd(T a, T b){	return b ? gcd(b, a%b): a; }
template<typename T>
T lcm(T a, T b){	return a/gcd(a, b) * b;		}
 
void Dijkstra(vector<vii>& g, vector<ll>& res, int s){
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	int u,v,cost;
	res[s]=0;
	pq.push({s,0});
	while(!pq.empty()){						
		/*
			ab ye priority_queue me jab distance update krte hai to node ko update to kr ni skte to use wapis new distance
			se dalna pdta hai ab purana bhi rkha hai , and min. priority queue to naya wla pehle access krlenge isliye jo 
			baad me read hoga wo bda hoga and ye check krlete hai not equal se and fir use wapis traverse ni krte.
		*/
		u = pq.top().first;
		cost = pq.top().second;
		pq.pop();
		if(res[u]<cost)continue;
		for(auto p: g[u]){
			if(res[p.first] > res[u]+p.second){
				res[p.first] = res[u] + p.second;
				pq.push({p.first,res[p.first]});
			}
		}
	}
}


int main()
{
	fastio;
	int n, m, u, v, cost;
	cin >> n >> m;
	vector<vii> g(n,vii());	
	rep(i,0,m){		
		cin>>u>>v>>cost;
		u--;v--;
		g[u].eb(mp(v,cost));
	}
	vector<ll> res(n,LLINF);
	Dijkstra(g, res, 0);
	rep(i,0,n) cout<< res[i]<< " ";
	return 0;
}
     