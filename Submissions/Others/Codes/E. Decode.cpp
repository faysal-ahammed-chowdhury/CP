#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = 1e9 + 7;
int psum[N];

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    int x = s[i] == '0' ? 1 : -1;
    psum[i] = psum[i - 1] + x;
  }

  map<int, int> mp;
  mp[0] = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = mp[psum[i]];
    int r = n - i + 1;
    ans = (ans + (1ll * l * r % mod)) % mod;
    mp[psum[i]] = (mp[psum[i]] + (i + 1)) % mod;
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