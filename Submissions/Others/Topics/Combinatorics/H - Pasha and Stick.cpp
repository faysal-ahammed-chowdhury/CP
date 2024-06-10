#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  if (n & 1) {
    cout << 0 << '\n';
    return 0;
  }

  n /= 2;
  int ans = ((n + 1) / 2) - 1;
  cout << ans << '\n';

  return 0;
}