#include <bits/stdc++.h>
using namespace std;
int n,m;
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
	for (int i = 0; i < n; ++i)
	{
		/* code */
		root[i]=i;
	}
	for(int i = 0; i < m;i++){
		int u,v;
		cin>>u>>v;
		merge(u,v);
	}
	set<int>s;
	for(int i=0; i < n;i++){
       s.insert(find_root(i+1));
	}
	cout<<s.size();

	}