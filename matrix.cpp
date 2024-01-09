#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//Largest Local Values in a Matrix
class Matrix1
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid)
    {
        int n=grid.size();
        vector<vector<int>> res(n-2, vector<int> (n-2));


        for(int i=1; i<=n-2; i++)
        {
            for(int j=1; j<=n-2; j++)
            {
                int maxi=0;
                maxi = max({maxi, grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]});
                maxi = max({maxi, grid[i][j-1], grid[i][j], grid[i][j+1]});
                maxi = max({maxi, grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]});

                res[i-1][j-1] = maxi;
            }
        }
        return res;
    }
};
//Flipping an Image
class Matrix2 {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m=image.size();
        for(int i=0;i<m;i++){
            reverse(image[i].begin(),image[i].end());
        }
        int n=image[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(image[i][j]==0){
                    image[i][j]=1;
                }else{
                    image[i][j]=0;
                }
            }
        }
        return image;
    }
};
//Delete Greatest Value in Each Row
class Matrix3 {
public:
    int deleteGreatestValue(vector<vector<int>>& g) {
        int  row =g.size();
        int col = g[0].size();
        int sum=0;
        int max=-1;
        for(int i=0; i<row; i++){
            sort(g[i].begin(),g[i].end());
        }
        for(int i=0; i<col; i++){ max=0;
            for(int j=0; j<row; j++){
                if(max<g[j][i]){
                    max=g[j][i];}
            }
            sum+=max;
        }
        return sum;
    }
};
// Count Negative Numbers in a Sorted Matrix
class Matrix4 {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]<0){
                    count++;
                }
            }
        }
        return count;
    }
};
//Row With Maximum Ones
class Matrix5 {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        vector<int> res{-1, -1};
        for(int i = 0; i < mat.size(); ++i){
            int one = count(mat[i].begin(), mat[i].end(), 1);
            if(one > res[1])
                res = {i, one};
        }
        return res;
    }
};