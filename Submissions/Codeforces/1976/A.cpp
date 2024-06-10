#include <bits/stdc++.h>
using namespace std;

bool sorted(string s) {
  int n = s.size();
  for (int i = 1; i < n; i++) {
    if (s[i] < s[i - 1]) return false;
  }
  return true;
}

void solve() {
  int n; cin >> n;
  string s, s1 = "", s2 = ""; cin >> s;
  bool ok = false;
  for (auto c : s) {
    if (c >='a') ok = true;
    if (ok) s2.push_back(c);
    else s1.push_back(c);
  }
  if (sorted(s1) and sorted(s2)) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
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