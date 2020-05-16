#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=0;
int main(){
    int t;cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int ans=0;
        while(n>1){
            int x= sqrt(2*n/3);
            if(3*x*x+x>2*n){
                x--;
            }
            x=(3*x*x+x)/2;
            ans+=n/x;
            n=n%x;
        }
        cout<<ans<<endl;
    }
    
}