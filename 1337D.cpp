#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll get(int a,int b,int c){
    return 1ll*(a-b)*(a-b)+1ll*(b-c)*(b-c)+1ll*(c-a)*(c-a);
}
ll solve(vector<int> a, vector<int>b,vector<int> c){
    ll ans=2e18;
    int i=0,j=0,k=-1;
    for ( i = 0; i < a.size(); i++)
    {
        while(j+1<b.size()&&b[j+1]<=a[i]) j++;
        while(k+1<c.size()&&c[k+1]<a[i]) k++;
        if(k+1<c.size()){
            ans=min(ans,get(a[i],b[j],c[k+1]));
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,x;
        vector<int> s1,s2,s3;
        cin>>a>>b>>c;
        for (int i = 0; i < a; i++)
        {
            int x; cin>>x; s1.push_back(x);
        }
        for (int i = 0; i < b; i++)
        {
            int x; cin>>x; s2.push_back(x);
        }
        for (int i = 0; i < c; i++)
        {   int x; cin>>x; s3.push_back(x);
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end()); sort(s3.begin(),s3.end());
        ll ans = 2e18;
        ans=min(solve(s1,s2,s3),ans);ans=min(ans,(solve(s1,s3,s2)));
         ans=min(ans,solve(s2,s1,s3)); ans=min(ans,solve(s2,s3,s1));
          ans=min(ans,solve(s3,s1,s2)); ans=min(ans,solve(s3,s2,s1));
        cout<<ans<<endl;  
    }
 
}