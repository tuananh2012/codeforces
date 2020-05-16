#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int t,m,a[100010];
map<int,int> ma;
int get(int x){
    int ans=0;
    while(x){
        x>>=1;
        ans++;
    }
    return ans-1;
}
bool check(int mask, int pos){
    return (mask>>pos)&1;
}
int main(){
    cin>>t;
    while (t--)
    {   ll sum=0;
        vector<int> cnt(33,0);
        cin>>n>>m;
        for (int i = 0; i < m; i++)
        {
            cin>>a[i];
            sum+=1ll*a[i];
            cnt[get(a[i])]++;
        }
        if(sum < n) cout<<-1<<endl;
        else{ 
            sum=0;
            int ans=0;
            sort(a,a+m);
            for (int i = 0; i <= log2(n); i++)
            {
                if(check(n,i)){
                    sum=(1ll<<i);
                    //   cout<<i<<endl;
                    vector<int> cnt1=cnt;
                    for(int j=i;j>=0;j--){
                        if(sum >= cnt1[j]*(1ll<<j)){
                            sum-= cnt1[j]*(1ll<<j);
                            cnt1[j]=0;
                        }
                        else{

                            cnt1[j]-=sum/(1ll<<j);
                            sum=sum% (1ll<<j);
                        }
                        if(sum==0) break;

                    }
                    if(sum==0){
                        cnt=cnt1;
                        n-=(1ll<<i);
                    }
                }
            }
            
            // cout<<n<<endl;
            for(int i=30;i>=0;i--){
                if(check(n,i)){

                    for(int j=i;j<=30;j++ ){
                        if(cnt[j]>0){
                            // cout<<i<<" "<<j<<endl;
                            cnt[j]--;
                            ans+=(j-i);
                            for(int x=i; x<j;x++){
                                cnt[x]++;
                            }
                            break;
                        }
                    }
                }
            }
            cout<<ans<<endl;
            

        }
        

    }

}
    