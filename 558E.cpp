#include<bits/stdc++.h>
using namespace std;
#define ll long long    
const int N=100010;
int n,m,d[N],h[N];
struct node
{
    ll left,right,high,sum,sz,l,r;
} node[4*N];
typedef struct node node;
node add(node a, node b){
    if(a.sz==0) return b;
    if(b.sz==0) return a;
    node ans= new node;
    ans.sz=a.sz+b.sz; ans.l=a.l; ans.r=a.r;
    if(a.sz==1){
        
    }





   
}
void buildTree(int l,int r,int id){
    if(l==r){
        node[id].left=h[i];
        node[id].right=h[i];
        node[id].high=h[i];
        node[id].sum=h[i];

    }
    else{
        int mid=(l+r)>>1;
        buildTree(l,mid,2*id); buildTree(mid+1,r,2*id+1);
        add(id,l,r,mid);
    }
}
node query(int id,int l,int r,int u, int v){
    if()
    if(l==r) return node[id];
    int mid=(l+r)>>1;
    return 
}

int main(){
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>d[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
        h[i]<<=1;
    }

    
    

}