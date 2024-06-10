#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int, int> mp;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += mp[a[i]];
    if (a[i] == 1) {
      ans += mp[2];
    }
    if (a[i] == 2) {
      ans += mp[1];
    }
    mp[a[i]]++;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}