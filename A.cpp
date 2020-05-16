#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200010];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> pos[206];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            pos[a[i]].push_back(i);
        }
        int ans = 1;
        vector<int> oc[205];
        for(int i =1 ;i<201;i++){
            int val = 0, index = 0;
            for(int j=0;j<n;j++){
                if(index+1<=pos[i].size()&&j==pos[i][index]){
                    index++;
                    val++;
                }
                oc[i].push_back(val);
            }
        }
        for(int i = 1;i<201;i++){
            for(int j =1;j+j<=pos[i].size();j++){
                int l = pos[i][j-1],r=pos[i][pos[i].size()-j];
                for(int v=1;v<201;v++){
                    ans=max(ans, 2*j+oc[v][r-1]-oc[v][l]);
                }
            }
        }
        cout<<ans<<endl;
    }
 
}



