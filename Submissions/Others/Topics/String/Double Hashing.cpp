#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
pair<int, int> pw[N];

void prec() {
  pw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1ll * p1 * pw[i - 1].first % MOD1;
    pw[i].second = 1ll * p2 * pw[i - 1].second % MOD2;
  }
}

pair<int, int> get_hash(string &s) {
  int n = s.size();
  pair<int, int> hash_val = {0, 0};
  for (int i = 0; i < n; i++) {
    hash_val.first += 1ll * s[i] * pw[i].first % MOD1;
    hash_val.first %= MOD1;
    hash_val.second += 1ll * s[i] * pw[i].second % MOD2;
    hash_val.second %= MOD2;
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