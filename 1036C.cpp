#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll compute(int x){
     ll ans=1;
    for (int i = 0; i < x; i++)
    {
        ans=ans*9;
    }
    return ans;
}
ll get(int x){
    if(x==1) return 10;
    ll ans=compute(x);
    if(x>=2) ans+= compute(x-1)*(x-1);
    if(x>=3) ans+=compute(x-2)*(x-1)*(x-2)/2;
    if(x>=4) ans+=(compute(x-3)*(x-1)*(x-2)*(x-3))/6;
    return ans;
}
ll get1(int x){
    ll ans=0;
    for(int i=1;i<=x;i++){
        ans+=get(i);
    }
    return ans;
}
ll solve(vector<int> x){
    ll ans=0;
    if(x.size()==0) return 1;
    if(x.size()==1) return x.back()+1;
        int v=x.size();
        ll val= get1(v-1);
        int k=x[v-1];
        x.pop_back();
        return val*k+ solve(x);
}
int main(){
    int t; cin>>t;
    cout<<get1(6)<<endl;
    cout<<solve({0,0,0,0,0,0,1});
    // while (t--)
    // {   ll l,r; vector<int> x,y;
    //     cin>>l>>r;
    //     l--;
    //     while(l){
    //         x.push_back(l%10);
    //         l/=10;
    //     }
    //     while (r)
    //     {
    //         y.push_back(r%10);
    //         r/=10;
    //     }
    //     cout<<(solve(y)-solve(x))<<endl;
    // }
    
}