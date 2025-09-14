#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3005;
bool vis[N][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }

  vector<pair<int, int>> v;
  v.push_back({1, 1});
  string ans = ""; ans += s[1][1];
  int it = n + n - 2;
  while (it--) {
    // cout << v.size() << '\n';
    char mn = 'Z';
    vector<pair<int, int>> tmp;
    for (auto [i, j] : v) {
      if (i + 1 <= n) {
        mn = min(mn, s[i + 1][j]);
      }
      if (j + 1 <= n) {
        mn = min(mn, s[i][j + 1]);
      }
    }

    for (auto [i, j] : v) {
      // cout << i << ' ' << j << ":\n";
      if (i + 1 <= n and mn == s[i + 1][j] and !vis[i + 1][j]) {
        // cout << i + 1 << ' ' << j << " - ";
        tmp.push_back({i + 1, j});
        vis[i + 1][j] = true;
      }
      if (j + 1 <= n and mn == s[i][j + 1] and !vis[i][j + 1]) {
        // cout << i << ' ' << j + 1 << " - ";
        tmp.push_back({i, j + 1});
        vis[i][j + 1] = true;
      }
      // cout << "\n\n";
    }

    ans += mn;

    v.clear();
    for (auto [i, j] : tmp) {
      v.push_back({i, j});
    }
  }

  cout << ans << '\n';

  return 0;
}