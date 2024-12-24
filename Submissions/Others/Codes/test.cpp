#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int d = 1; d <= 24; d++) {
    for (int i = 1; i <= 9; i += 6) {
      int x = 0;
      for (int j = 1; j <= d; j++) {
        x *= 10;
        x %= 7;
        x += i;
        x %= 7;
      }
      if (x % 7 == 0) {
        cout << d << ": " << i << '\n';
      }
    }
  }

  return 0;
}