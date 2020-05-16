#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[500010],l[500010],r[500010];
long long dpl[500010],dpr[500010];
void getleft(){
    stack<int> s;
    for (int i = 0; i < n; i++)
    {   l[i]=-1;
        if(!s.empty()){
            while(!s.empty()&& a[i] <= a[s.top()]){
                s.pop();
            }
        }
        if(!s.empty()) l[i]=s.top();
        s.push(i); 
    }
}
void getright(){
    stack<int> s;
    for (int i = n-1; i >= 0; i--){
         r[i]=n;
        if(!s.empty()){
            while(!s.empty()&& a[i] <= a[s.top()]){
                s.pop();
            }
        }
        if(!s.empty()) r[i]=s.top();
        s.push(i);
    }  
}
int main(){
     ios_base:: sync_with_stdio(0);
     cin.tie(0);
     cin>>n;
     for(int i=0;i<n;i++){
          cin>>a[i];
     }
     getleft();
     getright();
     for(int i=0;i<n;i++){
         if(l[i]>=0)
         dpl[i]= dpl[l[i]]+1ll*(i-l[i])*a[i];
         else dpl[i]=1ll*(i-l[i])*a[i];
     }
     for (int i = n-1; i >= 0; i--)
     {   if(r[i]<n)
         dpr[i]= dpr[r[i]]+1ll*(r[i]-i)*a[i];
         else dpr[i] = 1ll * (r[i]-i) * a[i];
     }
     int mark=0;
     ll res=0;
          for(int i=0; i<n;i++){
         if(dpl[i]+dpr[i]-a[i]>res){
             mark=i;
             res= dpl[i]+dpr[i]-a[i];
         }
     }
     for(int j=mark-1;j>=0;j--){
         if(a[j]>=a[j+1]) a[j]=a[j+1];
     }
     for(int j=mark+1;j<n;j++){
         if(a[j]>a[j-1]) a[j]=a[j-1];
     }
     for (int i = 0; i < n; i++)
     {
         /* code */
         cout<<a[i]<<" ";
     }
}
