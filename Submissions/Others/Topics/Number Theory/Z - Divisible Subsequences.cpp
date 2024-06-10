#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int d, n; cin >> d >> n;
    ll a[n + 1]; a[0] = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
      a[i] += a[i - 1];
    }
    map<int, int> mp;
    long long cnt = 0;
    for(int i = 1; i <= n; i++) {
      if(a[i] % d == 0) cnt++;
      cnt += mp[a[i] % d];
      mp[a[i] % d]++;
    }
    cout << cnt << '\n';
  }

  return 0;
}