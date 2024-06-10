#include <bits/stdc++.h>
using namespace std;

char get(char a, char b) {
  for (char c = 'a'; c <= 'z'; c++) {
    if (c != a and c != b) return c;
  }
  return '.';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      if (i + 1 < n) {
        s[i] = get(s[i - 1], s[i + 1]);
      }
      else {
        s[i] = get(s[i - 1], s[i - 1]);
      }
    }
  }

  cout << s << '\n';

  return 0;
}