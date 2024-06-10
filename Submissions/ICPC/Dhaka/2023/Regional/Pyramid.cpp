#include <bits/stdc++.h>
using namespace std;

double suface_area;

double fun(double square_area) {
  double base = sqrt(square_area);
  double triangle_area = suface_area - square_area;
  double per_triangle_area = triangle_area / 4;
  double triangle_height = (per_triangle_area * 2) / base;
  double x = base / 2;
  double height = sqrt((triangle_height * triangle_height) - (x * x));
  double volume = (base * base * height) / 3;
  if (x > triangle_height) volume = 0;
  return volume;
}

int cs = 0;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    cin >> suface_area;
    cout << fixed << setprecision(4);
    double l = 0, r = suface_area, ans = -1;
    int it = 100;
    while (it--) {
      double mid1 = l + (r - l) / 3;
      double mid2 = r - (r - l) / 3;
      double x = fun(mid1);
      double y = fun(mid2);
      if (x > y) {
        ans = x;
        r = mid2;
      }
      else {
        l = mid1;
      }
    }

    cout << "Case " << ++cs << ": ";
    cout << ans << '\n';
  }

  return 0;
}