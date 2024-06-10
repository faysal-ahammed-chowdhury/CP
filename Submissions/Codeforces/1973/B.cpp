#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> v[34];
  for (int k = 0; k < 30; k++) {
    v[k].push_back(0);
  }
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < 30; k++) {
      if (CHECK(a[i], k)) {
        v[k].push_back(i);
      }
    }
  }
  for (int k = 0; k < 30; k++) {
    v[k].push_back(n + 1);
  }

  int ans = 1;
  for (int k = 0; k < 30; k++) {
    int mx = 0;
    int sz = v[k].size();
    if (sz == 2) continue;
    for (int i = 1; i < sz; i++) {
      mx = max(mx, v[k][i] - v[k][i - 1]);
    }
    ans = max(ans, mx);
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