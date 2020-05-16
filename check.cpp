#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=0;
    for (int i = 0; i < 6; i++)
    {
        int x; cin>>x;
        a=__gcd(a,x);
        cout<<a<<endl;
    }
    
}