#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (a.empty()) a.push_back(x);
    else if (a.back() != x) a.push_back(x);
  }
  n = a.size();
  vector<pair<int, int>> v;
  bool done[n];
  memset(done, false, sizeof done);
  for (int i = 0; i < n; i++) {
    v.push_back({a[i], i});
  }
  sort(v.rbegin(), v.rend());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto [x, idx] = v[i];
    bool ok = false;
    if (idx - 1 >= 0 and done[idx - 1]) ok = true;
    if (idx + 1 < n and done[idx + 1]) ok = true;
    if (!ok) ans++;
    done[idx] = true;
    // cout << x << ' ' << idx << ' ' << done[idx - 1] << '\n';
  }
  cout << ans << '\n';
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