#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  vector<int> v;
  int cnt = 1;
  char last = s[0];
  for (int i = 1; i < n; i++) {
    if (s[i] == last) cnt++;
    else {
      v.push_back(cnt);
      cnt = 1;
      last = s[i];
    }
  }
  v.push_back(cnt);
  int ans = 0;
  for (auto x : v) {
    ans += x / 2;
  }
  if (v.size() == 1) {
    cout << ans << '\n';
    return;
  }
  if (s[0] == s[n - 1]) {
    if (v.front() % 2 == 0 and v.back() % 2 == 0) {
      cout << --ans << '\n';
      return;
    }
    if (v.front() % 2 == 1 and v.back() % 2 == 1) {
      cout << ans << '\n';
      return;
    }
    for (int i = 1; i + 1 < v.size(); i++) {
      if (v[i] % 2 == 0) {
        cout << --ans << '\n';
        return;
      }
    }
    cout << ans << '\n';
  }
  else {
    for (auto x : v) {
      if (x % 2 == 0) {
        cout << --ans << '\n';
        return;
      }
    }
    cout << ans << '\n';
  }
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