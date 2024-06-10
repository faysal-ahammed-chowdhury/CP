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
  
  int cnt = 1, ans = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i + 1]) {
      cnt++;
    }
    else {
      ans = max(ans, cnt);
      cnt = 1;
    }
  }
  ans = max(ans, cnt);

  cout << ans << '\n';

  return 0;
}