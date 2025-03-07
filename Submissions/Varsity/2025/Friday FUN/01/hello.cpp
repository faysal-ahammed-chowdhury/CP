#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x; cin >> x;
  int ans = 21;
  if (x >= 60) {
    x -= 60;
    ans++;
  }

  cout << ans << ':';
  if (x < 10) cout << '0';
  cout << x << '\n';

  return 0;
}