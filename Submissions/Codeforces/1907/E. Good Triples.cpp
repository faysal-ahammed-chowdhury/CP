#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  long long ans = 1;
  while (n > 0) {
    int last = n % 10;
    n /= 10;
    int cnt = 0;
    for (int i = 0; i <= last; i++) {
      for (int j = 0; j <= last; j++) {
        for (int k = 0; k <= last; k++) {
          if (i + j + k == last) {
            cnt++;
          }
        }
      }
    }
    ans *= cnt;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}