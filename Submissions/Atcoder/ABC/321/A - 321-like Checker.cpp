#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for(int i = 0; i + 1 < s.length(); i++) {
    if(s[i] <= s[i + 1]) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";

  return 0;
}