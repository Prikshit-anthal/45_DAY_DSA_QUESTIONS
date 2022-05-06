class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor)
    {
        if (sr >= image.size() || sc >= image[0].size() || sc < 0 || sr < 0)
            return;
        if (image[sr][sc] != oldColor || image[sr][sc] == newColor)
        {
            return;
        }

        image[sr][sc] = newColor;

        // calls
        dfs(image, sr + 1, sc, newColor, oldColor);
        dfs(image, sr, sc + 1, newColor, oldColor);
        dfs(image, sr, sc - 1, newColor, oldColor);
        dfs(image, sr - 1, sc, newColor, oldColor);
    }
};