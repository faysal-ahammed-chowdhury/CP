#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N = 1e6 + 9, mod = 1000000007; 
int fact[N], ifact[N];  

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

int inverse(int x) {
  return power(x, mod - 2, mod);
}

void prec() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  ifact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
  }
}

int nCr(int n, int r) {
  if (r > n) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int nPr(int n, int r) {
  if (r < 0) return 0;
  if (n < 0) return 0;
  if (r > n) return 0;
  return 1ll * fact[n] * ifact[n - r] % mod;
}

void solve() {
  int n, k; cin >> n >> k;
  if (k % 2 == 1) {
    cout << 0 << '\n';
    return;
  }
  int half = k / 2;
  int d = n / k;
  int rem = n % k;
  ll x = 1ll * d * half;
  int ans = 0;
  for (int i = 0; i <= min(rem, half); i++) {
    int a = 1ll * nCr(rem, i) * nCr(k - rem, half - i) % mod;
    int b = power(2, (x + i), mod);
    ans += 1ll * a * b % mod;
    ans %= mod;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec(); // must include

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}