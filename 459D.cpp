#include<bits/stdc++.h>
const int N=1000010;
using namespace std;
int n, a[N], f1[N],f2[N];
vector<int> st[4*N];
vector<int> :: iterator low;
void build(int id,int l, int r){
    if(l==r){
        st[id].push_back(f1[l]);
    }
    else{
        int mid=(l+r)>>1;
        build(2*id,l,mid); build(2*id+1,mid+1,r);
        merge(st[2*id].begin(),st[2*id].end(),st[2*id+1].begin(),st[2*id+1].end(),back_inserter(st[id]));
    }
}
int query(int id,int l, int r, int u, int v, int val){
    if(l>v|| r<u) return 0;
    if(u<=l&& r<=v){
        low= upper_bound(st[id].begin(),st[id].end(), val);
        return st[id].end()-low;
    }
    else{
        int mid= (l+r)>>1;
        return query(2*id,l,mid,u,v,val)+query(2*id+1,mid+1,r,u,v,val);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<int,int> x;
    cin>>n;
    for (int i = 0; i < n; i++)
    {   
        cin>>a[i];
        if(x.find(a[i])==x.end()){
            x[a[i]]=0;
        }
        x[a[i]]++;
        f1[i+1]=x[a[i]];
    }
    x.clear();
    for(int i=n-1;i>=0;i--){
        if(x.find(a[i])==x.end()){
            x[a[i]]=0;
        }
        x[a[i]]++;
        f2[i+1]=x[a[i]];
    }
    long long ans=0;
    build(1,1,n);
    for (int i = 2; i <= n; i++)
    {
        ans+= query(1,1,n,1,i-1,f2[i]);
    }
    cout<<ans<<endl;
    

    
    

    
}