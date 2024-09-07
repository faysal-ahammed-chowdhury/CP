#include <bits/stdc++.h>
using namespace std;

const int N = 100000000;
vector<bool> is_prime(N, true);

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  vector<int> primes;
  for (int i = 1; i < N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  int last = 0;
  int mx = 0;
  for (auto p : primes) {
    mx = max(mx, p - last);
    last = p;
  }
  cout << mx << '\n';

  return 0;
}