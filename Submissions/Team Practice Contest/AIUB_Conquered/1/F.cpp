#include <bits/stdc++.h>
using namespace std;

int beauty(string &s) {
  int cnt = 0, ans = 0;
  for (auto c : s) {
    if (c == '(') cnt++;
    else if (cnt > 0 and c == ')') {
      cnt--;
      ans += 2;
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  cout << beauty(s) << '\n';

  return 0;
}