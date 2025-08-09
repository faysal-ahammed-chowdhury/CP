#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;

  int left = k - 1;
  int right = n - k;
  int ans = min(left, right) + 1;

  int tmp1 = k, tmp2 = k;
  for (int i = k + 1; i <= n; i++) {
    tmp2 = i;
    if (s[i] == '#') break;
  }

  for (int i = k - 1; i >= 1; i--) {
    tmp1 = i;
    if (s[i] == '#') break;
  }

  if (tmp1 == 1 and s[1] != '#') tmp1 = 0;
  if (tmp2 == n and s[n] != '#') tmp2 = n + 1;

  if (tmp1 == k and tmp2 == k) {
    cout << ans << '\n';
    return;
  }

  int ans2 = 1 + tmp1;
  int ans3 = 1 + (n + 1) - tmp2;
  int tmp = max(ans2, ans3);

  ans = min(ans, tmp);
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}