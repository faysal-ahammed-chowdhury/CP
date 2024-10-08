#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int x = 1;
  cout << x << endl;
  while (true) {
    int y; cin >> y;
    if (y == 99) return 0;
    if (y % 3) {
      int rem = 3 - (y % 3);
      x = y + rem;
      cout << x << endl;
    }
    else {
      x = y + 2;
      cout << x << endl;
    }
    if (x == 99) return 0;
  }

  return 0;
}
