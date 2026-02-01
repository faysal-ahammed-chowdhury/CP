#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  vector<int> v;
  int cnt = 0, ans = 0;

  if (n == 1) {
    cout << 1 << '\n';
    return;
  }

  if (s[1] == '0' and s[2] == '0') {
    s[2] = '1';
  }
  if (s[n] == '0' and s[n - 1] == '0') {
    s[n - 1] = '1';
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      cnt++;
    }
    else {
      ans++;
      if (cnt) v.push_back(cnt);
      cnt = 0;
    }
  }
  if (cnt) v.push_back(cnt);

  for (int i = 0; i < v.size(); i++) {
    int x = v[i];
    ans += x / 3;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}