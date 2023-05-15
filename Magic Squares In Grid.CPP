class Solution {
public:
    bool ismagsq(vector<vector<int>> &grid , int i , int j){
        if(i+2 < grid.size() && j+2 < grid[0].size()){
            int c1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
            int c2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
            int c3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
            int r1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            int r2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
            int r3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
            int d1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
            int d2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

            if((c1==c2) && (c1==c3) && (c1==r1) && (c1==r2) && (c1==r3) && (c1==d1) && (c1==d2)){
                set<int> s({1,2,3,4,5,6,7,8,9});
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++) s.erase(grid[i+k][j+l]);
                }
                return s.empty();
            }
        }
        return 0;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int cnt = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(ismagsq(grid, i, j)) cnt++;
            }
        }
        return cnt;
    }
};
