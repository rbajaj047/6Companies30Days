class Solution {
public:
    vector<vector<int>> dir = {{0,0},{0,-1},{-1,0},{1,0},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};

    bool isValid(int nx, int ny, int n, int m)
    {    
        return (nx>=0 && ny>=0 && nx<n && ny<m);
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum = 0, ct = 0;
                for(auto &it:dir)
                {
                    int nx = i+it[0];
                    int ny = j+it[1];
                    if(isValid(nx,ny,n,m))
                    {
                        sum+=img[nx][ny];
                        ct+=1;
                    }
                }
                ans[i][j] = sum/ct;
            }
        }
        return ans;
    }
};
