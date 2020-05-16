#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {   int n,m;
        cin>>n>>m;
        if(n>m) {
            int te=n; n=m; m=te;
        }
        if(n==1) cout<<"YES"<<endl;
        else if(n==2){
            if(m==2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    

    
}