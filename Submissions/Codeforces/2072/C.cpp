#include <bits/stdc++.h>
using namespace std;
#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

void solve() {
  int n, k; cin >> n >> k;

  if (n == 1) {
    cout << k << '\n';
    return;
  }

  int a[n + 1];
  memset(a, -1, sizeof a);
  a[1] = 0;
  int val = 0;
  for (int i = 2; i <= n; i++) {
    int here = i - 1;
    bool ok = true;
    for (int b = 0; b < 30; b++) {
      if (CHECK(here, b)) ok &= (CHECK(k, b) == CHECK(here, b));
    }
    if (ok) a[i] = here;
    else break;

    val |= a[i];
  }

  if (val != k) a[n] = k;

  val = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) a[i] = k;
    cout << a[i] << ' ';
    val |= a[i];
  }
  cout << '\n';

  assert(val == k);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}