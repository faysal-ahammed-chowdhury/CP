#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(pair<int, int> x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64((x.first + FIXED_RANDOM) ^ (x.second + FIXED_RANDOM));
  }
};

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }
int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

const int G = 17, N = 22, inf = 1e9;
vector<int> g[G];
string s[N];
bitset<N> vis[N];
int n, m, gold, dis[N][N], dis2[G][G], dp[G][1 << G], stid;
gp_hash_table<pair<int, int>, int, custom_hash> mp;

bool is_valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= m;
}

void bfs(int i, int j) {
  queue<pair<int, int>> q;
  q.push({i, j});
  vis[i][j] = true;
  dis[i][j] = 0;
  while (!q.empty()) {
    pair<int, int> top = q.front(); q.pop();
    for (int k = 0; k < 8; k++) {
      int nwi = top.first + dx[k];
      int nwj = top.second + dy[k];
      if (is_valid(nwi, nwj) and !vis[nwi][nwj]) {
        q.push({nwi, nwj});
        vis[nwi][nwj] = true;
        dis[nwi][nwj] = dis[top.first][top.second] + 1;
      }
    }
  }
}

int dfs(int u, int mask) {
  // cout << u << ' ' << __builtin_popcount(mask) << ' ' << dis2[u][stid] << '\n';
  if (__builtin_popcount(mask) == gold - 1) {
    return dis2[u][stid];
  }
  int &ans = dp[u][mask];
  if (ans != -1) return ans;
  ans = inf;
  for (auto v : g[u]) {
    if (CHECK(mask, v) == false and v != u) {
      ans = min(ans, dis2[u][v] + dfs(v, mask | (1 << u)));
    }
  }
  return ans;
}

int cs;
void solve() {
  mp.clear();
  for (int i = 1; i <= 16; i++) {
    g[i].clear();
  }
  
  cin >> n >> m;
  int id = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'x' or s[i][j] == 'g') {
        mp[ {i, j}] = gold = ++id;
        if (s[i][j] == 'x') stid = mp[ {i, j}];
      }
    }
  }
  // matrix to list
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'x' or s[i][j] == 'g') {
        memset(vis, 0, sizeof vis);
        bfs(i, j);
        for (auto [p, id] : mp) {
          g[mp[ {i, j}]].push_back(id);
          dis2[mp[ {i, j}]][id] = dis[p.first][p.second];
        }
      }
    }
  }
  memset(dp, -1, sizeof dp);
  cout << "Case " << ++cs << ": " << dfs(stid, 0) << '\n';
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