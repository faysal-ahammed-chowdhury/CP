#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double p(int x, int n, int m) {
  return pow((x / (double)m), n) - pow(((x - 1) / (double)m), n);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, n; cin >> m >> n;
  double ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += p(i, n, m) * i;
  }
  cout << fixed << setprecision(10);
  cout << ans << '\n';

  return 0;
}