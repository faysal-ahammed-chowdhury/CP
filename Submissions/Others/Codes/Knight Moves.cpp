#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 105;
int n, m, level[N][N];
bool vis[N][N];

int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

bool is_valid(int x, int y) {
  if(x >= 1 && x <= n && y >= 1 && y <= m) return true;
  return false;
}

void bfs(int i, int j) {
  queue<pair<int, int>> q;
  q.push({i, j});
  vis[i][j] = true;
  level[i][j] = 0;
  while(!q.empty()) {
    pair<int, int> top = q.front(); q.pop();
    for(int k = 0; k < 8; k++) {
      int new_i = top.first + dx[k];
      int new_j = top.second + dy[k];
      if(is_valid(new_i, new_j)  && !vis[new_i][new_j]) {
        level[new_i][new_j] = level[top.first][top.second] + 1;
        q.push({new_i, new_j});
        vis[new_i][new_j] = true;
      }
    }
  }
}

void solve() {
   cin >> n >> m;
   for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      vis[i][j] = 0;
      level[i][j] = -1;
    }
   }
   int a, b; cin >> a >> b;
   int c, d; cin >> c >> d;
   a++, b++, c++, d++;

   bfs(a, b);

   // for(int i = 1; i <= n; i++) {
   //  for(int j = 1; j <= m; j++) {
   //    cout << level[i][j] << ' ';
   //  }
   //  cout << '\n';
   // }

   cout << level[c][d] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}