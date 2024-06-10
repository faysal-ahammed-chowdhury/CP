#include <bits/stdc++.h>
using namespace std;

const int mod = 1000003, N = 1e6 + 9;
int fact[N];

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

int nCk(int n, int k) {
  int upper = fact[n];
  int lower = (1LL * fact[n - k] * fact[k]) % mod;
  int lower_inverse = power(lower, mod - 2);
  return (1LL * upper * lower_inverse) % mod;
}

int cs = 0;
void solve() {
  int n, k; cin >> n >> k;
  cout << "Case " << ++cs << ": ";
  cout << nCk(n, k) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  calc_fact();

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}