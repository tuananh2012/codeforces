#include<bits/stdc++.h>
using namespace std;
const int N= (1<<17)-1;
const int c=1e9;
int n,a[102], prime[18], fac[61];
int dp[N][110][3];
 
bool isPrime(int x){
	bool check=1;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0) {
			check=0; break;
		}
	}
	return check;
}
void f(){
	int j=0;
	for(int i=2;i<=60;i++){
		if(isPrime(i)){
			prime[j]=i;
			j++;
		}
	}
}
void getmask(){
	for(int x=1;x<=60;x++){
	int ans=0;
	for(int i=0;i<17;i++){
		if(x%prime[i]==0) ans=ans|(1<<i);
	}
	fac[x]= ans;
    }
}
 
int main(){
	f();
	getmask();
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int mask=0;mask<=N;mask++){
		for(int j=0;j<=n;j++){
			if(j==0)
			dp[mask][j][0]=0;
			else dp[mask][j][0]=c;
		}
	}
	for(int i=1;i<=n;i++ ){
		for(int j=1;j<60;j++){
			int x=(~fac[j])&N;
			for(int s=x; ;s=(s-1)&x){
				if(dp[s|fac[j]][i][0]>dp[s][i-1][0]+abs(j-a[i-1])){
					dp[s|fac[j]][i][0]=dp[s][i-1][0]+abs(j-a[i-1]);
					dp[s|fac[j]][i][1]=j;
					dp[s|fac[j]][i][2]=s;
					
				}
				if(s==0) break;
			}	
		}
	}
	int mark=0;
	for(int i=0;i<=N;i++){
		if(dp[i][n][0]<dp[mark][n][0]) mark=i;
	}
	vector<int> ans;
	for(int i=n;i>0;i--){
		ans.push_back(dp[mark][i][1]);
		mark=dp[mark][i][2];
	}
	for(int i=n-1;i>=0;i--){
		cout<<ans[i]<<" ";
	}
}
