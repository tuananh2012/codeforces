#include<bits/stdc++.h>
using namespace std;
int t,n,p[1001],c[1001];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        bool check =1;
        for (int i = 0; i < n; i++)
        {
            cin>>p[i]>>c[i];
            if(i>=1){
                if(p[i]<p[i-1]| c[i-1]>c[i]) check =0;
                else if( p[i]==p[i-1]&& c[i]>c[i-1]) check =0;
            }
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
}