#include<bits/stdc++.h>
using namespace std;
const int N=2010, INF=2e9;
int n,m,a[N],st[4*N],lazy[4*N];
void buildTree(int l, int r,int index){
    if(l>r) return;
    if(l==r) st[index]=a[l];
    else{
        int mid=(l+r)>>1;
        buildTree(l,mid,2*index+1); buildTree(mid+1,r,2*index+2);
        st[index]=min(st[2*index+1],st[2*index+2]);
    }
}
void push(int index){
    if(lazy[index]==0) return;
    lazy[2*index+1]+=lazy[index];
    lazy[2*index+2]+=lazy[index];
    st[2*index+1]+=lazy[index];
    st[2*index+2]+=lazy[index];
    lazy[index]=0;
}
void update(int l,int r,int index,int u,int v,int val){
    if(l>v||r<u) return;
    if(u<=l&&v<=r) {
        lazy[index]+=val;
        st[index]+=val;
    }
    else{
        push(index);
        int mid=(l+r)>>1;
        update(l,mid,2*index+1,u,v,val);
        update(mid+1,r,2*index+2,u,v,val);
        st[index]=min(st[2*index+1],st[2*index+2]);
    }
}
int query(int l,int r,int index,int u,int v){
    if(l>v||r<u) return INF;
    if(u<=l&& r<=v) {
        return st[index];
    }   
    else{
        push(index);
        int mid= (l+r)>>1;
        return min(query(l,mid,2*index+1,u,v), query(mid+1,r,2*index+2,u,v));    
    }
}

int main(){
        ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n;
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    buildTree(0,n-1,0);
    cin>>m; string u; getline(cin,u);
     while(m--){
         string s;
         getline(cin,s);
         int l,r;
         l=s[0]-'0';r=s[2]-'0';
        if(s.length()==3){
            if(l<=r) cout<<query(0,n-1,0,l,r)<<endl;
            if(l>r) cout<<min(query(0,n-1,0,l,n-1),query(0,n-1,0,0,r))<<endl;
        }
        else{
            int inc;
            if(s.length()==5)  inc=s[4]-'0';
            else inc=-(s[5]-'0');
            if(l<=r) update(0,n-1,0,l,r,inc);
            else{
                update(0,n-1,0,l,n-1,inc);
                update(0,n-1,0,0,r,inc);
            }
        }
    }


    

    

}