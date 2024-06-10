#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;

bool is_n_prime(int n) {
  if(n == 1) return false;
  int lim = sqrt(n + 1);
  for(int i = 2; i <= lim; i++) {
    if(n % i == 0) return false;
  }
  return true;
}

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

  for(int i = 2; i < N; i++) {
    if(is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();
  int n; cin >> n;

  if(is_n_prime(n)) {
    cout << 1 << '\n';
    cout << n << '\n';
    return 0;
  }

  if(is_n_prime(n - 2)) {
    cout << 2 << '\n';
    cout << 2 << ' ' << n - 2 << '\n';
    return 0;
  }

  cout << 3 << '\n';
  cout << 3 << ' ';
  n -= 3;

  for(auto p: primes) {
    int need = n - p;
    if(is_n_prime(need)) {
      cout << p << ' ' << need << '\n';
      break;
    }
  }

  return 0;
}