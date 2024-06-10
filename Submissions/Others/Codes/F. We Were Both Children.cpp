#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
ll n, cnt[N], divisors[N];

void sieve() {
  for(int i = 2; i <= n; i++) {
    for(int j = i; j <= n; j += i) {
      divisors[j] += cnt[i];
    }
  }
}

void solve() {
  cin >> n;

  for(int i = 0; i <= n; i++) {
    cnt[i] = 0;
    divisors[i] = 0;
  }

  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    if(x > n) continue;
    cnt[x]++;
  }

  sieve();

  ll mx = 0;
  for(int i = 2; i <= n; i++) {
    mx = max(mx, divisors[i]);
  }

  cout << mx + cnt[1] << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}