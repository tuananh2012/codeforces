#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,d;
int main(){
    cin>>t;
    while ((t--))
    {
        cin>>n>>a>>b>>c>>d;
        if(n*(a-b)<=(c+d)&& n*(a+b)>=(c-d)) 
        
        cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    

}