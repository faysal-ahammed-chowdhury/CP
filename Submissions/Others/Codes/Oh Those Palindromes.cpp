#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  string ans = s;
  sort(ans.begin(), ans.end());
  cout << ans << '\n';

  return 0;
}