#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ans = (1 << n) - 1 - n;
  cout << ans << '\n';

  return 0;
}