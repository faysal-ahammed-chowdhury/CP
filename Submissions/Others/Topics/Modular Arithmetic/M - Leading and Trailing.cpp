#include <bits/stdc++.h>
using namespace std;

const int mod = 1000;

int power(int n, int k) {
  if(k == 0) return 1;
  int val = power(n, k / 2);
  if(k & 1) {
    return ((1LL * val * val) % mod) * n % mod;
  }
  else {
    return (1LL * val * val) % mod;
  }
}

int first3(int n, int k) {
  double a = k * log10(n);
  double b = a - floor(a);
  double c = pow(10, b);
  return floor(c * 100);
}

void solve() {
  int n, k; cin >> n >> k;

  cout << first3(n, k) << "...";
  int last = power(n, k);
  if(last < 10) {
    cout << "00" << last << '\n';
  }
  else if(last < 100) {
    cout << "0" << last << '\n';
  }
  else {
    cout << last << '\n';
  }
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