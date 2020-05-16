#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,a[500010],q;
int gcd[4*N];
int ans;
void build(int id,int l,int r){
    if(l==r){
        gcd[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    gcd[id]=__gcd(gcd[2*id],gcd[2*id+1]);
}
void update(int id,int l,int r, int pos,int x){
    if(l>pos|| r<pos) return;
    if(l==r) gcd[id]=x;
    else{
        int mid=(l+r)>>1;
        update(2*id,l,mid,pos,x);
        update(2*id+1,mid+1,r,pos,x);
        gcd[id]=__gcd(gcd[2*id],gcd[2*id+1]);
    }
}
void query(int id,int l,int r, int u, int v, int x){
    if(ans>=2) return;
    if(l>v|| r<u) return;
    if(l==r){
        if(gcd[id]%x==0) return;
        else ans++;
    }
    if(u<=l&&r<=v) {
        if(gcd[id]%x==0) return;
        else {
            if(gcd[2*id]%x&& gcd[2*id+1]%x) ans+=2;
            else {
                int mid=(l+r)>>1;
                if(gcd[2*id]%x==0)  query(2*id+1,mid+1,r,u,v,x);
                else  query(2*id,l,mid,u,v,x);
            }
        }
    }
    else{
    int mid= (l+r)>>1;
     query(2*id,l,mid,u,v,x);query(2*id+1,mid+1,r,u,v,x);}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cin>>q;
    build(1,0,n-1);
    while (q--)
    {
        int x, y,z,t;
        cin>>x>>y>>z;
        y--;
        if(x&1){
            z--;
            cin>>t;
            ans=0;
            query(1,0,n-1,y,z,t);
            if(ans<=1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            
        }
        else update(1,0,n-1,y,z);
    }
}