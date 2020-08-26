/** check if there is a path from (0, 0) to (n - 1, m - 1) using '.' only **/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 9, M = 1e3 + 9;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
char grid[N][M];
bool vis[N][M];
int n, m;

bool valid(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == '.';
}

bool FloodFill(int r, int c)
{
    if(!valid(r, c)) return false;
    if(r == n - 1 && c == m - 1) return true;
    
    vis[r][c] = true;
    
    bool ret = false;
    for(int i = 0; i < 4; ++i)
    {
        ret |= FloodFill(r + dr[i], c + dc[i]);
    }
    
    return ret;
}

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
    {
        cin >> grid[i][j];
    }
    
    cout << (FloodFill(0, 0) ? "YES" : "NO") << endl;
}