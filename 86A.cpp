#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200010 ;
int c[N],cnt[N];
vector<int> m;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    { 
        int x; cin>>x; m.push_back(x);
        
    }
    for (int i = 0; i < k; i++)
    {
        cin>>c[i];
    }
    sort(m.begin(),m.end());
    int ans=0;
    vector<int> :: iterator low;
    for(int i=1;i<=k;i++){
        low= lower_bound(m.begin(),m.end(),i);
        cnt[i]=(m.end()-low);
 
        if(cnt[i]%c[i-1]==0) ans=max(ans,cnt[i]/c[i-1]);
        else ans=max(ans,cnt[i]/c[i-1]+1);
    }
    cout<<ans<<endl;
    vector<int> res[ans];
    int j=0;
    for(int i=0;i<n;i++){
        res[j].push_back(m[i]);
        j++;
        if(j==ans) j=0;    
    }
    for (int i = 0; i < ans; i++)
    {
        cout<<res[i].size()<<" ";
        for(auto j: res[i]) cout<<j<<" ";
        cout<<endl;
    }

    


    
    
    

}