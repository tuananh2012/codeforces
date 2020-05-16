#include<bits/stdc++.h>
using namespace std;
int n,l[303],c[303];
map<int,int> dp[303];
int main(){
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>l[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }
    dp[0][l[0]]=c[0];
    dp[0][0]=0;
    for (int i = 1; i < n; i++)
    {   dp[i][0]=0;
        dp[i][l[i]]=c[i];
        for(auto p : dp[i-1]){
            int f= p.first;
            int sec=p.second;
            if(dp[i].find(f)== dp[i].end())
            dp[i][f]= sec;
            else dp[i][f]=min(dp[i][f],sec);
            int ne= __gcd(f,l[i]);
            if(dp[i].find(ne)== dp[i].end()) dp[i][ne]= sec+c[i];
            else{
                dp[i][ne]=min(dp[i][ne],sec+c[i]);
            }
        }
    }
    if(dp[n-1].find(1)== dp[n-1].end()) cout<<-1;
    else cout<<dp[n-1][1]<<endl;
}

