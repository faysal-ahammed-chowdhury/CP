#include <bits/stdc++.h>
using namespace std;

int p1, p2, a1, a2, b1, b2;

double get_distance(int x1, int y1, int x2, int y2) {
  return sqrt((abs(x1 - x2) * abs(x1 - x2)) + (abs(y1 - y2) * abs(y1 - y2)));
}

bool ok(double radius) {
  if (get_distance(p1, p2, a1, a2) <= radius and get_distance(0, 0, a1, a2) <= radius) {
    return true;
  }
  if (get_distance(p1, p2, b1, b2) <= radius and get_distance(0, 0, b1, b2) <= radius) {
    return true;
  }
  if (get_distance(p1, p2, b1, b2) <= radius) {
    if (get_distance(0, 0, a1, a2) <= radius) {
      if (get_distance(a1, a2, b1, b2) <= 2 * radius) {
        return true;
      }
      else {
        return false;
      }
    }
    else {
      return false;
    }
  }
  else if ((get_distance(p1, p2, a1, a2) <= radius)) {
    if (get_distance(0, 0, b1, b2) <= radius) {
      if (get_distance(a1, a2, b1, b2) <= 2 * radius) {
        return true;
      }
      else {
        return false;
      }
    }
    else {
      return false;
    }
  }
  return false;
}

void solve() {
  cin >> p1 >> p2 >> a1 >> a2 >> b1 >> b2;
  double l = 0, r = 1e9, ans = 0;
  int it = 100;
  while (it--) {
    double mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid;
    }
    else {
      l = mid;
    }
  }
  cout << fixed << setprecision(10) << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}