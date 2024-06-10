#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

bool ok(int p) {
  string str = "";
  str += s.substr(p);
  string x = s.substr(0, p);
  reverse(x.begin(), x.end());
  str += x;
  bool ans = true;
  for (int i = 1; i < k; i++) {
    ans &= str[i] == str[i - 1];
  }
  for (int i = 0; i + k < n; i++) {
    ans &= str[i] != str[i + k];
  }
  return ans;
}

void solve() {
  cin >> n >> k >> s;
  int cnt = 0;
  for (auto c : s) {
    cnt += c == '1';
  }
  if (cnt % k or (n - cnt) % k) {
    cout << -1 << '\n';
    return;
  }
  int p = -1;
  for (int i = 0; i < n;) {
    ++i;
    bool flag = false;
    for (int j = 1; j < k; j++, i++) {
      if (s[i] != s[i - 1]) {
        p = i;
        flag = true;
        break;
      }
    }
    if (flag) break;
  }
  if (ok(0)) {
    cout << n << '\n';
    return;
  }
  if (p == -1) {
    for (int i = 0; i + k < n; i++) {
      if (s[i] == s[i + k]) {
        p = i + k;
        break;
      }
    }
  }
  if (ok(p)) cout << p << '\n';
  else if (p - k >= 0 and ok(p - k)) cout << p - k << '\n';
  else cout << -1 << '\n';
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