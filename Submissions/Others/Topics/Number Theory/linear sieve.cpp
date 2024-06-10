#include <bits/stdc++.h>
using namespace std;

const int N = 10000000;
vector<int> spf(N + 1); // memory takes 32 times more than classic sieve
vector<int> primes;

void linear_sieve() { // O(n)
  for (int i = 2; i <= N; ++i) {
    if (spf[i] == 0) {
      spf[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; i * primes[j] <= N; ++j) {
      spf[i * primes[j]] = primes[j];
      if (primes[j] == spf[i]) {
        break;
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}