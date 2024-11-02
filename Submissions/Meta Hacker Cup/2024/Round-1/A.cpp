#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000000 + 9, inf = 1e18;
const double eps = 1e-6;
array<double, 2> a[N];
int n;

int cs;
void solve() {
  cin >> n;
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    double mx = (x == 0 ? inf : (double)(i) / x);
    double mn = (y == 0 ? inf : (double)(i) / y);
    a[i] = {mn, mx};
    if (y == 0) flag = true;
  }

  cout << fixed << setprecision(10);
  cout << "Case #" << ++cs << ": "; 
  if (flag) {
    cout << -1 << '\n';
    return;
  }
  sort(a + 1, a + n + 1);
  double mn_right = inf, ans;
  for (int i = 1; i <= n; i++) {
    double mn = a[i][0];
    double mx = a[i][1];
    if (mn <= mn_right + eps) {
      ans = mn;
      mn_right = min(mn_right, mx);
    }
    else {
      cout << -1 << '\n';
      return;
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}