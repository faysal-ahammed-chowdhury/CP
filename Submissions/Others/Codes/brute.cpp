#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 100 + 9, mod = 1e9 + 7;
const ll inf = 1e9;
int n, a[N];

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }


  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int idx, k; cin >> idx >> k;
      int cur = a[1], cnt = 0;
      bool ok = true;
      for (int i = 2; i < idx; i++) {
        cnt++;
        if (a[i] > cur) {
          cur = a[i];
          cnt = 0;
          continue;
        }

        if (cnt >= k) {
          ok = false;
          cout << 0 << '\n';
          break;
        }
      }

      if (ok) {
        int cnt = 0, pos = 0, mx = 0;
        int first;
        for (int i = 1; i <= idx; i++) {
          if (a[i] == a[idx]) {
            first = i;
            break;
          }
        }
        for (int i = 1; i <= min(n, first + k); i++) {
          mx = max(mx, a[i]);
          if (a[i] == a[idx]) cnt++;
          if (a[i] == a[idx] and i <= idx) pos++;
        }

        if (mx > a[idx]) {
          cout << 0 << '\n';
        }
        else {
          int upore = (pos == 1) ? 1 : power(2, pos - 2, mod);
          int niche = power(2, cnt - 1, mod);
          int ans = 1ll * upore * power(niche, mod - 2, mod) % mod;
          cout << ans << '\n';
        }
      }
    }
    else {
      int idx; cin >> idx;

      int k = 1;
      for (int i = 1; i <= idx; i++) {
        if (a[i] == a[idx]) {
          k = max(k, idx - i);
        }
        else {
          for (int j = i + 1; j <= idx; j++) {
            if (a[j] > a[i]) {
              k = max(k, j - i);
              break;
            }
          }
        }
      }

      int cur = a[1], cnt = 0;
      bool ok = true;
      for (int i = 2; i < idx; i++) {
        cnt++;
        if (a[i] > cur) {
          cur = a[i];
          cnt = 0;
          continue;
        }

        if (cnt >= k) {
          ok = false;
          cout << 0 << '\n';
          break;
        }
      }

      if (ok) {
        int cnt = 0, pos = 0, mx = 0;
        int first;
        for (int i = 1; i <= idx; i++) {
          if (a[i] == a[idx]) {
            first = i;
            break;
          }
        }
        for (int i = 1; i <= min(n, first + k); i++) {
          mx = max(mx, a[i]);
          if (a[i] == a[idx]) cnt++;
          if (a[i] == a[idx] and i <= idx) pos++;
        }

        if (mx > a[idx]) {
          cout << 0 << '\n';
        }
        else {
          int upore = (pos == 1) ? 1 : power(2, pos - 2, mod);
          int niche = power(2, cnt - 1, mod);
          int ans = 1ll * upore * power(niche, mod - 2, mod) % mod;
          cout << ans << '\n';
        }
      }
    }
  }

  return 0;
}