#include<bits/stdc++.h>
using namespace std;
int t,n,pos[100010];
int main(){
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            pos[x]=i;
        }
        int start=1;
        int high=n;
        bool check=1;
        while (check&&start<n)
        {
            int s=start;
            while (s<n&&pos[s]==pos[s+1]-1)
            {
                s++;
            }
            if(pos[s]!=high){
                check =0;
            }
            else{
                high=pos[start]-1;
                start=s+1;
            }
            
        }
        
        if(!check) cout<<"NO"<<endl;
        else cout<<"Yes"<<endl;
    }
    

}