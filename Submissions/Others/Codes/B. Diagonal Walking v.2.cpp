#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int dx[] = {0, +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {0, -1, +1, +0, +0, +1, +1, -1, -1};

void solve() {
  int n, m, k; cin >> n >> m >> k;

  int ans = -1;
  for (int j = 0; j <= 8; j++) {
    int x = dx[j], y = dy[j];
    int need = abs(dx[j]) + abs(dy[j]) + abs(n - x);
    int tmp = abs(n - x);
    x += tmp;
    assert(x == n);
    y += tmp;
    int tmp2 = abs(m - y);
    need += abs(y - m);
    y += (m - y);
    assert(y == m);
    int here = tmp + ((tmp2 % 2) ? tmp2 - 1 : tmp2);
    if (need <= k and (k - need) % 2 == 0) {
      here += (k - need);
      ans = max(ans, here);
    }

    if (tmp2 % 2) {
      need++;
      here = tmp + tmp2;
      if (need <= k and (k - need) % 2 == 0) {
        here += (k - need);
        ans = max(ans, here);
      }
    }
  }

  for (int j = 0; j <= 8; j++) {
    int x = dx[j], y = dy[j];
    int need = abs(dx[j]) + abs(dy[j]) + abs(m - y);
    int tmp = abs(m - y);
    x += tmp;
    y += tmp;
    int tmp2 = abs(n - x);
    assert(y == m);
    need += abs(x - n);
    x += (n - x);
    assert(x == n);
    int here = tmp + ((tmp2 % 2) ? tmp2 - 1 : tmp2);
    if (need <= k and (k - need) % 2 == 0) {
      here += (k - need);
      ans = max(ans, here);
    }

    if (tmp2 % 2) {
      need++;
      here = tmp + tmp2;
      if (need <= k and (k - need) % 2 == 0) {
        here += (k - need);
        ans = max(ans, here);
      }
    }
  }

  for (int j = 5; j <= 8; j++) {
    int x = dx[j], y = dy[j];
    int need = 1 + abs(n - x);
    int tmp = abs(n - x);
    x += tmp;
    assert(x == n);
    y += tmp;
    int tmp2 = abs(m - y);
    need += abs(y - m);
    y += (m - y);
    assert(y == m);
    int here = tmp + ((tmp2 % 2) ? tmp2 - 1 : tmp2);
    if (need <= k and (k - need) % 2 == 0) {
      here += (k - need);
      ans = max(ans, here);
    }

    if (tmp2 % 2) {
      need++;
      here = tmp + tmp2;
      if (need <= k and (k - need) % 2 == 0) {
        here += (k - need);
        ans = max(ans, here);
      }
    }
  }

  for (int j = 5; j <= 8; j++) {
    int x = dx[j], y = dy[j];
    int need = 1 + abs(m - y);
    int tmp = abs(m - y);
    x += tmp;
    y += tmp;
    int tmp2 = abs(n - x);
    assert(y == m);
    need += abs(x - n);
    x += (n - x);
    assert(x == n);
    int here = tmp + ((tmp2 % 2) ? tmp2 - 1 : tmp2);
    // cout << here << '\n';
    if (need <= k and (k - need) % 2 == 0) {
      here += (k - need);
      ans = max(ans, here);
    }

    if (tmp2 % 2) {
      need++;
      here = tmp + tmp2;
      if (need <= k and (k - need) % 2 == 0) {
        here += (k - need);
        ans = max(ans, here);
      }
    }
  }

  cout << ans << '\n';
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