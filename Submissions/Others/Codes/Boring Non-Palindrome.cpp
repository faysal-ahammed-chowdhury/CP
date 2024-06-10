#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string &s) {
  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r]) return false;
    l++, r--;
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  int idx = 0;
  for (int i = 1; i <= n; i++) {
    string str = s.substr(i, n - i + 1);
    if (is_palindrome(str)) {
      idx = i - 1;
      break;
    }
  }

  for (int i = idx; i >= 1; i--) {
    s += s[i];
  }

  cout << s.substr(1) << '\n';

  return 0;
}