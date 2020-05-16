#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010],n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;

    while (t--)
    {
        cin>>n;
        map<ll,int > cnt;
        bool check=1;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            ll x= a[i]+n*(1e9);
            x%=n;
            x+=i;
            x%=n;
            if(cnt.find(x)== cnt.end()){
                cnt[x]=1;
            }
            else{
                check=0;
            }
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    

}