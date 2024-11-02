#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    int cur = a[i] - sum;
    int here = cur * (n - i + 1);
    if (here >= k) {
      ans += k;
      break;
    }
    k -= here;
    ans += here;
    sum += cur;
    ans++;
  }
  cout << ans << '\n';
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