#include<bits/stdc++.h>
using namespace std;
void bfs(int v,int e){
vector<vector<int>>adj(v);
for(int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
cout<<"enter the starting vertex"<<endl;
int s;
cin>>s;
queue<int>q;
vector<bool>visit(v,false);
visit[s]=true;
q.push(s);
cout<<"bfs traversal from vertex"<<s<<":";
while(!q.empty()){
    int curr=q.front();
    q.pop();
    cout<<curr<<"  ";
    for(int u:adj[curr]){
        if(!visit[u]){
            visit[u]=true;
            q.push(u);
        }

    }

}
}
int main(){
cout<<"enter mumber of vertices and edges";
int v,e;
cin>>v>>e;
bfs(v,e);

}
