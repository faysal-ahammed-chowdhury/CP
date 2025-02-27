#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, x, k; cin >> n >> x >> k;
  string s; cin >> s;

  int xx = x;
  int sec = 1;
  bool here = false;
  for (auto c : s) {
    if (c == 'L') xx--;
    else xx++;

    if (xx == 0) {
      here = true;
      break;
    }
    sec++;
  }

  xx = 0;
  int sec2 = 1;
  bool here2 = false;
  for (auto c : s) {
    if (c == 'L') xx--;
    else xx++;

    if (xx == 0) {
      here2 = true;
      break;
    }
    sec2++;
  }

  if (!here) {
    cout << 0 << '\n';
    return;
  }

  int ans = 1;
  if (!here2) {
    cout << ans << '\n';
    return;
  }

  k -= sec;

  ans += (k / sec2);

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