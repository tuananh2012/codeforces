#include<bits/stdc++.h>
using namespace std;
int compute(string s, int val){
    string m[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    int res=0;
    for(int i=0;i<7;i++){
        if(s[i]=='1'&& m[val][i]=='0') { res=-1; break;}
        else if(m[val][i]=='1'&& s[i]=='0') res++;
    }
    return res;

}
int main(){
    bitset<2010>dp[2010];
    int n,k; cin>>n>>k;
    vector<string> s;
    for (int i = 0; i < n; i++)
    {
        string t; cin>>t; s.push_back(t);
    }
    for(int i=n-1;i>=0;i--){
        vector<int> pos;
        for(int j=0;j<10;j++){
            int t=compute(s[i],j);
            if(t!=-1) 
            pos.push_back(t);
        }
        if(i==n-1){
            for(int val: pos) {
                dp[i][val]=1;

            }
        }
        else{
            for(int val: pos){
                bitset<2010> x=dp[i+1];
                dp[i]=(dp[i]|(x<<val));
            }
        }
    }

    if(!dp[0].test(k)){
        cout<<-1<<endl; return 0;
    } 
    else{
        dp[n][0]=1;
        int remain=k;
        for (int i = 0; i < n; i++)
        {
            for(int j=9;j>=0;j--){
                int t=compute(s[i],j);
                if(t==-1)continue;
                else{
                    if(remain-t>=0&&dp[i+1][remain-t]==1){
                        cout<<j;
                        remain-=t;
                        break;
                    }
                }
            }
        }
        
    }
}