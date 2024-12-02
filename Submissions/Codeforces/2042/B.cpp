#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  int cnt1 = 0, cnt2 = 0;
  for (auto [x, cnt] : mp) {
    if (cnt == 1) cnt1++;
    else cnt2++;
  }

  int ans = ((cnt1 + 1) / 2) * 2;
  ans += cnt2;
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