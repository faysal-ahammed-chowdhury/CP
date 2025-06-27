#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5005, inf = 2e9;
int n, a[N];

int f(int i, int x) {
  int l = i, r = n, idx = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (a[mid] >= x) {
      idx = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  if (idx == -1) return 0;
  return n - idx + 1;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int sum = a[i] + a[j];
      int x = f(j + 1, sum);
      int y = f(j + 1, (a[n] - sum) + 1);
      ans += max(0, y - x);
      // cout << i << ' ' << j << ' ' << f(j + 1, sum) << '\n';
    }
  }
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