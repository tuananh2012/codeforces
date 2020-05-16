#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=0;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,t;
    cin>>t;
    while (t--)
    {   
        int k;
        string s;
        cin>>n>>k;
        cin>>s;
        set<char> x;
        vector<int> cnt(26,0);
        for (int i = 0; i < n; i++)
        {
            x.insert(a[i]);
            cnt[a[i]-'a']++;      
        }
        if(x.size()==1){
            while(n>0){
                cout<<*x.begin();
                n-=k;
            }
        }
        else if(cnt[*x.begin-'a']<k){
            for (int i = 0; i < n; i++)
            {
                if(cnt[i]>=k){
                    cout<<'a'+i;
                    k-=a[i];
                }
            }
            
        }
        else{
            
        }
        cout<<endl;

        

        
        
        
    }
    

}