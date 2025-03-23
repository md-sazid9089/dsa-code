//20230104063
#include<bits/stdc++.h>
using namespace std;
void dfs(int v,int e){

vector<vector<int>>adj(v);

cout << "Enter " << e << " edges (as pairs of space-separated integers):\n";
for(int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

cout << "Enter the starting vertex for BFS: ";
int s;
cin>>s;


queue<int>st;
vector<bool>visit(v,false);

visit[s]=true;
st.push(s);

cout << "BFS Traversal from vertex " << s << ": ";
while(!st.empty()){
    int curr=st.front();
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
cout << "Enter number of vertices and edges: ";
int v,e;
cin>>v>>e;
dfs(v,e);


}
