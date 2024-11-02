#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  for (auto &c : s1) {
    c = tolower(c);
  }
  for (auto &c : s2) {
    c = tolower(c);
  }
  sort(s1.rbegin(), s1.rend());
  sort(s2.rbegin(), s2.rend());
  cout << "Case " << ++cs << ": ";
  if (s1.substr(0, s1.find(' ')) == s2.substr(0, s2.find(' '))) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  cin.ignore();
  while(t--) {
    solve();
  }

  return 0;
}