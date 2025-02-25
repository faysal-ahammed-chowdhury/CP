#include <bits/stdc++.h>
using namespace std;

void solve() {
  int k; cin >> k;
  vector<pair<int, int>> v;

  int y = 1, x = 1;
  while (k > 0) {
    int done = 0;
    for (int i = 1; ; i++) {
      if (((i * (i - 1)) / 2) <= k) {
        done = ((i * (i - 1)) / 2);
        v.push_back({x, y});
        x++;
      }
      else break;
    }
    y++;
    k -= done;
  }

  cout << v.size() << '\n';
  for (auto [x, y] : v) {
    cout << x << ' ' << y << '\n';
  }
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