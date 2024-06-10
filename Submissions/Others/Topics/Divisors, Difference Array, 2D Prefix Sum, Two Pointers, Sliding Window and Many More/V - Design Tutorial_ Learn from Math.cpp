#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
vector<bool> is_prime(N, true);

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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();
  int n; cin >> n;
  for (int i = 2; i <= n; i++) {
    int need = n - i;
    if (is_prime[i] == false and is_prime[need] == false) {
      cout << i << ' ' << need << '\n';
      return 0;
    }
  }

  return 0;
}