class Solution{
  public:
    vector<int> bfs(int N, vector<int> adj[]){ // N=>No of nodes and adj[] is adjacency list
      vector<int> bfs;
      vector<int> vis(N+1, 0);
      for(int i=1; i<=N; i++){
          if(!vis[i]){
              std::queue<int> q;
              q.push(i);
              vis[i]=1;
              while(!q.empty()){
                  int node = q.front();
                  bfs.push_back(node);
                  q.pop();
                  for(auto i:adj[node]){
                      if(!vis[node]){
                        q.push(i);
                        vis[node]=1;
                      }
                  }
                  
              }
          }
      }
    }
};
