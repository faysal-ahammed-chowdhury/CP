#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// almost correct solution - precision error
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int tot = 0, inv = 0;
      for (int val1 = 1; val1 <= a[i]; val1++) {
        for (int val2 = 1; val2 <= a[j]; val2++) {
          if (val1 > val2) inv++;
          tot++;
        }
      }
      ans += double(inv) / tot;
    }
  }

  cout << fixed << setprecision(6);
  cout << ans << '\n';

  return 0;
}