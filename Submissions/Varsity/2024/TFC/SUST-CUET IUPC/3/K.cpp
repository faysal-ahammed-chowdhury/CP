#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

void solve() {
  int n, k; cin >> n >> k;
  if (n % 2 == 0) {
    if ((n / 2) >= k) {
      cout << "YES\n";
      return;
    }
    else {
      cout << "NO\n";
      return;
    }
  }
  else {
    for (auto x : primes) {
      long long y = 1ll * x * (k - 1);
      long long rem = n - y;
      if (rem > 0 and rem % x == 0) {
        cout << "YES\n";
        return;
      }
    }
  }

  cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();
  for (int i = 2; i < N; i++) {
    if (is_prime[i]) primes.push_back(i);
  }

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}