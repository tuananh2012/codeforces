#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1<<18;
ll dp[18][maxn];
ll inc[18][18];
int n,k,m, a[18];

bool check( int mask, int pos){
    mask>>=pos;
    return mask&1;
}

void compute(int v,int mask){
    for(int i=0;i<n;i++){
        if(!check(mask,i)){
            int ne = mask+(1<<i);
            dp[i][ne]= max(dp[i][ne],(dp[v][mask]+ a[i]+ inc[v][i]));
        }
    }
}
int cnt(int mask){
    int ans=0;
    for(int i=0;i<n;i++){
        if(mask&1) ans++;
        mask>>=1;
    }
    return ans;
}
int main(){
    cin>>n>>m>>k;
    for (int i = 0; i <n ;i++ )
    {
        cin>>a[i];
        dp[i][1<<i]=a[i];
    }
    for (int i = 0; i < k; i++)
    {
        int x,y,z;
         cin>>x>>y>>z;
         x--; y--;
        inc[x][y]=z;
    }
    for (int j = 1; j < (1<<n); j++)
    {
        for (int i = 0; i < n; i++)
        {   
             if(check(j,i)) compute(i,j);
        }
    }
    ll ans=0;
    for(int i=1;i<(1<<n);i++){
        if(cnt(i)==m){
            for(int j=0;j<n;j++){
                ans=max(ans,dp[j][i]);
            }
        }
    }
    cout<<ans<<endl;

 
    

    
    
    

    
    


}