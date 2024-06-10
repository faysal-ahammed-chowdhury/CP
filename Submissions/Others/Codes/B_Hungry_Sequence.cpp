#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;
vector<bool> is_prime(N, true);
vector<int> a;

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
      a.push_back(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}