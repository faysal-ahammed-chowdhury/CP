#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, mod = 1e9 + 7;
int a[N], val[35], need[35];

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

int calc(int n) {
  int ans = 1;
  int tot = power(2, n - 1, mod);
  int tmp = power(2, mod - 2, mod);
  for (int i = 1; ; i++) {
    if (tot == 1) break;
    int half = 1ll * tot * tmp % mod;
    ans = 1ll * ans * power(i, half, mod) % mod;
    tot -= half;
    if (tot < 0) tot += mod;
  }
  ans = 1ll * ans * n % mod;
  return ans;
}

void prec() {
  for (int i = 1; i <= 33; i++) {
    val[i] = calc(i);
    need[i] = (1ll << (i - 1));
  }
}

int f(int x, int baki) {
  if (baki == 0) return 1;
  int ans = x;
  baki--;
  for (int i = 1; i < min(33ll, x); i++) {
    if (need[i] <= baki) {
      baki -= need[i];
      ans = 1ll * ans * val[i] % mod;
    }
    else {
      ans = 1ll * ans * f(i, baki) % mod;
      return ans;
    }
  }
  return ans;
}

void solve() {
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  int ans = 1;
  for (int i = 1; i <= min(n, 33ll); i++) {
    if (a[i] <= 30 and need[a[i]] <= k) {
      k -= need[a[i]];
      ans = 1ll * ans * val[a[i]] % mod;
    }
    else {
      ans = 1ll * ans * f(a[i], k) % mod;
      break;
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}