#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s1, s2; cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  if (n != m) {
    int need = abs(m - n);
    string t = "";
    for (int i = 1; i <= need; i++) {
      t += '0';
    }
    if (n < m) {
      s1 = t + s1;
      n = m;
    }
    else {
      s2 = t + s2;
      m = n;
    }
  }

  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      int x = s1[i] - '0', y = s2[i] - '0';
      if (x < y) {
        cout << "<\n";
      }
      else {
        cout << ">\n";
      }
      return 0;
    }
  }

  cout << "=\n";

  return 0;
}