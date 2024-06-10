#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if ((a[i] + a[j] + a[k] == 3) and ((a[i] ^ a[j]) ^ a[k])) {
          cout << i << '^' << j << '^' << k << " = " << ((a[i] ^ a[j]) ^ a[k]) << '\n';
          sum += ((a[i] ^ a[j]) ^ a[k]);
        }
      }
    }
  }
  cout << sum << '\n';

  return 0;
}