
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
vector<int> level(100, -1);
vector<bool>visited(100,false);
void bfs(int source){
visited[source]=true;
queue<int>q;
level[source]=0;
q.push(source);
while(!q.empty()){
    int node=q.front();
    q.pop();
    for(auto n:adj[node]){
        if(!visited[n]){
            visited[n]=true;
            level[n]=level[node]+1;
            q.push(n);
        }
    }
}
}
int main(){
int n,m;
cout<<"the number of nodes and edges: ";
    cin>>n>>m;
    cout<<"Enter the edges(u,v): ";
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int source;
cout<<"source";
cin>>source;
bfs( source);
cout<<"level from source node"<<source<<endl;
for(int i=0;i<m;i++){
    if(level[i]!=-1){
        cout<<"NOde "<<i<<"is at "<<level[i]<<endl;
    }
    else{
        cout<<"node "<<i<<" is not reachable";
    }
}
}
