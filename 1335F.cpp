#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string> a,b;
 pair<int,int> move(int i,int j){
    switch(b[i][j]){
        case('U'): return {i-1,j};
        case('D'): return {i+1,j};
        case('L'): return {i,j-1};
        case('R'): return {i,j+1};
    }
 }


int main(){
    int t; cin>>t;
    while(t--){
        a.clear();b.clear();
        cin>>n>>m;
        for (int i = 0; i < n; i++)
        {
            string s; cin>>s;
            a.push_back(s);
        }
        for (int i = 0; i < n; i++)
        {
            string s; cin>>s; b.push_back(s);
        }
        int k = log2(n*m);
        k++;
        pair<int,int> res[n][m][k];
        for(int i = 0;i<=k;i++){
            for (int j = 0; j < n; j++)
            {
                for (int v = 0; v < m; v++)
                {
                    if(i==0) res[j][v][i]=move(j,v);
                    else {
                       int f=res[j][v][i-1].first;
                        int s= res[j][v][i-1].second;
                        res[j][v][i]= res[f][s][i-1];
                    }
                }
            }    
        }
        map<pair<int,int>,int> mp;
        int ans1=0,ans2=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {    

                pair<int,int>pii= res[i][j][k];
                if(mp.find(pii)==mp.end()) {
                    ans1++;
                    mp[pii]=1;
                    if(a[i][j]=='0'){
                        ans2++;
                        mp[pii]=2;
                    }
                }
                else{
                    if(mp[pii]==1&&a[i][j]=='0'){
                        ans2++;
                        mp[pii]=2;
                    }
                }
            }
            
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
}