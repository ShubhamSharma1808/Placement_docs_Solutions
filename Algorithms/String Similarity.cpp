#include <bits/stdc++.h>

using namespace std;

// Complete the stringSimilarity function below.
long stringSimilarity(string s) {
    int n = s.size();
    long res = n;
    vector<int> Z(n);
    Z[0]=0;
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<=r)
            Z[i] = min(Z[i-l],r-i+1);
        else Z[i]=0;
        while(i+Z[i]<n && s[i+Z[i]]==s[Z[i]])
            ++Z[i];
        if(Z[i]>0 && i+Z[i]-1>r){
            l = i;
            r = i + Z[i]-1;
        }
        res += Z[i];
        //printf("Z[%d] : %d , res: %d, l: %d, r: %d\n",i,Z[i],res,l,r);       
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        long result = stringSimilarity(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
