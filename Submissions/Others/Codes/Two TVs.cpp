#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[f, s] : a) {
    cin >> f >> s;
  }

  vector<int> v;
  for (auto [f, s] : a) {
    v.push_back(f);
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (auto &[f, s] : a) {
    f = lower_bound(v.begin(), v.end(), f) - v.begin();
    f++;
    s = lower_bound(v.begin(), v.end(), s) - v.begin();
    s++;
  }

  int m = n + n + 1;
  int d[m + 1];
  memset(d, 0, sizeof d);
  for (auto [f, s] : a) {
    d[f]++;
    d[s + 1]--;
  }

  bool ok = true;
  for (int i = 1; i <= m; i++) {
    d[i] += d[i - 1];
    ok &= d[i] <= 2;
  }

  cout << (ok ? "YES\n" : "NO\n");

  return 0;
}