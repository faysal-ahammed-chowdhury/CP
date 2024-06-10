#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool is_prime(int n) {
  if(n == 2) return true;
  if(n < 2 || n % 2 == 0) return false;
  int limit = sqrt(n + 1);
  for(int i = 2; i <= limit; i++) {
    if(n % i == 0) {
      return false;
    }
  }
  return true;
}

bool is_perfect_square(int n) {
  int x = round(sqrt(n));
  if(x * x == n) return true;
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k; cin >> k;
  string s; cin >> s;
  int ans = 0;
  for(auto i: s) {
    int n = i - '0';
    if((is_prime(n) || is_perfect_square(n)) && n != 0) {
      ans++;
    }
  }
  cout << ans << '\n';
        
  return 0;
}