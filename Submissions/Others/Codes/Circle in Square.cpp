#include <bits/stdc++.h>
using namespace std;

const double pi = 2 * acos (0.0);

int cs;
void solve() {
  double r; cin >> r;
  double d = r + r;
  double area_sq = d * d;
  double area_circle = pi * r * r;
  cout << "Case " << ++cs << ": ";
  cout << fixed << setprecision(2) << area_sq - area_circle << '\n';
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