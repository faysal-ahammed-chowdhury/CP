#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e18;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  int sum = 0, ans = inf;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    if (sum > k) break;
    int need = k - sum;
    ans = min(ans, need);
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