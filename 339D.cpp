#include<bits/stdc++.h>
using namespace std;
const int N=300000;
int a[N],st[N];
void buildTree(int l, int r,int index,bool check){
    if(l>r) return;
    if(l==r) st[index]=a[l];
    else{
        int mid=(l+r)>>1;
        buildTree(l,mid,2*index+1, !check);
        buildTree(mid+1,r,2*index+2,!check);
        if(check){
            st[index]= st[2*index+1]| st[2*index+2];
        }
        else{
            st[index]=st[2*index+1]^st[2*index+2];
        }
    }
}
void update(int l,int r,int index,int pos,int val,bool check){
 if(pos>=l&&pos<=r){
       if(l==r){
           st[index]=val;
           return;
       }
       int mid=(l+r)>>1;
       update(l,mid,2*index+1,pos,val,!check);
       update(mid+1,r,2*index+2,pos,val,!check);
       if(check) st[index]=st[2*index+1]|st[2*index+2];
       else st[index]=st[2*index+1]^ st[2*index+2];
   }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    bool check=n&1;
    n=(1<<n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    buildTree(0,n-1,0,check);
    // update(0,n-1,0,0,5,check);
    // for(int i=0;i<2*n-1;i++) cout<<st[i]<<endl;
    while (m--)
    {
        int pos,val;
        cin>>pos>>val;
        pos--; update(0,n-1,0,pos,val,check);
        cout<<st[0]<<endl;
    }
    

    

    
}