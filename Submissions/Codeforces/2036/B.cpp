#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, k; cin >> n >> k;
  map<int, int> mp;
  for (int i = 1; i <= k; i++) {
    int b, c; cin >> b >> c;
    mp[b] += c;
  }
  vector<int> v;
  for (auto [b, c] : mp) {
    v.push_back(c);
  }
  sort(v.rbegin(), v.rend());

  int m = v.size();
  m = min(m, n);

  int ans = 0;
  for (int i = 0; i < m; i++) {
    ans += v[i];
  }
  cout << ans << '\n';
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