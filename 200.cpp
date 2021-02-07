200. Number of Islands
Medium

Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1



class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& c){
        if(i<0||i>=c.size()||j<0||j>=c[0].size()){
            return;
        }
        c[i][j]='0';
        bfs(i+1,j,c);
        bfs(i,j+1,c);
        //bfs(i-1,j,c);
        //bfs(i,j-1,c);
    }
    int numIslands(vector<vector<char>>& c) {
        int m = c.size();
        int count = 0;
        int n = c[0].size();
        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if(c[i][j]=='1'){
                    count+=1;
                    bfs(i, j, c);
                }
            }
        }
        return count;
    }
};
