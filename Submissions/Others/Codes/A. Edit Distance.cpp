#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int cnt0 = 0, cnt1 = 0;
  for (auto c : s) {
    if (c == '0') cnt0++;
    else cnt1++;
  }

  if (cnt0 > cnt1) {
    for (int i = 1; i <= s.size(); i++) {
      cout << 1;
    }
    cout << '\n';
  }
  else if (cnt1 > cnt0) {
    for (int i = 1; i <= s.size(); i++) {
      cout << 0;
    }
    cout << '\n';
  }
  else {
    if (s[0] == '0') cout << 1;
    else cout << 0;
    for (int i = 2; i <= s.size(); i++) {
      cout << s[0];
    }
    cout << '\n';
  }

  return 0;
}