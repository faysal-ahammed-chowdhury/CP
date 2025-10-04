#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int x1, y11, x2, y2; 
int x3, y3, x4, y4; 
int x5, y5, x6, y6; 

bool match(double x, double y) {
  if (x >= x3 and x <= x4 and y >= y3 and y <= y4) return true;
  if (x >= x5 and x <= x6 and y >= y5 and y <= y6) return true;
  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> x1 >> y11 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  cin >> x5 >> y5 >> x6 >> y6;

  bool mismatch = false;
  for (int x = x1; x <= x2; x++) {
    mismatch |= !match(x, y11);
    if (x < x2) mismatch |= !match(x + 0.5, y11);
    mismatch |= !match(x, y2);
    if (x < x2) mismatch |= !match(x + 0.5, y2);
  }

  for (int y = y11; y <= y2; y++) {
    mismatch |= !match(x1, y);
    if (y < y2) mismatch |= !match(x1, y + 0.5);
    mismatch |= !match(x2, y);
    if (y < y2) mismatch |= !match(x2, y + 0.5);
  }

  if (mismatch) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}