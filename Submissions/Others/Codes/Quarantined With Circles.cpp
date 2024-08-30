#include <bits/stdc++.h>
using namespace std;

const double pi = 2 * acos(0.0);

void solve() {
  double R, n; cin >> R >> n;
  double theta = (360.0 / n) / 2;
  double r = (sin(theta * pi / 180) * R) / (1 - sin(theta * pi / 180));
  double area1 = (theta / 360.0) * pi * R * R;
  double theta2 = 90 - theta;
  double area2 = (theta2 / 360.0) * (pi * r * r);
  double otivuj = (R + r) / cos(theta * pi / 180);
  double area = 0.5 * (R + r) * r * sin(theta2 * pi / 180);
  // cout << area << '\n';
  cout << fixed << setprecision(10) << (area - area1 - area2) * n * 2.0 << '\n';
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