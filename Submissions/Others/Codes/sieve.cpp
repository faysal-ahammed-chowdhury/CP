#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;
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

  for (int i = 1; i <= 100; i++) {
    cout << i << ": ";
    if (is_prime[i]) {
      cout << "PRIME\n";
    }
    else {
      cout << "NOT PRIME\n";
    }
  }

  return 0;
}