/*
straight forward question
max and min array banalo then hrr element ke liye check krlo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T,n;
	cin>>T;
	while(T--){
	    cin>>n;
	    int arr[n],Max[n],Min[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int tmp=arr[0];
	    bool flag = false;
	    Max[0]=INT_MIN;
	    Min[n-1]=INT_MAX;
	    for(int i=1;i<n;i++){
	        Max[i] = max(Max[i-1],arr[i-1]);
	        Min[n-i-1] = min(Min[n-i],arr[n-i]);
	        //cout<<Max[i]<<" "<<Min[n-i-1]<<endl;
	    }
	    if(arr[0]<Min[0]){
	        cout<<"0"<<endl;
	        continue;
	    }
	    else if(arr[n-1]>Max[n-1]){
	        cout<<n-1<<endl;
	        continue;
	    }
	    for(int i=1;i<n-1;i++){
	        if(Max[i]<arr[i] && arr[i]<Min[i]){
	            cout<<i<<endl;
	            flag = true;
	            break;
	        }
	    }
	    if(!flag)
	        cout<<"-1"<<endl;
	}
	return 0;
}
