#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    for(int i=a;i<=b;i++){
        for(int j=b;j<=c;j++){
            for(int t=c;t<=d;t++){
                if(i+j>t) ans++;
            }
        }
    }
    cout<<ans<<endl;
}
    