#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();

  int i = 0, j = n - 1;
  int ans = 0;
  while (i < j) {
    ans += s[i] != s[j];
    i++, j--;
  }
  cout << ans << '\n';

  return 0;
}