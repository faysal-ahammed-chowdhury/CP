#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int d, n; cin >> d >> n;
    ll a[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
      a[i] += a[i - 1];
    }
    map<int, int> mp;
    ll cnt = 0;
    for(int i = 1; i <= n; i++) {
      cnt += mp[a[i] % d];
      if(a[i] % d == 0) cnt++;
      mp[a[i] % d]++;
    }
    cout << cnt << '\n';
  }

  return 0;
}