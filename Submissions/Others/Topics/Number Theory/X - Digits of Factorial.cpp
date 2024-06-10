#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
vector<double> log10n(N, 0);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  double ans = 0;
  for(int i = 1; i < N; i++) {
    ans += log10(i);
    log10n[i] = ans;
  }

  int t, cs = 0; cin >> t;
  while(t--) {
    int n, base; cin >> n >> base;
    cout << "Case " << ++cs << ": ";
    cout << (long long)(log10n[n] / log10(base)) + 1 << '\n';
  }

  return 0;
}