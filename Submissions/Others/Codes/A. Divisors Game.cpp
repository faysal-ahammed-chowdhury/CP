#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, MX = 1e6 + 9;
vector<int> divs[MX];
int dp[MX];
int a[N], pref[N][32];

void sieve() {
  for (int i = 2; i < MX; i++) {
    for (int j = i; j < MX; j += i) {
      divs[j].push_back(i);
    }
  }
}

int f(int x) {
  if (dp[x] != -1) return dp[x];
  set<int> se;
  for (auto d : divs[x]) {
    se.insert(f(x / d));
  }
  int mex = 0;
  while (se.find(mex) != se.end()) {
    mex++;
  }
  return dp[x] = mex;
}

void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = f(a[i]);
    a[i] = a[i - 1] ^ a[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < 32; k++) {
      pref[i][k] = pref[i - 1][k];
    }
    pref[i][a[i]]++;
    // cout << pref[i][3] << '\n';
  }

  while (q--) {
    int l, r; cin >> l >> r;

    ll bob = 0;
    for (int k = 0; k < 32; k++) {
      int x = pref[r][k] - (l - 2 >= 0 ? pref[l - 2][k] : 0);
      // cout << k << ' ' << x << '\n';
      if (l == 1 and k == 0) x++;
      // cout << k << ' ' << x << '\n';
      bob += (1ll * x * (x - 1)) / 2;
    }

    int len = (r - l + 1);
    ll tot = (1ll * len * (len + 1)) / 2;
    ll alice = tot - bob;

    // cout << bob << '\n';

    if (alice == bob) {
      cout << "Draw\n";
    }
    else if (alice > bob) {
      cout << "First\n";
    }
    else {
      cout << "Second\n";
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  memset(dp, -1, sizeof dp);

  // for (int i = 1; i <= 100000; i++) {
  //   cout << i << ' ' << f(i) << '\n';
  // } 

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}