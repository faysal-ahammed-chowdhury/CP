#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, inf = 2e9;
pair<int, int> a[N];
int n;

int f(int x1, int y1, int x2, int y2) {
  int d1 = max(abs(x1 - x2), abs(y1 - y2));
  return (d1 + 1) / 2;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1);

  auto [x1, y1] = a[1];
  auto [x2, y2] = a[n];

  for (int i = 1; i <= n; i++) {
    swap(a[i].first, a[i].second);
  }
  sort(a + 1, a + n + 1);

  auto [y3, x3] = a[1];
  auto [y4, x4] = a[n];

  if (n == 1) {
    cout << 0 << '\n';
    return 0;
  }
  if (n == 2) {
    int ans = f(a[1].first, a[1].second, a[2].first, a[2].second);
    cout << ans << '\n';
    return 0;
  }
  if (n == 3) {
    int ans = f(a[1].first, a[1].second, a[2].first, a[2].second);
    ans = max(ans, f(a[1].first, a[1].second, a[3].first, a[3].second));
    ans = max(ans, f(a[2].first, a[2].second, a[3].first, a[3].second));
    cout << ans << '\n';
    return 0;
  }

  int ans = f(x1, y1, x2, y2);
  ans = max(ans, f(x1, y1, x3, y3));
  ans = max(ans, f(x1, y1, x4, y4));
  ans = max(ans, f(x2, y2, x3, y3));
  ans = max(ans, f(x2, y2, x4, y4));
  ans = max(ans, f(x3, y3, x4, y4));
  cout << ans << '\n';

  return 0;
}