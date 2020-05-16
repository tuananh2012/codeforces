#include<bits/stdc++.h>
using namespace std;
int a,b,c,t;
vector<int> u[20010];
void solve(){
    int ans = c-a;
    int x=a,q=b,z=c;
    for(int y = (max(1,b-c+a)); y<=b+c-a; y++){
        int res = abs(b-y);
        int val = 200010;
        int mark;
        for( int i : u[y]){
            if(val> abs(a-i)){
                val = abs(a-i);
                mark = i;
            }
        }
        res+= val;
        if(c>=y){
            if(c%y<=(y/2)){
                res+= c%y;
                if( res <= ans){
                     ans = res;
                    q=y; z= c-c%y; x=mark;
                }
            }
            else {
                res+=(y-(c%y));
                if( res <= ans){
                    ans=res;
                    q=y; z= c+y-(c%y); x= mark;
                }
            }
        }
        else{
            res+= (y-c);
            if( res <= ans){
                 ans = res;
                 q=y; z=y; x=mark;
            }
        }
    }
     cout<<ans<<endl;
     cout<<x<<" "<<q<<" "<<z<<endl;
 
    
}
int main(){
    for(int i = 1;i<20010;i++){
        for (int j = 1; j <= sqrt(i); j++)
        {
            if(i % j ==0){
                u[i].push_back(j);
                if(j!=(i/j)) u[i].push_back(i/j);
            }
        }
    }
//    for(int i : u[10]) cout<<i<<endl;
    cin>>t; 
   while (t--)
   {   cin>>a>>b>>c;
        solve();
   }
    
}