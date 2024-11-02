#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int last = -1e9;
  int ans[n + 1];
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) last = i;
    ans[i] = i - last;
  }
  last = 1e9;
  for (int i = n; i >= 1; i--) {
    if (a[i] == 0) last = i;
    ans[i] = min(ans[i], last - i);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}