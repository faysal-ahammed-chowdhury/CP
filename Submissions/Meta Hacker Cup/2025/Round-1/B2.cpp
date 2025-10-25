#include <bits/stdc++.h>
using namespace std;
#include <sys/resource.h>
#define int long long

const int mod = 1e9 + 7;
vector<int> divs, primes;

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

int nCr(int n, int r) {
  int sum = 1;
  for (int i = 1; i <= r; i++) {
    int a = n - r + i;
    a %= mod;
    if (a < 0) a += mod;
    sum = sum * (a) % mod;
    sum = sum * power(i, mod - 2, mod) % mod;
  }
  return (int)sum;
}


int f(int x, int n) {
  int ans = 1;
  for (auto p : primes) {
    int ex = 0;
    while (x % p == 0) {
      x /= p;
      ex++;
    }
    if (ex > 0) {
      ans *= nCr(ex + n - 1, ex);
      ans %= mod;
    }
  }
  return ans;
}

int cs;
void solve() {
  divs.clear();
  primes.clear();
  int n, a, b; cin >> n >> a >> b;

  int tmp = b;
  for (int i = 1; i * i <= b; i++) {
    if (b % i == 0) {
      divs.push_back(i);
      if (i != (b / i)) divs.push_back(b / i);
    }
    bool yes = false;
    while (i > 1 and tmp % i == 0) {
      yes = true;
      tmp /= i;
    }
    if (yes) primes.push_back(i);
  }
  if (tmp > 1) primes.push_back(tmp);

  int ans = 0;
  for (auto x : divs) {
    int here = 0;
    if (x <= a) {
      int y = b / x;
      here = f(x, n) * f(y, n) % mod;
    }
    ans += here;
    ans %= mod;
  }

  cout << "Case #" << ++cs << ": " << ans << '\n';
}

int32_t main() {
  rlimit rlim;
  if (getrlimit(RLIMIT_STACK, &rlim)) return 1;
  rlim.rlim_cur = rlim.rlim_max;
  // You can set the fixed value instead of max value, e.g. rlim.rlim_cur = 1024 * 1024 * 1024
  // will set your stack size to 1 GiB
  if (setrlimit(RLIMIT_STACK, &rlim)) return 2;
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}