#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  if (s == "0") {
    cout << 0 << '\n';
    return 0;
  }
  reverse(s.begin(), s.end());
  int n = s.size();
  int cnt = 0, pos = -1;
  for (int i = 0; i < n; i++) {
    cnt += s[i] == '1';
    pos = i;
  }

  int ans = 0;
  for (int i = 0; i < n; i += 2) {
    ans++;
  }
  if (cnt == 1 and pos % 2 == 0) {
    --ans;
  }

  cout << ans << '\n';

  return 0;
}