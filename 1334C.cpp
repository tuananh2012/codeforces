#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n, a[300010],b[300010];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>n;
        ll ans=0;
        ll res = 1e18;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i]>>b[i];
            if(i>=1){
            ans+= max(a[i]-b[i-1],0ll);
            res = min( res, a[i]-max(a[i]-b[i-1],0ll));
            }

        } 
        ans+= max(a[0]-b[n-1],0ll);
        res = min(res, a[0]-max(a[0]-b[n-1],0ll));
        ans+= res;
        cout<<ans<<endl;
    }
}