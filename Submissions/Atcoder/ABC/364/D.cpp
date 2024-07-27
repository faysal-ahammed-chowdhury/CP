#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 9;
int n, q;
int a[N];

bool ok(int x, int b, int k) {
  int l = b - x, r = b + x;
  int len1 = upper_bound(a + 1, a + n + 1, r) - lower_bound(a + 1, a + n + 1, l);
  return len1 >= k;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  while (q--) {
    int b, k; cin >> b >> k;
    int l = 0, r = 1e10, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(mid, b, k)) {
        ans = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}