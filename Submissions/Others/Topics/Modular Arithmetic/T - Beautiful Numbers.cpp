#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1e6 + 9;
int a, b, n, fact[N];

void calc_fact() {
  fact[0] = 1, fact[1] = 1;
  for(int i = 2; i < N; i++) {
    fact[i] = (1LL * fact[i - 1] * i) % mod;
  }
}

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

bool excellent(int x) {
  while(x > 0) {
    if(x % 10 != a && x % 10 != b) {
      return false;
    }
    x /= 10;
  }
  return true;
}

int combination(int a_cnt, int b_cnt) {
  int upper = fact[n];
  int down = (1LL * fact[a_cnt] * fact[b_cnt]) % mod;
  int down_inverse = power(down, mod - 2);
  return (1LL * upper * down_inverse) % mod;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  calc_fact();

  cin >> a >> b >> n;
  long long ans = 0;
  for(int i = 0; i <= n; i++) {
    int a_cnt = i;
    int b_cnt = n - i;
    int sum_of_digits = (a * a_cnt) + (b * b_cnt);
    if(excellent(sum_of_digits)) {
      ans += combination(a_cnt, b_cnt);
      ans %= mod;
    }
  }
  cout << ans << '\n';

  return 0;
}