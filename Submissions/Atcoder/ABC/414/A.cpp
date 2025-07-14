#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, l, r; cin >> n >> l >> r;
  int ans = 0;
  while (n--) {
    int x, y; cin >> x >> y;
    if (x <= l and y >= r) ans++;
  }
  cout << ans << '\n';

  return 0;
}