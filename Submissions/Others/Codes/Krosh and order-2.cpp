#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int zero = 0, one = 0, two = 0, three = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    zero += x == 0;
    one += x == 1;
    two += x == 2;
    three += x == 3;
  }

  if (m == 2) {
    int ans = one;
    cout << ans << '\n';
  }
  else if (m == 3) {
    int ans = one;
    int possilbe = (n + 1) / 2;
    ans += min(possilbe, two) * 2;
    two -= min(possilbe, two);
    ans += two;
    cout << ans << '\n';
  }
  else {
    int ans = one;
    int possilbe = (n + 1) / 2;
    if (three < possilbe and two) ans += 2;
    ans += min(possilbe, three) * 3;
    three -= min(possilbe, three);
    ans += three;
    cout << ans << '\n';
  }

  return 0;
}