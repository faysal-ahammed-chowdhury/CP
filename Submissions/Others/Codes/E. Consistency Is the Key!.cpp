#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
using i128 = unsigned __int128;
int x, y;

int power[70];
void prec() {
  for (int i = 0; i < 64; i++) {
    power[i] = pow(2, i);
  }
}

bool ok(int sec) {
  int pw = power[sec];
  i128 a = i128(i128(sec) * y) * pw;
  i128 b = i128(pw - 1) * x * 2;
  return a > b;
}

int cs;
void solve() {
  cin >> x >> y;
  cout << "Case #" << ++cs << ": ";
  for (int sec = 1; sec < 64; sec++) {
    if (ok(sec)) {
      cout << sec << '\n';
      return;
    }
  }

  int dis = (x * 2);
  int ans = (dis + y - 1) / y;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}