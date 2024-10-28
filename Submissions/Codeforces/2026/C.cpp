#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;

  int cnt = 0, discount = 0;
  for (int i = n; i >= 2; i--) {
    if (s[i] == '1' and (i - 1 - cnt) > 0) {
      discount += i;
      cnt++;
      continue;
    }
    if (cnt > 0) cnt--;
  }
  
  int tot = (n * (n + 1)) / 2;
  cout << tot - discount << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}