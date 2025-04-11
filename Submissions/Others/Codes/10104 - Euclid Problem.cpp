#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  while (cin >> a >> b) {
    int x, y;
    int g = gcd(a, b, x, y);
    cout << x << ' ' << y << ' ' << g << '\n';
  }

  return 0;
}