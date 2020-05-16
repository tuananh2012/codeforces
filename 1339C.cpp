#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010];
int main(){
    cin>>t;
    while (t--)
    {
        cin>>n;
        int max = -1e9;
        for(int i = 0;i < n;i++){
            cin>>a[i];
        }
        int max1 = 0;
        for(int i = 0;i < n;i++){
            if(max-a[i] > max1) max1=max-a[i];
            if(max<a[i]) max = a[i];
        }
        int ans = 0;
        while(max1>0){
            max1 >>=1;
            ans++;
        }
        cout<<ans<<endl;

    }
    

}