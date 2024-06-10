#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 9;
int spf[N], phi[N];

void sieve_phi() {
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

  for (int i = 2; i < N; i++) {
    int x = i, res = 1;
    while (x > 1) {
      int p = spf[x], pw = 1;
      while (x % p == 0) {
        pw *= p;
        x /= spf[x];
      }
      res *= pw - (pw / p); // (p^e) - (p^(e-1))
    }
    phi[i] = res;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve_phi();

  return 0;
}