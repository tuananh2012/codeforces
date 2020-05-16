#include<bits/stdc++.h>
using namespace std;
int n,a[100010],k,mark;
int main(){
    int t; 
    cin>>t;
    while (t--)
    {
  
    
    cin>>n>>k;
    bool check =0;
    
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]==k) {
            check =1; mark=i;
        }
    }
    if(!check) { cout<<"NO"<<endl; continue;}
    check =0;
    for (int i = 0; i < n-1; i++)
    {
        if(a[i]>=k&&a[i+1]>=k){
            check =1; break;
            
        }   
    }
    for (int i = 0; i < n-2; i++)
    {
        if(a[i]>=k&& a[i+2]>=k){
            check=1; break;
        }
    }
    if(check|| n==1) cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
    }
    
    


    
    
}