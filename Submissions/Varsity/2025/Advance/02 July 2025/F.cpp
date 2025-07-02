#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  int ans = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt > 0) {
      if (s[i] == 'g') ans++;
      cnt--;
    }
    else {
      if (s[i] == 'p') ans--;
      cnt++;
    }
  }
  cout << ans << '\n';

  return 0;
}