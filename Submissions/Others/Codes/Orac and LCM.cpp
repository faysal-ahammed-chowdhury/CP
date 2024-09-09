#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int spf[N];

void spf_sieve() {
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
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int n; cin >> n;
  int gc = 0;
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    gc = __gcd(gc, x);
    while (x > 1) {
      int p = spf[x], ex = 0;
      while (x % p == 0) {
        ex++;
        x /= p;
      }
      mp[p].push_back(ex);
    }
  }
  long long ans = 1;
  for (auto &[p, v] : mp) {
    if (v.size() >= n - 1) {
      sort(v.begin(), v.end());
      ans *= powl(p, (v.size() == n ? v[1] : v[0]));
      // cout << p << ": ";
      // for (auto ex : v) {
      //   cout << ex << ' ';
      // }
      // cout << '\n';
    }
  }
  cout << ans << '\n';

  return 0;
}