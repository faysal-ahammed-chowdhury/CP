#include <bits/stdc++.h>
using namespace std;
#include <sys/resource.h>

const int N = 3005;
string s[N];
bool vis[N][N];

int n, m, cnt;

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};
set<pair<int, int>> se;

bool ok(int i, int j) {
  if (!(i >= 0 and i < n and j >= 0 and j < m)) return false;
  if (vis[i][j]) return false;
  if (s[i][j] == 'B') return false;
  return true;
}

void dfs(int i, int j) {
  cnt++;
  vis[i][j] = true;
  for (int k = 0; k < 4; k++) {
    int new_i = i + dx[k];
    int new_j = j + dy[k];
    if (ok(new_i, new_j)) {
      if (s[new_i][new_j] == '.') {
        se.insert({new_i, new_j});
      }
      else dfs(new_i, new_j);
    }
  }
}

int cs = 0;
void solve() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vis[i][j] = false;
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  cout << "Case #" << ++cs << ": ";

  map<pair<int, int>, int> mp;

  int ans = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j] and s[i][j] == 'W') {
        se.clear();
        cnt = 0;
        dfs(i, j);

        int space_cnt = (int) se.size();
        if (space_cnt == 0) {
          ans += cnt;
        }
        else if (space_cnt == 1) {
          for (auto x : se) {
            mp[ {x.first, x.second}] += cnt;
          }
          mx = max(mx, mp[ {(*se.begin()).first, (*se.begin()).second}]);
        }
      }
    }
  }
  ans += mx;
  cout << ans << '\n';
}


int32_t main() {
  rlimit rlim;
  if (getrlimit(RLIMIT_STACK, &rlim)) return 1;
  rlim.rlim_cur = rlim.rlim_max;
  // You can set the fixed value instead of max value, e.g. rlim.rlim_cur = 1024 * 1024 * 1024
  // will set your stack size to 1 GiB
  if (setrlimit(RLIMIT_STACK, &rlim)) return 2;
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}