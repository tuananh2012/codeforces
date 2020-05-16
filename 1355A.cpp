#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll get(ll l,ll r){
    return (l+r)*(r-l+1)>>1;
}
int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    long long ans=0;
    for(int i=c;i<=d;i++){
        ll t=i+1-b;
        if(t>a&&t<=b){
            ans+=(1ll*(b-t+1)*(c-b+1));
   
            ans+= get(max(1ll,c-(i-a)),c-b);//
            
        }
        else if(t<=a){
            ans+=((b-a+1)*(c-b+1));
         

        }
        
        else if(t>b){
            // if(t<=c) ans+=get(max(1ll, ), c-t+1);
            if(t<=c){
                ll r= c-t+1;
                ll l=r-(b-a);
                ans+=get(max(1ll,l),r);

            }
         
        }

    }
    cout<<ans<<endl;
    
}