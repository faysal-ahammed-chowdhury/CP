#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 50005;
int n, a[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int sq = sqrt(2 * (n + 1)) + 1;
  // cout << sq << '\n';

  set<array<int, 3>> se, first_bench;
  for (int i = 0; i <= sq; i++) {
    for (int j = 0; j <= sq; j++) {
      int x = 3 * i + 1;
      int y = 3 * j + 1;
      first_bench.insert({x + y, x, y});
      se.insert({x + y, x, y});

      x = 3 * i + 1;
      y = 3 * j + 2;
      se.insert({x + y, x, y});

      x = 3 * i + 2;
      y = 3 * j + 1;
      se.insert({x + y, x, y});

      x = 3 * i + 2;
      y = 3 * j + 2;
      se.insert({x + y + 2, x, y});
    }
  }

  // for (auto [d, x, y] : first_bench) {
  //   cout << d << ' ' << x << ' ' << y << '\n';
  // }

  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      auto [d, x, y] = *se.begin();
      cout << x << ' ' << y << '\n';
      // cout << d << ' ' << x << ' ' << y << '\n';
      se.erase(se.begin());
      first_bench.erase({d, x, y});
    }
    else {
      auto [d, x, y] = *first_bench.begin();
      cout << x << ' ' << y << '\n';
      // cout << d << ' ' << x << ' ' << y << '\n';
      first_bench.erase(first_bench.begin());
      se.erase({d, x, y});
    }
  }
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