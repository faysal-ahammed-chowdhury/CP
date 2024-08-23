#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  if (!(n & 1)) cout << -1 << '\n';
  else {
    int a[n + 1];
    int mid = (n + 1) / 2;
    a[mid] = 1;
    int l = mid - 1, r = mid + 1, cur = 2;
    while (l >= 1 and r <= n) {
      a[r] = cur++;
      a[l] = cur++;
      l--, r++;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}