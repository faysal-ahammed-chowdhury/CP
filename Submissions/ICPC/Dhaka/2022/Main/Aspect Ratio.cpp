#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cs;
void solve() {
  double k; cin >> k;
  double ans = sqrtl(((k * k) - 1) / (4 - (k * k)));
  cout << fixed << setprecision(4);
  cout << "Case " << ++cs << ": " << ans << '\n';
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