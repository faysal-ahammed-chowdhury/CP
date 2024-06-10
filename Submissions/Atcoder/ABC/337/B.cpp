#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  char last = s[0];
  for (int i = 1; i < s.size(); i++) {
    if (last > s[i]) {
      cout << "No\n";
      return 0;
    }
    last = s[i];
  }

  cout << "Yes\n";

  return 0;
}