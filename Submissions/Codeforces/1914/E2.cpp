#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> x, pair<int , int> y) {
  long long d1 = abs(1ll * x.first - x.second);
  long long d2 = abs(1ll * y.first - y.second);
  return d2 < d1;
}

void solve() {
  int n; cin >> n;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].first--;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
    a[i].second--;
    a[i].second = -a[i].second;
  }
  sort(a + 1, a + 1 + n, cmp);

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      ans += a[i].first;
    }
    else {
      ans += a[i].second;
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}