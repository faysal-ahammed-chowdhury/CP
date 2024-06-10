#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  double h, l; cin >> h >> l;
  double x = ((l * l) - (h * h)) / (2 * h);
  cout << fixed << setprecision(10) << x << '\n';

  return 0;
}