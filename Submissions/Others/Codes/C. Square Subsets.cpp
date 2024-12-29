#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 1e5 + 9, MAXV = 75, mod = 1e9 + 7;
int spf[N], dp[MAXV][(1 << 19) + 5];
vector<int> primes;
int n, sz, freq[MAXV], maskof[MAXV];

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

void spf_sieve() {
  for (int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

int indexof(int p) {
  for (int i = 0; i < sz; i++) {
    if (primes[i] == p) return i;
  }
  return -1;
}

void prec() {
  for (int i = 2; i <= 70; i++) {
    if (spf[i] == i) primes.push_back(i);
  }
  sz = primes.size();

  for (int i = 2; i < MAXV; i++) {
    int x = i;
    while (x > 1) {
      int p = spf[x], ex = 0;
      while (x % p == 0) {
        ex++;
        x /= p;
      }
      if (ex & 1) SET(maskof[i], indexof(p));
    }
  }
}

int f(int value, int mask) {
  if (value > 70) return mask == 0;
  int &ans = dp[value][mask];
  if (ans != -1) return ans;
  if (freq[value] == 0) ans = f(value + 1, mask);
  else {
    ans = 1ll * f(value + 1, maskof[value] ^ mask) * power(2, freq[value] - 1, mod) % mod;
    ans += 1ll * f(value + 1, mask) * power(2, freq[value] - 1, mod) % mod;
    ans %= mod;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();
  prec();

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    freq[x]++;
  }

  memset(dp, -1, sizeof dp);
  int ans = f(1, 0) - 1;
  if (ans < 0) ans += mod;
  cout << ans << '\n';

  return 0;
}