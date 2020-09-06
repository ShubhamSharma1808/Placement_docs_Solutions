
/*
 segment tree ko use krke ho jaega 
 */


#include<bits/stdc++.h>
using namespace std;

unordered_map<char,bool> vowels;


bool is_Vowel(string str){
    int n = str.size()-1;
    if(vowels[str[0]] && vowels[str[n]])return true;
    return false;
}

int build_stree(vector<int>& stree, vector<string>& arr,int idx, int R_l,int R_r){

    if (R_l == R_r){
        if(is_Vowel(arr[R_l]))
            stree[idx]=1;        
        cout<<stree[idx]<<" ";
        return stree[idx];
    }
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    int mid = (R_l+R_r)/2;    
    stree[idx] = build_stree(stree,arr,left,R_l,mid) + build_stree(stree,arr,right,mid+1,R_r);
    cout << stree[idx] << " ";
    return stree[idx];
}

int extract(vector<int>& stree, int idx, int t_l, int t_r, int q_l, int q_r){

    if(q_l <= t_l && q_r>=t_r)
        return stree[idx];
    if( t_l > q_r ||  t_r < q_l )
        return 0;
    int  mid = (t_l + t_r)/2;
    return extract(stree,2*idx+1,t_l,mid,q_l,q_r) + extract(stree,2*idx+2,mid+1,t_r,q_l,q_r);

}

int main(){
    int n;
    cin>>n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    vowels['a']= 1;    vowels['e'] = 1;    vowels['i'] = 1;
    vowels['o'] = 1;    vowels['u'] = 1;
    vector<int> stree(4*n,0);
    build_stree(stree,arr,0,0,n-1);
    //for(int i: stree)cout<<i<<" ";
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<extract(stree,0,0,n-1,--x,--y)<<endl;
    }
    return 0;
}
