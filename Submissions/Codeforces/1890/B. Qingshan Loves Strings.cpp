#include <bits/stdc++.h>
using namespace std;

bool is_valid(string s) {
  int n = s.size();
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == s[i + 1]) return false;
  }
  return true;
}

void solve() {
  int n, m; cin >> n >> m;
  string s1, s2; cin >> s1 >> s2;
  if (is_valid(s1)) {
    cout << "Yes\n";
    return;
  }

  if (!is_valid(s2)) {
    cout << "No\n";
    return;
  }

  if (s2[0] != s2[m - 1]) {
    cout << "No\n";
    return;
  }

  if (s2[0] == '0') {
    for (int i = 0; i + 1 < n; i++) {
      if (s1[i] == '0' and s1[i + 1] == '0') {
        cout << "No\n";
        return;
      }
    }
    cout << "Yes\n";
  }
  else {
    for (int i = 0; i + 1 < n; i++) {
      if (s1[i] == '1' and s1[i + 1] == '1') {
        cout << "No\n";
        return;
      }
    }
    cout << "Yes\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}