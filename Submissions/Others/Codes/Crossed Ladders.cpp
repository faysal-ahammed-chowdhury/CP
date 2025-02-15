#include <bits/stdc++.h>
using namespace std;

struct pt {
  double x, y;
  pt() {}
  pt(double _x, double _y) : x(_x),
    y(_y) {}
  pt operator-(const pt& p) const {
    return
      pt(x - p.x, y - p.y);
  }
  double cross(const pt& p) const {
    return x * p.y - y * p.x;
  }
  double cross(const pt& a, const pt& b)
  const {
    return (a - *this).cross(b - *this);
  }
};
int sgn(const double& x) {
  return x >= 0
         ? x ? 1 : 0 : -1;
}
bool inter1(double a, double b, double c, double d) {
  if (a > b)
    swap(a, b);
  if (c > d)
    swap(c, d);
  return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d, pt& intersection) {
  // Checking if the lines are collinear
  if (c.cross(a, d) == 0 && c.cross(b, d) == 0) {
    // Lines are collinear, check for overlap in the bounding box
    if (inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y)) {
      intersection = a; // Set intersection to a point on line a-b (since they're collinear)
      return true;
    }
    return false;
  }

  // Checking if the lines intersect
  if (sgn(a.cross(b, c)) != sgn(a.cross(b, d)) && sgn(c.cross(d, a)) != sgn(c.cross(d, b))) {
    // Use the determinant formula to calculate the intersection point
    double denominator = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);

    if (denominator != 0) {
      // Calculate the intersection point using the formula for parametric equations
      double t = ((c.x - a.x) * (d.y - c.y) - (c.y - a.y) * (d.x - c.x)) / denominator;
      intersection = pt(a.x + t * (b.x - a.x), a.y + t * (b.y - a.y));
      return true;
    }
  }
  return false;
}

double x, y, k;

bool ok(double w) {
  double h1 = sqrt((x * x) - (w * w));
  double h2 = sqrt((y * y) - (w * w));


  pt p1 = {0, 0};
  pt p2 = {w, h1};
  pt p3 = {w, 0};
  pt p4 = {0, h2};

  // cout << p1.x << ' ' << p1.y << '\n';
  // cout << p2.x << ' ' << p2.y << '\n';
  // cout << p3.x << ' ' << p3.y << '\n';
  // cout << p4.x << ' ' << p4.y << '\n';

  pt p;
  if (!check_inter(p1, p2, p3, p4, p)) return false;
  // cout << p.y << '\n';
  return p.y >= k;
}

int cs;
void solve() {
  cin >> x >> y >> k;
  double l = 0, r = min(x, y), ans = 0;
  int it = 100;
  while (it--) {
    double mid = (l + r) / 2.0;
    if (ok(mid)) {
      ans = mid;
      l = mid;
    }
    else r = mid;
  }
  cout << fixed << setprecision(10); 
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