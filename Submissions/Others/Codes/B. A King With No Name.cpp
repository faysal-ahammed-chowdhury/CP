#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1005, inf = 1e18;
int n;
string s[N];
int dis[N][N];
bool vis[N][N][10];

int dx[] = { +0, +0, -1, +1};
int dy[] = { -1, +1, +1, -1};

bool valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= n and s[i][j] != '#';
}

void dijkstra(int i, int j) {
  dis[i][j] = 0;
  priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
  pq.push({0, i, j, 0});
  while (!pq.empty()) {
    auto [d, i, j, dir] = pq.top(); pq.pop();
    if (vis[i][j][dir]) continue;
    vis[i][j][dir] = true;
    // cout << i << ' ' << j << ' ' << dir << ' ' << d << ":\n";
    for (int k = 0; k < 4; k++) {
      int nwi = i + dx[k];
      int nwj = j + dy[k];
      int nwdir = k + 1;
      if (valid(nwi, nwj)) {
          // cout << nwi << ' ' << nwj << ' ' << dis[nwi][nwj] << '\n';
        if (dis[nwi][nwj] >= (d + (nwdir != dir))) {
          dis[nwi][nwj] = (d + (nwdir != dir));
          pq.push({dis[nwi][nwj], nwi, nwj, nwdir});
        }
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int src_i, src_j, dest_i, dest_j;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '@' + s[i];
    for (int j = 1; j <= n; j++) {
      dis[i][j] = inf;
      if (s[i][j] == 'Q') {
        src_i = i, src_j = j;
      }
      if (s[i][j] == 'K') {
        dest_i = i, dest_j = j;
      }
    }
  }

  dijkstra(src_i, src_j);
  int ans = dis[dest_i][dest_j];
  if (ans >= inf) ans = -1;
  cout << ans << '\n';

  return 0;
}