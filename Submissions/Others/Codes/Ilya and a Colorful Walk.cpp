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

  int ans = 0;
  for (int i = n; i > 1; i--) {
    if (a[i] != a[1]) {
      ans = i - 1;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[n]) {
      ans = max(ans, n - i);
      break;
    }
  }

  cout << ans << '\n';
 
  return 0;
}