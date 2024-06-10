#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int rem = n % k;
  int ans = n + (k - rem);
  cout << ans << '\n';

  return 0;
}