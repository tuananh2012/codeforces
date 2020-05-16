#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000010;
int n, a[N];
// void compute(){
//     for (int i = 0; i < n; i++)
//     {
//         dp[0][i]=a[i];
//     }
//     for (int i = 1; i < 20; i++)
//     {
//         for (int j = 0; j+a2[i] <= n; j++)
//         {  
//             dp[i][j]=min(dp[i-1][j],dp[i-1][j+a2[i-1]]);
//         }
        
//     }
// }
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    
    // compute();
    int m; cin>>m;
    long long ans=0;
    while (m--)
    {
        int l,r; cin>>l>>r;
        ans+=*min_element(a+l,a+r+1);
       
        
    }
    cout<<ans<<endl; 
}