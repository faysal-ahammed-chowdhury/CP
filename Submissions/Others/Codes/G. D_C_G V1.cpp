#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 9;
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

int power(int a, int b) {
  int ans = 1;
  for (int i = 1; i <= b; i++) {
    ans *= a;
  }
  return ans;
}

int build(int a, int g) {
  int c = 1;
  map<int, int> mp_a, mp_g;
  int tmp_a = a, tmp_g = g;
  while (tmp_a > 1) {
    mp_a[spf[tmp_a]]++;
    tmp_a /= spf[tmp_a];
  }
  while (tmp_g > 1) {
    mp_g[spf[tmp_g]]++;
    tmp_g /= spf[tmp_g];
  }

  for (auto [p, pw] : mp_g) {
    if (mp_a[p] < pw) {
      c *= power(p, pw - mp_a[p]);
    }
  }
  return c;
}

void solve() {
  int a, b, g; cin >> a >> b >> g;
  int c = build(a, g);
  int d = build(b, g);
  int gg = __gcd((a * c), (b * d));
  if (g != gg) {
    cout << -1 << '\n';
    return;
  }
  cout << c << ' ' << d << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}