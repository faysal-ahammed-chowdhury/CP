#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n; cin >> n;
  if (n > 20) {
    cout << "0000\n";
    return;
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = 1ll * ans * i % 10000;
  }
  string s = to_string(ans);
  int len = s.size();
  for (int i = 1; i <= 4 - len; i++) {
    cout << 0;
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