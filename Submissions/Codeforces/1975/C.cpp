#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 1; i + 1 <= n; i++) {
    if (a[i] <= a[i + 1]) {
      ans = max(ans, a[i]);
    }
    else {
      ans = max(ans, a[i + 1]);
    }
  }

  for (int i = 1; i + 2 <= n; i++) {
    vector<int> v;
    v.push_back(a[i]);
    v.push_back(a[i + 1]);
    v.push_back(a[i + 2]);
    sort(v.begin(), v.end());
    ans = max(ans, v[1]);
  }

  sort(a + 1, a + n + 1);
  ans = max(ans, a[(n + 1) / 2]);
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