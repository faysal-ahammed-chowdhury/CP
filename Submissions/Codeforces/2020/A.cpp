#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, k; cin >> n >> k;
  if (k == 1) {
    cout << n << '\n';
    return;
  }
  vector<int> v;
  for (int i = k; i <= n; i *= k) {
    v.push_back(i);
  }
  int ans = n % k;
  n -= (n % k);
  while (n > 0) {
    ++ans;
    auto it = *(--upper_bound(v.begin(), v.end(), n));
    n -= it;
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