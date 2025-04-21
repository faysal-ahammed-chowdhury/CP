#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = ".." + s;

  int cnt = 1;
  int ans[n + 1];
  for (int i = n; i >= 1; i--) {
    if (s[i] == '<') {
      ans[i] = cnt++;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (i == 1 or s[i] == '>') {
      ans[i] = cnt++;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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