#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 100 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;

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

int legendre(int n, int p) {
  int ex = 0;
  while(n) {
    ex += (n / p);
    n /= p;
  }
  return ex;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  for(int i = 2; i < N; i++) {
    if(is_prime[i]) primes.push_back(i);
  }

  while(true) {
    int n; int d; cin >> n >> d;
    if(n == 0 && d == 0) {
      break;
    }
    map<int, int> mp1, mp2;
    for(auto p: primes) {
      int pw = legendre(n, p);
      if(pw != 0) mp1[p] = pw;
    }

    int lim = sqrt(d + 1);
    for(int i = 2; i <= lim; i++) {
      while(d % i == 0) {
        mp2[i]++;
        d /= i;
      }
    }
    if(d > 1) mp2[d]++;

    bool possible = true;
    for(auto i: mp2) {
      if(mp1[i.first] < i.second) {
        cout << 0 << '\n';
        possible = false;
        break;
      }
    }

    if(possible) {
      long long ans = 1;
      for(auto i: mp1) {
        if(mp2.find(i.first) != mp2.end()) {
          ans *= (i.second + 1) - mp2[i.first];
        }
        else {
          ans *= (i.second + 1);
        }
      }
      cout << ans << '\n';
    }
  }

  return 0;
}