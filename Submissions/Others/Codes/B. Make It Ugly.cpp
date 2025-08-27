#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  bool all_same = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i > 1) all_same &= a[i] == a[i - 1];
  }

  if (all_same) {
    cout << -1 << '\n';
    return;
  }

  vector<int> v;
  v.push_back(0);
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[1]) {
      v.push_back(i);
    }
  }
  v.push_back(n + 1);

  int ans = n;
  for (int i = 1; i < (int)v.size(); i++) {
    ans = min(ans, v[i] - v[i - 1] - 1);
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