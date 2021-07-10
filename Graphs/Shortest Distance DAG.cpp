#include<bits/stdc++.h>
using namespace std;
void toposo(int src, stack<int>& st, int vis[], vector<pair<int,int>> adj[]){
    vis[i] =1;
    for(auto it : adj[i]){
        if(!vis[it.first]){
            toposo(it.first,st,vis,adj);
        }
        st.push(i);
    }
}
void shortestpath(int src, int n, vector<pair<int,int>> adj[]){
    int vis[n] = {0};
    stack<int> st;
    for(int i= 0; i<n; i++){
        if(!vis[i]){
            findtopo(i,st,vis,adj);
        }
    }
    int dis[n] = {1e9};
    dis[st.top] = 0;
    while(!st.empty()){
        int i = st.top;
        st.pop();
        if(dis[i]!=1e9){
        for(auto it : adj[i]){
                dis[it.first] = min(dis[it.first],dis[i]+adj[it.second]);
        }
    } }
    for(int i=0; i<n; i++){
        (dis[i]==1e9)? cout<<"inf ":cout<<dis[i]<<" ";
    }
}
int main(){
    int n,m; //N-> nodes; M->Edges
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int s,e,wt;
        cin>>s>>e>>wt;
        adj[s].push_back({e,wt});
    }
    shortestpath(0,n,adj);
    return 0;
}
