#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (i + j + k == n and __gcd(i, j) == k and i != j and j != k and i != k) {
          cout << i << ' ' << j << ' ' << k << '\n';
        } 
      }
    }
  }

  return 0;
}