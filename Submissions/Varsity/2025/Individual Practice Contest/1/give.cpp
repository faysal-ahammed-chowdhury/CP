#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s, t; cin >> s >> t;

  sort(s.begin(), s.end());

  int idx = -1, i = 0;
  for (auto c : s) {
    if (c != '0') {
      idx = i;
      break;
    }
    i++;
  }

  if (idx == -1) {
    if (s == t) {
      cout << "OK\n";
      return 0;
    }
    cout << "WRONG_ANSWER\n";
    return 0;
  }

  string ans = "";
  ans += s[idx];
  for (int i = 0; i < s.size(); i++) {
    if (i == idx) continue;
    ans += s[i];
  }

  if (ans == t) cout << "OK\n";
  else cout << "WRONG_ANSWER\n";

  return 0;
}