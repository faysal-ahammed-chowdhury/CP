#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s1, s2; cin >> s1 >> s2;
  set<char> se;
  for (auto c : s1) {
    se.insert(c);
  }

  for (auto c : s2) {
    if (se.find(c) != se.end()) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}