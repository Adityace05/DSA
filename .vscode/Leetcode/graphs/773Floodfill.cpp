// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

// Output: [[2,2,2],[2,2,0],[2,0,1]]




// class Solution
// {
// private:
//     void dfs(vector<vector<int>> &copy, int sr, int sc, int color, int iniColor)
//     {
//         copy[sr][sc] = color;
//         int m = copy.size();
//         int n = copy[0].size();

//         if (sr - 1 >= 0 && copy[sr - 1][sc] == iniColor)
//         {
//             dfs(copy, sr - 1, sc, color, iniColor);
//         }
//         if (sr + 1 < m && copy[sr + 1][sc] == iniColor)
//         {
//             dfs(copy, sr + 1, sc, color, iniColor);
//         }
//         if (sc - 1 >= 0 && copy[sr][sc - 1] == iniColor)
//         {
//             dfs(copy, sr, sc - 1, color, iniColor);
//         }
//         if (sc + 1 < n && copy[sr][sc + 1] == iniColor)
//         {
//             dfs(copy, sr, sc + 1, color, iniColor);
//         }
//     }

// public:
//     vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
//     {
//         int iniColor = image[sr][sc];
//         if (iniColor == color)
//             return image;
//         vector<vector<int>> copy = image;

//         dfs(copy, sr, sc, color, iniColor);

//         return copy;
//     }
// };

// time complexity = nxm
// space complexity = nxm