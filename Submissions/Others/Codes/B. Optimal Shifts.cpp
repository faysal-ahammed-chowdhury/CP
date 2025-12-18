#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      v.push_back(i);
    }
  }

  int ans = 0;
  for (int i = 1; i < v.size(); i++) {
    ans = max(ans, v[i] - v[i - 1] - 1);
  }

  ans = max(ans, (n - v.back()) + (v.front() - 1));

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