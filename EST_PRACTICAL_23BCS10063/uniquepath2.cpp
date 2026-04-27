class Solution {
    int function(vector<vector<int>>& obstacleGrid, int m,int n, vector<vector<int>>& dp){
        if(m<0 || n<0) return 0;
        if(obstacleGrid[m][n]==1) return 0;
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]=function(obstacleGrid,m-1,n,dp)+function(obstacleGrid,m,n-1,dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return function(obstacleGrid,m-1,n-1,dp);
    }
};