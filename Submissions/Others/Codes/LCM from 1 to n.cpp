#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
const int N = 1e8 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;
vector<uint> pref;

void sieve() {
  is_prime[1] = false;
  for (int i = 2; i * i < N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

void prec() {
  sieve();
  primes.push_back(1);
  for (int i = 2; i < N; i++) {
    if(is_prime[i]) {
      primes.push_back(i);
    }
  }

  int sz = primes.size();
  pref.resize(sz);
  pref[0] = 1;
  for (int i = 1; i < sz; i++) {
    pref[i] = pref[i - 1] * primes[i];
  }
}

int get(int n, int p) {
  int ans = p;
  while (1ll * ans * p <= n) {
    ans *= p;
  }
  return ans;
}

int cs;
void solve() {
  int n; cin >> n;
  uint ans = 1;
  for (auto p : primes) {
    if (p == 1) continue;
    if (p * p > n) break;
    ans *= get(n, p) / p;
  }
  int idx = upper_bound(primes.begin(), primes.end(), n) - primes.begin() - 1;
  ans *= pref[idx];
  cout << "Case " << ++cs << ": " << ans << '\n';
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