#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, w, tim[N], row[N];
vector<pair<int, int>> col[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    col[x].push_back({y, i});
  }

  int mn = 2e9;
  for (int i = 1; i <= w; i++) {
    mn = min(mn, (int)col[i].size());
  }

  for (int j = 0; j < mn; j++) {
    int mx = 0;
    for (int i = 1; i <= w; i++) {
      mx = max(mx, col[i][j].first);
      // cout << col[i][j] << ' ';
    }
    for (int i = 1; i <= w; i++) {
      row[col[i][j].second] = j + 1;
    }
    tim[j + 1] = mx;
    // cout  << '\n';
  }

  int q; cin >> q;
  while (q--) {
    int t, a; cin >> t >> a;
    if (tim[row[a]] == 0) cout << "Yes\n";
    else if (tim[row[a]] > t) cout << "Yes\n";
    else cout << "No\n";
    // cout << tim[1] << '\n';
  }

  return 0;
}