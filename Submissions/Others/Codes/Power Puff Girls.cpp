#include <bits/stdc++.h>
using namespace std;

const int N = 22;
string s[N];
bool vis[N][N];
int n, m, dis[N][N];

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

bool is_valid(int i, int j) {
  return i >= 0 and i < n and j >= 0 and j < m;
}

bool ok(int i, int j) {
  if (!is_valid(i, j)) return false;
  return !vis[i][j] and s[i][j] != '#' and s[i][j] != 'm';
}

void bfs(int i, int j) {
  queue<pair<int, int>> q;
  dis[i][j] = 0;
  q.push(make_pair(i, j));
  while (!q.empty()) {
    int top_i = q.front().first;
    int top_j = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++) {
      int new_i = top_i + dx[k];
      int new_j = top_j + dy[k];
      if (ok(new_i, new_j)) {
        q.push(make_pair(new_i, new_j));
        vis[new_i][new_j] = true;
        dis[new_i][new_j] = dis[top_i][top_j] + 1;
      }
    }
  }
}

int cs;
void solve() {
  memset(vis, false, sizeof vis);
  memset(dis, 0, sizeof dis);
  cin >> n >> m;
  int ax = -1, ay = -1;
  int bx = -1, by = -1;
  int cx = -1, cy = -1;
  int hx = -1, hy = -1;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'a') ax = i, ay = j;
      else if (s[i][j] == 'b') bx = i, by = j;
      else if (s[i][j] == 'c') cx = i, cy = j;
      else if (s[i][j] == 'h') hx = i, hy = j;
    }
  }
  bfs(hx, hy);
  int ans = max({dis[ax][ay], dis[bx][by], dis[cx][cy]});
  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}