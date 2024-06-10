#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; double d, h; cin >> n >> d >> h;
  double a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  double ans = 0.5 * d * h;
  for(int i = 0; i + 1 < n; i++) {
    if(a[i] + h <= a[i + 1]) {
      ans += (0.5 * h * d);
    }
    else {
      // consider as a trapezoid
      double new_h = (a[i] + h - a[i + 1]);
      double opposite_base = (d * new_h) / h;
      double base = 0.5 * (d + opposite_base);
      ans += ((h - new_h) * base);
    }
  }

  cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}