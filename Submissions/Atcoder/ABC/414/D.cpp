#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  ll a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  ll ans = 0;
  vector<ll> v;
  for (int i = 2; i <= n; i++) {
    ans += a[i] - a[i - 1];
    v.push_back(a[i] - a[i - 1]);
  }
  sort(v.rbegin(), v.rend());
  m--;

  for (int i = 0; i < m; i++) {
    ans -= v[i];
  }  

  cout << ans << '\n';

  return 0;
}