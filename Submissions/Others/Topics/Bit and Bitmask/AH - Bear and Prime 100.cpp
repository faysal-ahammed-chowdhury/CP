#include <bits/stdc++.h>
using namespace std;

const int N = 51;
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

bool query(int x) {
  cout << x << endl;
  string s; cin >> s;
  return s == "yes";
}

int32_t main() {
  sieve();
  for (int i = 2; i <= 50; i++) {
    if (is_prime[i]) primes.push_back(i);
  }

  if (query(2 * 2) or query(3 * 3) or query(5 * 5) or query(7 * 7)) {
    cout << "composite" << endl;
  }

  int cnt = 0;
  for (auto p : primes) {
    if (query(p)) cnt++;
  }
  if (cnt <= 1) {
    cout << "prime" << endl;
  }
  else {
    cout << "composite" << endl;
  }

  return 0;
}