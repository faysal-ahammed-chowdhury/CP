#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  string ans = s;
  auto get_op = [&](int i) {
    return n - i + 1;
  };
  int half = (n + 1) / 2;
  for (int i = half; i >= 1; i--) {
    ans[i] = s[i];
    ans[get_op(i)] = s[i];
  }
  cout << "Case " << ++cs << ": ";
  if (ans > s) { // case-1 (e.g. 1000)
    cout << ans.substr(1) << '\n';
    return;
  }
  int idx = -1;
  for (int i = half; i >= 1; i--) {
    if (s[i] != '9' or s[get_op(i)] != '9') {
      idx = i;
      break;
    }
  }
  if (idx == -1) { // case-2 (e.g. 9999)
    cout << 1;
    for (int i = 1; i < n; i++) cout << 0;
    cout << 1 << '\n';
    return;
  }
  int op_idx = get_op(idx);
  if (s[idx] <= s[op_idx]) {
    ans[idx]++;
    ans[op_idx] = ans[idx];
    for (int i = idx + 1; i < op_idx; i++) {
      ans[i] = '0';
    }
  }
  cout << ans.substr(1) << '\n';
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