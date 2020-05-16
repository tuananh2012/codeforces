#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t,x[1010],y[1010];
int main(){
    cin>>t;
    int i=1;

    while (t--)
    {
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=0;i<n;i++) cin>>y[i];
        sort(x,x+n); sort(y,y+n);
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=x[i]*y[n-1-i];
        }
        cout<<"Case #"<<i<<": "<< ans<<endl;
        i++;
    }
    

}