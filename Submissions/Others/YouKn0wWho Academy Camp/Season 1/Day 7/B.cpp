#include <bits/stdc++.h>
using namespace std;

#define int long long
double get(int x1, int y1, int x2, int y2) {
  return sqrt((abs(x1 - x2) * abs(x1 - x2)) + (abs(y1 - y2) * abs(y1 - y2)));
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  cout << fixed << setprecision(10);

  cout << get(x1, y1, x2, y2) << '\n';

  return 0;
}