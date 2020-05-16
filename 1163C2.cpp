#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n, x[1010],y[1010];
int main(){
     
     cin>>n;
     for(int i=0;i<n;i++){
          cin>>x[i]>>y[i];
     }
     map<double, set<double>> mp;
     for(int i=0;i<n-1;i++){
          for(int j=i+1;j<n;j++){
               double v,c;
               if(x[i]==x[j]){
                    v=INF; c=x[i];
               }
               else{ v= (double)(y[i]-y[j])/(x[i]-x[j]);
                     c= (double)y[i]- (double)(y[i]-y[j])*x[i]/(x[i]-x[j]);
               }
               if(mp.find(v)== mp.end()) {
                    set<double> s; s.insert(c);
                    mp[v]=s;
               }
               else mp[v].insert(c);
          }
     }
     long long ans=0, sum=0;
     for(auto i: mp){
          ans+=i.second.size()*sum;
          sum+=i.second.size();
     }
     cout<<ans<<endl;
}
