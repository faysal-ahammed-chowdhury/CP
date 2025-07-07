#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ll ans = -1e9, sum = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    sum += x;
    ans = max(ans, sum);
    sum = max(0ll, sum);
  }

  cout << ans << '\n';

  return 0;
}