#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 9;
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

void solve() {
  int n; cin >> n;
  int a = 0, b = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a = __gcd(a, x);
  }
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    b = __gcd(b, x);
  }

  if (a == b) {
    cout << 0 << '\n';
    return;
  }

  map<int, int> mp1, mp2;
  
  while (a > 1) {
    mp1[spf[a]]++;
    a /= spf[a];
  }

  while (b > 1) {
    mp2[spf[b]]++;
    b /= spf[b];
  }

  bool ans1 = 0, ans2 = 0;
  for (auto [x, y] : mp1) {
    if (mp2.find(x) == mp2.end()) {
      ans1 = true;
    }
    else if (mp2[x] < y) {
      ans1 = true;
    }
  }

  for (auto [x, y] : mp2) {
    if (mp1.find(x) == mp1.end()) {
      ans2 = true;
    }
    else if (mp1[x] < y) {
      ans2 = true;
    }
  }

  int ans = ans1 + ans2;

  cout << ans << '\n';
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