#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll u,v;
	cin>>u>>v;
	if(u>v) cout<<-1;
	else if( (u+v) % 2!=0) cout<<-1;
	else if(u==0){
		if(v) cout<<2<<endl<<v/2<<" "<<v/2<<endl;
		else cout<<0;
	}
	else if(u==v) cout<<1<<endl<<u;
	else{
		bool check=1;
		bitset<60> tong(v),x(u), a,b;
		int du=0;
		for(int i=0;i <60; i++){
			if(tong[i]==x[i]){
				if(du){
					check = 0; break;
				}
              	if(i==59 || tong[i+1] == x[i+1]){
              		if(tong[i]==0){
              			a[i]=0; b[i]=0;
              		}
              		else{
              			a[i]=1; b[i]=0;
              		}
              	}
              	else{
              		if(tong[i] == 0){
              			a[i]=1;
              			b[i]=1;
              			du=1;
              		}
              		else {
              			check=0; break;
              		}

              	}
              }
              else {
              	if(du == 0){
              		check=0; break;
              	}
              	else{
              		if(x[i] == 1){
              			a[i]=1; b[i]=0;
              			du = 1;
              		}
              		else{
              			if( i == 59 || tong[i+1] == x[i+1]){
              				a[i] = 0; b[i] = 0; du=0;
              			}
              			else{
              				a[i] = 1; b[i] = 1; du = 1;
              			}
              		}
              	}

              }
			}
		if(check){
			cout<<2<<endl<<a.to_ullong()<<" "<<b.to_ullong();
		}

		if(check == 0){
			cout<<3<<endl<<u<<" "<<(v-u)/2<<" "<<(v-u)/2<<endl;
		}

	}

}