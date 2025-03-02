
#include<bits/stdc++.h>
using namespace std;
void dfs(int v,int e){
vector<vector<int>>adj(v);
for(int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int s;
cin>>s;
stack<int>st;
vector<bool>visit(v,false);
visit[s]=true;
st.push(s);
while(!st.empty()){
    int curr=st.top();
    st.pop();
    cout<<curr<<" ";

    for(int u:adj[curr]){
        if(!visit[u]){
            visit[u]=true;
            st.push(u);
        }
    }
}
cout<<endl;
}
int main(){
int v,e;
cin>>v>>e;
dfs(v,e);
}
