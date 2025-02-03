#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<pair<int, int>> col[N];
int row[N], tim[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, w; cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> y >> x;
    col[y].push_back({x, i});
  }

  int mn = 1e9;
  for (int i = 1; i <= w; i++) {
    mn = min(mn, (int)col[i].size());
  }

  for (int i = 1; i <= w; i++) {
    int j = 1;
    for (auto [r, idx] : col[i]) {
      row[idx] = j;
      j++;
    }
  }


  for (int j = 0; j < mn; j++) {
    int x = 0;
    for (int i = 1; i <= w; i++) {
      x = max(x, col[i][j].first);
    }
    tim[j + 1] = x;
    // cout << j << ' ' << x << '\n';
  }

  // cout << row[1] << '\n';

  int q; cin >> q;
  while (q--) {
    int t, a; cin >> t >> a;
    int x = tim[row[a]];
    if (x == 0) cout << "Yes\n";
    else if (t < x) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}