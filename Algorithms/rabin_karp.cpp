#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> Rabin_karp(string& t, string& s){

	int p = 31;
	int m = 1e9 + 9;
	int T = t.size(), S = s.size();
	vector<int>res;
	ll pat_hash;
	vector<ll> pow_p(max(T,S)),hash(t);
	pow_p[0]=1;
	for (int i = 1; i < pow_p.size(); ++i)
		pow_p[i] = (pow_p[i-1]*p)%m;
	for (int i = 0; i < T; ++i)
		hash[i] = (hash[i-1] + (s[i]-'a'+1)*pow_p[i])%m;
	for (int i = 0; i < S; ++i)
		pat_hash = (pat_hash + (s[i]-'a'+1)*pow_p[i])%m;
	for (int i = 0; i+S-1< T; ++i){
		ll cur_h = (h[i+S]+m-h[i])%m;
		if (cur_h == pat_hash)
			res.push_back(i);
	}
	return res;
}

int main(){

	string text,pattern;
	cin>>text>>pattern;
	vector<int> v = Rabin_karp(text,pattern);
	for(int i: v)cout<<i<<" ";
	return 0;
}