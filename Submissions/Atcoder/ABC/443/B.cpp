#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int n, k;

bool ok(int y) {
  int r = (y * (y + 1)) / 2;
  int l = (n * (n - 1)) / 2;
  return (r - l) >= k;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  int l = n, r = 1e8, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  cout << ans - n << '\n';

  return 0;
}