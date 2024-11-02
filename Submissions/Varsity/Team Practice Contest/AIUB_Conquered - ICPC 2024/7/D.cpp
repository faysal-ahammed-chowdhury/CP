#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h; cin >> h;
  int x = (1ll << (h + 1));
  string s; cin >> s;
  int now = 1;
  for (auto c : s) {
    if (c == 'L') {
      now *= 2;
    }
    else {
      now *= 2;
      now++;
    }
  }

  cout << x - now << '\n';

  return 0;
}