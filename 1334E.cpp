#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
ll D,q,n;
map<ll,ll> m;
ll solve(ll x){
    if(m.find(x) != m.end());
    ll res = 0;
    ll v = x;
    for(ll i =2;i*i<=x;i++){
        if(x%i ==0){
            res+=solve(v/i); 
            res = res % mod;    
            while(x%i==0) x = x/i;
        }
    }
    if(x>1){
        res+= solve(v/x);
        res = res % mod;
    }
    return m[v]= res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>D;
    cin>>q;
    m[1]=1;
    solve(D);
    while(q--){
        ll u,v;
        cin>>u>>v;
        ll x = u/__gcd(u,v); ll y= v/__gcd(u,v);
        cout<<m[x]*m[y]%mod<<endl;
    } 
}