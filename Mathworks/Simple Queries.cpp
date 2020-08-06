int bsearch(int x, int arr2[],int n){
    int l=0,r=n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr2[mid]<=x)
            l = mid+1;
        else
            r = mid-1;
    }
    return r;
}

vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n)
{
//Your code goes here
    vector<int> res(m);
    sort(arr2,arr2+n);
    
    for(int i=0;i<m;i++){
        res[i] = bsearch(arr1[i],arr2,n)+1;
    }
    return res;
}
