#include <bits/stdc++.h>
using namespace std;

#define len(x) (int)x.size()
#define ll long long

void solve() {
  ll a, s; cin >> a >> s;
  vector<int> b;
  while (s > 0) {
    int x = a % 10;
    int y = s % 10;
    a /= 10, s /= 10;
    if (x <= y) b.push_back(y - x);
    else {
      y += 10 * (s % 10);
      s /= 10;
      if (x < y and y >= 10 and y <= 19) b.push_back(y - x);
      else {
        cout << -1 << '\n';
        return;
      }
    }
  }

  if (a > 0) {
    cout << -1 << '\n';
    return;
  }
  else {
    while (b.back() == 0) b.pop_back();
    for (int i = len(b) - 1; i >= 0; i--) {
      cout << b[i];
    }
    cout << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}