#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  string s; cin >> s; 
  s = '.' + s;
  ll psum[n + 1];
  psum[0] = 0;
  for (int i = 1; i <= n; i++) {
    psum[i] = psum[i - 1] + a[i];
  }
  int l = 1, r = n;
  ll ans = 0;
  while (l <= r) {
    if (s[l] == 'L' and s[r] == 'R') {
      ans += psum[r] - psum[l - 1];
      l++, r--;
    }
    if (s[l] == 'R') l++;
    if (s[r] == 'L') r--;
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