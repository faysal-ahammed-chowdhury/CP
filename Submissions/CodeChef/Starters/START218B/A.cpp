#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int cnt = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    cnt += s[i] == '1';
    cnt -= s[i] == '0';
    if (cnt > 0) ans++;
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