#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int val = i * i + j * j;
      int sq = sqrt(val);
      while (sq * sq < val) sq++;
      while (sq * sq > val) sq--;
      if (sq * sq == val and sq <= n) {
        ans++;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}