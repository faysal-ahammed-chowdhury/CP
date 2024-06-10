#include <bits/stdc++.h>
using namespace std;

double get_distance(double x1, double y1, double x2, double y2) {
  return sqrt((abs(x1 - x2) * abs(x1 - x2)) + (abs(y1 - y2) * abs(y1 - y2)));
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1);

  double tot = 0;
  int cnt = 0;
  do {
    cnt++;
    double len = 0;
    for (int i = 1; i < n; i++) {
      len += get_distance(a[i].first, a[i].second, a[i + 1].first, a[i + 1].second);
    }
    tot += len;
  } while (next_permutation(a + 1, a + n + 1));

  double ans = tot / cnt;
  cout << fixed << setprecision(10) << ans << '\n';

  return 0;
}