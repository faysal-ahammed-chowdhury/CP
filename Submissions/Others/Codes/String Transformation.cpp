#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s, t; cin >> s >> t;
  map<char, char> mp1, mp2;

  int n = s.size();
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (mp1.find(s[i]) == mp1.end()) {
      mp1[s[i]] = t[i];
    }
    else {
      if (t[i] != mp1[s[i]]) {
        ok = false;
        break;
      }
    }
    if (mp2.find(t[i]) == mp2.end()) {
      mp2[t[i]] = s[i];
    }
    else {
      if (s[i] != mp2[t[i]]) {
        ok = false;
        break;
      }
    }
  }

  cout << (ok ? "Yes\n" : "No\n");

  return 0;
}