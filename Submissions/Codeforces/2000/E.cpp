#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m, k;

ll get(int i, int j) {
  int u = max(1, i - k + 1);
  int d = min(n, i + k - 1) - k + 1;
  int l = max(1, j - k + 1);
  int r = min(m, j + k - 1) - k + 1;
  return 1ll * (d - u + 1) * (r - l + 1);
}

void solve() {
  cin >> n >> m >> k;
  int w; cin >> w;
  int a[w + 1];
  for (int i = 1; i <= w; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + w + 1);
  reverse(a + 1, a + w + 1);
  vector<ll> v;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      v.push_back(get(i, j));
    }
  }
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  for (int i = 1; i <= w; i++) {
    ans += 1ll * a[i] * v[i - 1];
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}