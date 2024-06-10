#include <bits/stdc++.h>
using namespace std;

const int mod = 5;

int power(int a, int power_val) {
  if(power_val == 0) return 1;
  if(power_val & 1) {
    int val = power(a, power_val / 2);
    return ((1LL * val * val) % mod) * a % mod; 
  }
  else {
    int val = power(a, power_val / 2);
    return (1LL * val * val) % mod;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  string s; cin >> s;
  int start = s.length() - 5;
  int len = s.length();
  int n = 0;
  if(start < 0) {
    start = 0;
  }
  for(int i = start; i < len; i++) {
    n = n * 10 + (s[i] - '0');
  }

  int ans = (1 + power(2, n) + power(3, n) + power(4, n)) % mod;
  cout << ans << '\n';  

  return 0;
}