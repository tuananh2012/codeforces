#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>a ;
bool check(int x){
     for (int i = 2; i <= sqrt(x); i++)
     {
         if(x%i==0) return false;
     }
     return true;
     
}
void compute(){
    int j=0;
    for (int i = 800; i >=2 ; i--)
    {
        if(check(i)) {
            a.push_back(i);
        }
    }
}
pair<ll, vector<ll> >  get( ll ma){
    ll x=a.back(); a.pop_back();
    vector<ll> ans;
    if(x>ma) return {1,ans};
    ans.push_back(x);
    while (a.size()&&1e18/a.back()>=x)
    {
        x*=a.back();
        ans.push_back(a.back());
        a.pop_back();
    }
    return make_pair(x,ans);
    
}
int main(){
    compute();
 
    int t;
    cin>>t;
    while (t--)
    {   vector<ll> uv;
        vector<ll> temp =a;
        ll ma=1e9;
        int query=0;
        while (a.size())
        {   
             auto x=get((ll) pow(ma,1.0/3));
             if(x.first==1) break;
             query++;
             cout<<"? "<<x.first<<endl; cout.flush();
             if(query==22) break;
             ll gcd; cin>>gcd;
             if(gcd!=1){
                for(auto v: x.second){
                    if(__gcd(gcd,v)==v){
                        query++;
                        ll val=1;
                        while (val<=1e9)
                        {
                            val*=v;
                         }
                        cout<<"? "<<val<<endl; cout.flush();
                        int k; cin>>k;
                        int cnt=0;
                        while(k!=1 ){
                        k=k/v;
                        cnt++;
                        }
                        ma=ma/(ll)pow(v,cnt);
                        uv.push_back(cnt);    
                        if(query==22) break; 
                    }   
                }
            } 
        }
        if(uv.size()==0) {
             cout<<"! 8 "<<endl; cout.flush();
        }
        else{
            int ans=2;
            for(auto i: uv){
                ans*=(i+1);
            }
            cout<<"! "<<ans<<endl;
            cout.flush();
        }
        a=temp; 
    }
    
 
 
}