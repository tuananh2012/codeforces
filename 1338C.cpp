#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll binpow(ll x,ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans*=x;
        x*=x; y>>=1;
    }
    return ans;
}
ll get(ll n){
    if(n==1) return 1;
    ll a = log2(n)/2;
    ll pos= (n+2)/3;
    pos-=(binpow(4,a)-1)/3;
    ll ans= pos+binpow(4,a)-1;
    return ans;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        ll n; cin>>n;
        ll a = get(n),b=2,c=3,ans;
        ll temp=a;
        vector<int> x;
        while(temp>>2){
            x.push_back(temp%4);
            temp>>=2; 
        }
        while (x.size())
        {   b<<=2; c<<=2;
            int v= x.back(); x.pop_back();
            if(v==1){
                b+=2; c+=3;
            }
            else if(v==2){
                b+=3; c+=1;
            }
            else if(v==3){
                b+=1; c+=2;
            }
        if(n%3==1){
            cout<<a<<endl;
        }
        else if(n%3==2) cout<<b<<endl;
        else cout<<c<<endl;

    }
}