#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, k, a[N];

bool ok(int d) {
  int sum = 0, need = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] > d) return false;
    if (sum + a[i] <= d) sum += a[i];
    else {
      need++;
      sum = a[i];
    }
  }
  return need <= k;
}

int cs;
void solve() {
  cin >> n >> k;
  n++, k++;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = 1, r = 10000000, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << "Case " << ++cs << ": " << ans << '\n';

  int done = 1, sum = a[1], cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (sum + a[i] <= ans and (n - i) >= (k - done)) {
      sum += a[i];
    }
    else {
      cout << sum << '\n';
      cnt++;
      sum = a[i];
      done++;
    }
  }
  cout << sum << '\n';
  assert(cnt + 1 == k);
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