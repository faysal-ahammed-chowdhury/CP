#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int spf[N];

void spf_sieve() {
  for(int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    if(spf[i] == i) {
      for(int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

int nod(map<int, int> mp) {
  int ans = 1;
  for(auto [p, pw]: mp) {
    ans *= (pw + 1);
  }
  return ans;
}

int power(int b, int p, int m) {
  if(p == 0) return 1 % m;
  if(p & 1) {
    int val = power(b, p / 2, m);
    return ((1LL * val * val) % m) * b % m;
  }
  else {
    int val = power(b, p / 2, m);
    return (1LL * val * val) % m;
  }
}

bool ok(map<int, int> &mp, int divisor) {
  if(mp.size() == 0) return true;
  long long ans = 1;
  for(auto [p, pw]: mp) {
    ans *= power(p, pw, divisor);
    ans %= divisor;
  }
  return ans == 0;
}

void solve() {
  int n, q; cin >> n >> q;
  map<int, int> init;
  int x = n;
  while(x > 1) {
    init[spf[x]]++;
    x /= spf[x];
  }
  map<int, int> mp = init;

  while(q--) {
    int k; cin >> k;
    if(k == 1) {
      int x; cin >> x;
      while(x > 1) {
        mp[spf[x]]++;
        x /= spf[x];
      }

      int divisor = nod(mp);
      if(ok(mp, divisor)) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
    else {
      mp.clear();
      mp = init;
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}