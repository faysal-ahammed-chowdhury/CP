#include <bits/stdc++.h>
using namespace std;

const int N = 505, P = 4000, mod = 1e9 + 7;
vector<bool> is_prime(P, true);
vector<int> primes;
int pref[N], dp[N][N];

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(P + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < P; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

void prec() {
  for (int i = 1; i < P; i++) {
    if (is_prime[i]) primes.push_back(i);
  }
  pref[0] = 1;
  for (int i = 0; i <= 500; i++) {
    pref[i + 1] = 1ll * pref[i] * (primes[i] - 1) % mod;
  }
}

int f(int i, int last_pos) {
  if (last_pos < 0) return i == 0;
  if (i == 0) return 1;
  int &ans = dp[i][last_pos];
  if (ans != -1) return ans;
  ans = f(i, last_pos - 1);
  ans += 1ll * f(i - 1, last_pos) * primes[last_pos] % mod;
  ans %= mod;
  return ans;
}

int cs;
void solve() {
  int n, k; cin >> n >> k;
  int ans = pref[k];
  ans = 1ll * ans * f(n - k, k - 1) % mod;
  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  prec();

  memset(dp, -1, sizeof dp);
  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}