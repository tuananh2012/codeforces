#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    int n,s,k;
    cin>>n>>s;
    if(2*n<=s){

        cout<<"YES"<<endl;
        for (int i = 0; i < n-1; i++)
        {
            cout<<1<<" ";
        }
        cout<<s-n+1<<endl;
        cout<<s-n<<endl;
        
    }
    else{
        cout<<"NO"<<endl;
    }
}