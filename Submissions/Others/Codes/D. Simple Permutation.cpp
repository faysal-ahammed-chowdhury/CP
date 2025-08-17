#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;

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

void solve() {
  int n; cin >> n;
  int nby3 = n / 3;
  int p = *lower_bound(primes.begin(), primes.end(), nby3 + 1);
  set<int> se;
  for (int i = 1; i <= n; i++) {
    se.insert(i);
  }

  cout << p << ' ';
  se.erase(p);
  int x = p - 1, y = p + 1;
  while (true) {
    if (x >= 1 and y <= n) {
      cout << x << ' ' << y << ' ';
      se.erase(x);
      se.erase(y);
      --x, ++y;
    }
    else break;
  }

  while (!se.empty()) {
    cout << *se.begin() << ' ';
    se.erase(se.begin());
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  for (int i = 1; i < N; i++) {
    if (is_prime[i]) primes.push_back(i);
  }

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}