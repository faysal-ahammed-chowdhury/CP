#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  string s = "";
  for (int i = 0; i < k; i++) {
    s += i + 'a';
  }
  string ans = "";
  for (int i = 1; i <= n; i++) {
    ans += s;
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