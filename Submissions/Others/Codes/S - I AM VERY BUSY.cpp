#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a + 1, a + n + 1);
  int ans = 0, last = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i].second >= last) {
      ans++;
      last = a[i].first;
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}