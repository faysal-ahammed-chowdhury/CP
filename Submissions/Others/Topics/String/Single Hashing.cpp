#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;

const int MOD = 1e9 + 7;
const int p1 = 137;
int pw[N];
void prec() {
  pw[0] = 1;
  for (int i = 1; i < N; i++) {
    pw[i] = 1ll * pw[i - 1] * p1 * MOD;
  }
}

int get_hash(string &s) {
  int n = s.size();
  int hash_val = 0;
  for (int i = 0; i < n; i++) {
    hash_val += 1ll * s[i] * pw[i] % MOD;
    hash_val %= MOD;
  }
  return hash_val;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  prec();
  string s1, s2; cin >> s1 >> s2;
  if (get_hash(s1) == get_hash(s2)) {
    cout << "same\n";
  }
  else {
    cout << "not same\n";
  }

  return 0;
}