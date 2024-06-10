#include <bits/stdc++.h>
using namespace std;

const int N = 1150, K = 15;
int n, k, prime_length;
int dp[2][N][K];
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();
  primes.push_back(0);
  for (int i = 2; i < N; i++) {
    if (is_prime[i]) primes.push_back(i);
  }
  prime_length = primes.size();

  while (cin >> n >> k and n && k) {
    for (int i = 0; i < prime_length; i++) {
      for (int number = 0; number <= n; number++) {
        for (int lenght = 0; lenght <= k; lenght++) {
          if (i == 0) {
            if (number == 0 && lenght == 0) {
              dp[1][number][lenght] = 1;
            }
            else {
              dp[1][number][lenght] = 0;
            }
          }
          else {
            int &ans = dp[1][number][lenght];
            ans = 0;
            if (number >= primes[i] && lenght > 0) {
              ans += dp[0][number - primes[i]][lenght - 1];
            }
            ans += dp[0][number][lenght];
          }
        }
      }
      for (int number = 0; number <= n; number++) {
        for (int lenght = 0; lenght <= k; lenght++) {
          dp[0][number][lenght] = dp[1][number][lenght];
        }
      }
    }
    cout << dp[1][n][k] << '\n';
  }
}