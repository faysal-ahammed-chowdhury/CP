#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int, int> mp;
  mp[0] = 1;
  long long ans = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i] % m;
    sum %= m;
    ans += mp[sum];
    mp[sum]++;
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
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