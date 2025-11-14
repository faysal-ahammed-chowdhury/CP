#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const double eps = 1e-6;

double calc(double x) {
  double vat = 0;

  if (x > 12500) {
    double extra = min(50000.0, x) - 12500;
    vat += extra * 0.2;
  }
  if (x > 50000.0) {
    double extra = min(150000.0, x) - 50000;
    vat += extra * 0.4;
  }
  if (x > 150000) {
    double extra = x - 150000;
    vat += extra * 0.45;
  }

  if (x > 100000) {
    double extra = x - 100000;
    extra /= 2;
    extra = min(extra, 12500.0);
    vat += extra * 0.4;
  }
  return vat;
}

void solve() {
  double vat; cin >> vat;

  double l = 0, r = 200000000000;
  int it = 100;
  double ans;
  while (it--) {
    double mid = (l + r) / 2.0;
    if (calc(mid) >= vat) {
      // cout << mid << ' ' << calc(mid) << '\n';
      ans = mid;
      r = mid;
    }
    else l = mid;
  }

  cout << fixed << setprecision(10);
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