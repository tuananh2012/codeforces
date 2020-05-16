#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,w;
int root[100010],size[100010];
int find_root(int u){
	if(root[u]==u) return u;
	else return root[u]=find_root(root[u]);
}
void merge(int u,int v){
	int a= find_root(u),b = find_root(v);
	if(find_root(u)==find_root(v)) return;
	else{
		if(size[a]>size[b]){
			root[b]=a;
			size[a]+=size[b];
		}
		else{
			root[a] = b;
			size[b] += size[a];
		}

	}
}
int main(){
	cin>>n>>m;
	vector<tuple<int,int,int>> e;
	for(int i=0;i < m;i++){
		cin>>u>>v>>w;
		e.push_back(make_tuple(w,u,v));
	}
	sort(e.begin(),e.end());
	for (int i = 0; i < n; ++i)
	{
		/* code */
		root[i+1] = i;
	}
	long long int res=0, cnt=0;
	for(int i=0; i < e.size(), i++){
       u = get<1> (e[i]);
       v = get<2> (e[i]);
       w = get<0> (e[i]);
       if(find_root(u) != find_root(v)){
       	merge(u,v);
       	res += w;
       	cnt++;
       } 
       if(cnt == n-1) break;
	}
	cout<< res<<endl;


}