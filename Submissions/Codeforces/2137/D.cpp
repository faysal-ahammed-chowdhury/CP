#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 8;
int n, b[N], a[N];

void solve() {
  cin >> n;

  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    mp[b[i]].push_back(i);
  }

  int cur = 0;
  for (auto [x, v] : mp) {
    if (v.size() < x or v.size() % x != 0) {
      cout << -1 << '\n';
      return;
    }

    for (int j = 1; j <= (int)v.size(); j++) {
      int idx = v[j - 1];
      if (x == 1) {
        a[idx] = ++cur;
      }
      else {
        if (j % x == 1) cur++;
        a[idx] = cur;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
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