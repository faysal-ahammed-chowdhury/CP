#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int n, a[N];
ll m;

bool ok(int x) {
  ll tmp = m;
  for (int i = x; i >= 1; i--) {
    if (a[i] * 10 <= tmp) tmp -= a[i];
    else return false;
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  cout << ans << '\n';

  return 0;
}