#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,l,r;
void  solve(){
    if(l==(n)*(n-1)+1){
        cout<<1<<endl;
        return;
    }
    ll i = n-1;
    l--;
    r-=l;
    while(l- i*2>=0){
        l-=2*i ; i--;
    }
    int start;
    bool check = l&1;
    start = n-i;
    l= ((l+2)>>1)+start;
    while(r--){
        if(!check)
        cout<<start<<" ";
        else{
            cout<<l<<" ";
            l++;
            if(l>n) {
                start++;
                l= start + 1;
                if(start==n) start = 1;
            }
        }
            check = !check;
    }

}
int main(){
    ios_base::sync_with_stdio(0);
     cout.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>n>>l>>r;
        solve();
        cout<<endl;
    }
}