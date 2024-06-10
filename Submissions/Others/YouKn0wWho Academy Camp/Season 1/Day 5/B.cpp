#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  if(s[0] == '7' or s[1] == '7' or s[2] == '7') {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }

  return 0;
}