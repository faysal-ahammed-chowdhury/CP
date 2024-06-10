#include "bits/stdc++.h"
// code from Bruteforcer for learning purpose
using namespace std;

int lcm(int i, int j) {
  return (i / __gcd(i, j)) * j;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector <int> a (n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int N = -1;
    for(int i = 0; i < n; i++) {
      int cnt = 0;
      for(int j = 0; j < n; j++) {
        cnt += (a[i] % a[j] == 0);
      }
      if(cnt == n) {
        N = a[i];
        break;
      }
    }
    if(N == -1) {
      cout << n << endl;
      continue;
    }
    vector <int> divs;
    for(int i = 1; 1LL * i * i <= N; i++) {
      if(N % i == 0) {
        divs.push_back(i);
        if(i * i != N) {
          divs.push_back(N / i);
        }
      }
    }
    set <int> cont (a.begin(), a.end());
    int ans = 0;
    for(int i : divs) {
      if(cont.count(i)) {
        continue;
      }
      int l = 1;
      int cnt = 0;
      for(auto j : a) {
        if(i % j == 0) {
          l = lcm(l, j);
          ++cnt;
        }
      }
      if(l == i) {
        ans = max(ans, cnt);
      }
    }
    cout << ans << endl;
  }
}
