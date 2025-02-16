#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], dp[N];
vector<int> divs[N];

void sieve() {
  for (int i = 1; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
}

int f(int x) {
  if (x == 1) return 0;
  int &ans = dp[x];
  if (ans != -1) return ans;
  set<int> mex;
  for (auto y : divs[x]) {
    mex.insert(f(y));
  }
  ans = 0;
  while (true) {
    if (mex.find(ans) != mex.end()) ans++;
    else break;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  memset(dp, -1, sizeof dp);
  int n; cin >> n;
  int xr = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    xr ^= f(x);
  }

  if (xr) cout << "Anna\n";
  else cout << "Bruno\n";

  return 0;
}