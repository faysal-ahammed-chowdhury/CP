#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x, y; cin >> x >> y;
  double xpowy = 1LL * y * log10(x);
  double ypowx = 1LL * x * log10(y);

  if(xpowy == ypowx) {
    cout << "=\n";
  }
  else if(xpowy > ypowx) {
    cout << ">\n";
  }
  else {
    cout << "<\n";
  }

  return 0;
}