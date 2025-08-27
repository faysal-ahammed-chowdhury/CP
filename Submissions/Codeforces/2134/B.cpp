#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 100 + 9;
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
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << a[1] + k << '\n';
    return;
  }

  if (k % 2 == 1) {
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 == 1) cout << a[i] + k << ' ';
      else cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }


  int val = -1;
  for (auto p : primes) {
    if (k % p) {
      val = p;
      break;
    }
  }
  assert(val != -1);


  map<int, int> mp;
  mp[k % val] = 1;
  int cur = ((k % val) + (k % val)) % val;
  for (int i = 2; ; i++) {
    if (cur == (k % val)) break;
    mp[cur] = i;
    cur += k;
    cur %= val;
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] % val == 0) {
      cout << a[i] << ' ';
      continue;
    }
    int need = val - (a[i] % val);
    int x = mp[need];
    a[i] += x * k;
    cout << a[i] << ' ';
  }
  cout << '\n';

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  for (int i = 1; i <= 100; i++) {
    if (is_prime[i]) primes.push_back(i);
  }

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}