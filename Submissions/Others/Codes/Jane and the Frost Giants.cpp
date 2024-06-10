#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 205;
string s[N];
bool vis[N][N];
int n, m, dis_from_fire[N][N], dis[N][N];

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

bool is_valid(int i, int j) {
  return i >= 0 and i < n and j >= 0 and j < m;
}

bool ok(int i, int j) {
  if (!is_valid(i, j)) return false;
  return !vis[i][j] and s[i][j] != '#';
}

int cs;
void solve() {
  memset(vis, false, sizeof vis);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dis_from_fire[i][j] = 1000;
    }
  }
  memset(dis, false, sizeof dis);
  cin >> n >> m;
  queue<pii> q;
  int jane_i, jane_j;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'F') {
        q.push(make_pair(i, j));
        dis_from_fire[i][j] = 0;
        vis[i][j] = true;
      }
      else if (s[i][j] == 'J') jane_i = i, jane_j = j;
    }
  }
  // multi src bfs from fire
  while (!q.empty()) {
    int top_i = q.front().first;
    int top_j = q.front().second;
    q.pop();
    for (int k = 0; k < 4; k++) {
      int new_i = top_i + dx[k];
      int new_j = top_j + dy[k];
      if (ok(new_i, new_j)) {
        dis_from_fire[new_i][new_j] = dis_from_fire[top_i][top_j] + 1;
        vis[new_i][new_j] = true;
        q.push(make_pair(new_i, new_j));
      }
    }
  }
  // bfs from jane's position
  q.push(make_pair(jane_i, jane_j));
  dis[jane_i][jane_j] = 0;
  memset(vis, false, sizeof vis);
  bool flag = false;
  int ans = 500;
  while (!q.empty()) {
    int top_i = q.front().first;
    int top_j = q.front().second;
    q.pop();
    if (top_i == 0 or top_i == n - 1 or top_j == 0 or top_j == m - 1) {
      flag = true;
      ans = min(ans, dis[top_i][top_j]);
    }
    for (int k = 0; k < 4; k++) {
      int new_i = top_i + dx[k];
      int new_j = top_j + dy[k];
      if (ok(new_i, new_j) and dis[top_i][top_j] + 1 < dis_from_fire[new_i][new_j]) {
        dis[new_i][new_j] = dis[top_i][top_j] + 1;
        vis[new_i][new_j] = true;
        q.push(make_pair(new_i, new_j));
      }
    }
  }
  cout << "Case " << ++cs << ": ";
  if (flag) cout << ++ans << '\n';
  else cout << "IMPOSSIBLE\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}