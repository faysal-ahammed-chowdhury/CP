#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;
int n, m;
int maze[N][N];
int visited[N][N];

long long max(long long a, long long b) {
    return a > b ? a : b;
}

bool is_valid(int row, int col)
{
    return (row >= 0 && row < n && col >= 0 && col < m) ? true : false;
}

bool is_safe(int row, int col)
{
    return (maze[row][col] != 0) ? true : false;
}


long long sum = 0;
void dfs(pair<int, int> src)
{
    int x = src.first;  // col
    int y = src.second; // row

    visited[x][y] = 1;
    sum += maze[x][y];

    int diff[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + diff[i][0]; // row
        int new_y = y + diff[i][1]; // col

        if (is_valid(new_x, new_y) && is_safe(new_x, new_y) && !visited[new_x][new_y])
        {
            dfs({new_x, new_y});
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           cin >> maze[i][j];
           visited[i][j] = 0;
        }
    }

    long long ans = INT_MIN;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pair<int, int> src = {i, j};
            if (maze[i][j] != 0 && !visited[i][j])
            {
                sum = 0;
                dfs(src);
                ans = max(ans, sum);
            }
        }
    }
    cout << (ans == INT_MIN ? 0 : ans) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}