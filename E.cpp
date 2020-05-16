#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,k;
vector<pair<int,int> > concenate(vector<pair<int,int> > a, vector<pair<int,int> > b){
    vector<pii> ans;
    vector<bool> vis(201,0);
    for(auto v: a) vis[v.first]=1;
    for(auto v: b) vis[v.first]=1;
    for(int i =1;i<=200;i++){
        if(vis[i]==0) {
            ans.push_back({i,0}); break;
        }
    }
    for(int i=b.size()-1;i>=0;i--)ans.push_back(b[i]);
    for(int i=a.size()-1;i>=0;i--) ans.push_back(a[i]);
    return ans;

 }
int main(){
    int t; cin>>t;
    while (t--)
    {  
       cin>>n;
       vector<int> list[201];
       vector<pair<int,int> >ans,ans1,ans2;
       set<int> occur[201],occur1[201];
       for (int i = 0; i < n-1; i++)
       {
           cin>>k;
           for (int j = 0; j < k; j++)
           {
               int val; cin>>val; list[i].push_back(val);
               occur[val].insert(i); occur1[val].insert(i);
           }
       }
       bool check=1; int start=0,end=0;
       for (int i = 1; i < n+1; i++)
       {
           if(occur[i].size()==1){
               if(start==0) start=i;
               else{
                   end=i; check=0; break;
               }
           }
       }
        while(check&&ans.size()<n-1){
            start=0; end=0;
            for (int i = 1; i < n+1; i++){
                if(occur[i].size()==1){
                    if(start==0) start=i;
                    else{end=i; check=0; break;
                    }
                }
            }
            if(check){
                int j= *occur[start].begin();
                ans.push_back({start,j});
                for(int v: list[j]){
                    occur[v].erase(j);
                    occur1[v].erase(j);
                }
            }
        }
        if(check==0){
            bool test=1;
            while(ans1.size()<n-1-ans.size()){
                bool test=1;
                for(int i=1;i<=n;i++){
                    if(occur[i].size()==1&&i!=end){
                        test=0;
                        int j= *occur[i].begin();
                        ans1.push_back({i,j});
                        for(int v: list[j]){
                            occur[v].erase(j);
                        }
                    }
                }
                if(test) break;
            }
                while (ans2.size()<n-1-ans.size())
                {   test=1;
                    for(int i =1;i<=n;i++){
                        if(occur1[i].size()==1&&i!=start){
                            int j=*occur1[i].begin();
                            test=0;
                            ans2.push_back({i,j});
                            for(int v: list[j]){
                                occur1[v].erase(j);
                            }
                        }
                    }
                    if(test) break;
                }
            
            vector<pair<int,int>> temp;
            if(ans1.size()==n-1-ans.size()){
                check=1;
               temp= concenate(ans,ans1);

                for(int i=1;i<temp.size();i++){
                    int f=temp[i].first,sec=temp[i].second;
                    for(int j=i;j>i-list[sec].size();j--){
                        if(!binary_search(list[sec].begin(),list[sec].end(),temp[j].first)){
                            check=0; break;
                        }
                    }
                    if(!check) break;
                }
            }

           
        }
           if(check){
                vector<pii> temp=concenate(ans,ans1);
                for(auto v: temp) cout<<v.first<<" ";
            }
            else{
                vector<pii> temp1=concenate(ans,ans2);
                for(auto v: temp1) cout<<v.first<<" ";
            }
            cout<<endl;
     

     
    }
    
}