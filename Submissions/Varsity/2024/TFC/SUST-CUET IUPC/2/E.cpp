#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  
  vector<int> v;
  int last = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == s[i - 1]) {
      v.push_back(i - last);
      last = i;
    }
  }
  v.push_back(n - last + 1);

  int ans = 0;
  for (auto x : v) {
    ans += (x / 3);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}