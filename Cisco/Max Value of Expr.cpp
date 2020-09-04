/*
 * Dp variation of matrix chain multiplication.
 * it cant handle mulitple digit value test case , for that we need diff. implemetation like we will need to have two diff. arrays storing values 
 * of operands and operators. this is the one case. one more issue is that we just cant take local max to find the global max
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

 
 int solve(vector<vi>& cache, string str, int i, int j){
     if(cache[i][j]!=-1)
         return cache[i][j];     
     if(i==j){        
        printf("value returned from [ %d , %d ] is %d\n",i,j,str[i]-'0');
        cache[i][j] = str[i]-'0'; 
        return str[i]-'0';
     }
   int tmp1,tmp2,mx = INT_MIN; 
   rep(k,i,j){
     tmp1 = solve(cache,str,i,k);
     tmp2 = solve(cache,str,k+2,j); 
     //cout<<tmp1<<" "<<tmp2<<endl;
     if(str[k+1]=='+')
      mx = max(mx,tmp1+tmp2);
     else  if(str[k+1]=='-')
      mx = max(mx,tmp1-tmp2);
     else mx = max(mx,tmp1*tmp2);
     k++;
   }
   printf("value returned from [ %d , %d ] is %d\n",i,j,mx);
   cache[i][j]=mx;  
   return mx;
 }
 
int main()
{
	fastio;
  string str;
  cin>>str;
  vector<vi> cache(str.size(),vi(str.size(),-1));
  cout<<solve(cache,str,0,str.size()-1);
  return 0;
}
 
