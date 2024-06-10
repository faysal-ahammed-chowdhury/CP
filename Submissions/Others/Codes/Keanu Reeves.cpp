#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  int cnt0 = 0, cnt1 = 0;
  for (auto c : s) {
    cnt0 += c == '0';
    cnt1 += c == '1';
  }

  if (cnt0 == cnt1) {
    cout << 2 << '\n';
    cout << s.substr(0, n - 1) << ' ' << s[n - 1] << '\n';
  }
  else {
    cout << 1 << '\n';
    cout << s << '\n';
  }

  return 0;
}