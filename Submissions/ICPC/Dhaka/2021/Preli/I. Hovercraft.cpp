#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
double l, w;

double fun(double d) {
  double up = l - d;
  double x = sqrt((d * d) - (up * up));
  double y = w - x;
  return d + d + y;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin >> l >> w and l != 0 and w != 0) {
    double low = l / 2.0, high = l, ans = -1;
    int it = 100;
    while(it--) {
      double mid1 = low + (high - low) / 3;
      double mid2 = high - (high - low) / 3;
      double x = fun(mid1);
      double y = fun(mid2);
      if(x > y) {
        ans = x;
        low = mid1;
      }
      else {
        high = mid2;
      }
    }
    cout << fixed << setprecision(4) << ans << '\n';
  }

  return 0;
}