    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    ll tong=0;
    int n,m,l;
    vector<int> v,ans;
    int main(){
        cin>>n>>m;
        for (int i = 0; i < m; i++)
        {   cin>>l;
            tong+=l;
            v.push_back(l);
            if(l>n-i){
                cout<<-1;
                return 0;
            }
        }
        if(tong<n) {
            cout<<-1; return 0;
        }
        reverse(v.begin(),v.end());
        for (int i = 1; i <= n; i++)
        {    
            if(tong>=n-i+1&& v.back()<=n-i+1){
                ans.push_back(i);
                tong -= v.back();
                v.pop_back();
            }
            /* code */
        }
        for(int i : ans){
            cout<<i<<" ";
        }
        
    }