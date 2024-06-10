#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n];
    long long sum = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    double avg = (double) sum / n;
    map<int, int> mp;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      double x = avg * 2;
      if((long long) x == x) {
        int need = x - a[i];
        ans += mp[need];
      }
      mp[a[i]]++;
    }
    cout << ans << '\n';
  }

  return 0;
}