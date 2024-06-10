#include <bits/stdc++.h>
using namespace std;

const int N = 20000009;
vector<bool> is_prime(N, true);

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for(int i = 2; i <= lim; i++) {
    if(is_prime[i]) {
      for(int j = i + i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();
  vector<pair<int, int>> twin_primes;
  for(int i = 2; i < N; i++) {
    if(is_prime[i] && is_prime[i + 2]) {
      twin_primes.push_back({i, i + 2});
    }
  }

  int n;
  while(cin >> n) {
    cout << "(" << twin_primes[n - 1].first << ", " << twin_primes[n - 1].second << ")\n";
  }

        
  return 0;
}