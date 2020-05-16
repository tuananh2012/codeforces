#include<bits/stdc++.h>
using namespace std;
int n, a[100010];
long long pow1(int x,int a){
    long long ans=1;
    while(a--){
        ans*=x;
    }
    return ans;
}

int main(){
    cin>>n;
    int x=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        x=__gcd(x,a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        a[i]/=x;
    }
    vector<int > cnt(200010,0);
    vector<int> power(200010,200010);
    for (int i = 0; i < n; i++)
    {
        for (int  j = 2; j <= sqrt(a[i]); j++)
        {   
            if(a[i]%j==0){
                int c=0;
                cnt[j]++;
                while (a[i]%j==0)
                {   c++;
                    a[i]/=j;
                } 
                power[j]=min(power[j],c); 
            }
        }
        if(a[i]>1) {
            cnt[a[i]]++;
            power[a[i]]=1;
        }
    }
    long long ans=1;
    for (int i = 2; i < 200010; i++)
    {
        if(cnt[i]==n-1) {
            
           ans*= pow1(i,power[i]);
        }
    }
    cout<<ans*x<<endl;        
}