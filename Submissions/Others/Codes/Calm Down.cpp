#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  double R, n; cin >> R >> n;
  double theta = (360.0 / n) / 2;
  double pi = 2 * acos(0.0);
  theta = theta * pi / 180;
  double ans = (sin(theta) * R) / (1 + sin(theta));
  cout << "Case " << ++cs << ": ";
  cout << fixed << setprecision(10) << ans << '\n';
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