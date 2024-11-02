#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  if (s[0] == s[1] and s[1] == s[2]) cout << "Yes\n";
  else if (s[1] == s[2] and s[2] == s[3]) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}