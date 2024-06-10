#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;
int cnt[N], multiples[N];

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

  for (int i = 2; i < N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
    for (int j = i; j < N; j += i) {
      multiples[i] += cnt[j];
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    cnt[x]++;
  }

  sieve();

  return 0;
}