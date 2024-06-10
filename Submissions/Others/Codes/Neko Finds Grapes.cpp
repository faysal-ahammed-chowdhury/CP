#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  map<int, int> mp1, mp2;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    x %= 2;
    mp1[x]++;
  }
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    x %= 2;
    mp2[x]++;
  }

  int ans = min(mp1[0], mp2[1]) + min(mp1[1], mp2[0]);
  cout << ans << '\n';

  return 0;
}