#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=200010; 
const ll INF=2e18;
ll a[MAXN],n,m;

struct Node {
    ll lazy; // giá trị T trong phân tích trên
    ll val; // giá trị lớn nhất.
} nodes[MAXN * 4];
void buildTree(int l,int r,int id){
    nodes[id].lazy=0;
    if(l==r) nodes[id].val=a[l];
    else{
        int mid=(l+r)>>1;
        buildTree(l,mid,2*id); buildTree(mid+1,r,2*id+1);
        nodes[id].val=min(nodes[2*id].val,nodes[2*id+1].val);
    }
}
void down(int id) {
    int t = nodes[id].lazy;
    nodes[id*2].lazy += t;
    nodes[id*2].val += t;

    nodes[id*2+1].lazy += t;
    nodes[id*2+1].val += t;

    nodes[id].lazy = 0;
}
void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        // Khi cài đặt, ta LUÔN ĐẢM BẢO giá trị của nút được cập nhật ĐỒNG THỜI với
        // giá trị lazy propagation. Như vậy sẽ tránh sai sót.
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    int mid = (l + r) / 2;

    down(id); // đẩy giá trị lazy propagation xuống các con

    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    nodes[id].val = min(nodes[id*2].val, nodes[id*2+1].val);
}
ll query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return INF;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    down(id); 
    return min(query(id*2, l, mid, u, v),
        query(id*2+1, mid+1, r, u, v));
    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    buildTree(0,n-1,1);
    cin>>m; string u; getline(cin,u);
     while(m--){
         string s;
         getline(cin,s);
         stringstream ss; ss<<s;
         ll l,r,inc=INF;
         if(count(s.begin(),s.end(),' ')==1)
         ss>>l>>r;
         else ss>>l>>r>>inc;
        if(inc==INF){
            if(l<=r) cout<<query(1,0,n-1,l,r)<<endl;
            if(l>r) cout<<min(query(1,0,n-1,l,n-1),query(1,0,n-1,0,r))<<endl;
        }
        else{
            if(l<=r) update(1,0,n-1,l,r,inc);
            else{
                update(1,0,n-1,l,n-1,inc);
                update(1,0,n-1,0,r,inc);
            }
        }
    }


    

    

}