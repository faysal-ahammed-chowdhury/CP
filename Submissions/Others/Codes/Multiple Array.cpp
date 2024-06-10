#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  ll ans = 0;
  for (int i = n; i >= 1; i--) {
    ll need = b[i] - (((a[i] + ans) % b[i]) == 0 ? b[i] : ((a[i] + ans) % b[i]));
    ans += need;
  }
  cout << ans << '\n';

  return 0;
}