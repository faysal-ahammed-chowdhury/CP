#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  map<int, int> bonus;
  for (int i = 50; i >= 11; i--) {
    bonus[i] = 50 - i + 1;
  }
  bonus[10] = 42;
  bonus[9] = 44;
  bonus[8] = 46;
  bonus[7] = 48;
  bonus[6] = 50;
  bonus[5] = 53;
  bonus[4] = 57;
  bonus[3] = 62;
  bonus[2] = 68;
  bonus[1] = 80;

  int n; cin >> n;
  vector<pair<pair<int, int>, string>> v;
  for (int i = 1; i <= n; i++) {
    string team; cin >> team;
    int cnt, rank; cin >> cnt >> rank;
    v.push_back({{ -cnt, rank}, team});
  }

  sort(v.begin(), v.end());
  int R1 = 10 * -v[0].first.first;
  if (v[0].first.second <= 50) R1 += 2 * bonus[v[0].first.second];
  for (int i = 1; i < min((ll)v.size(), 3ll); i++) {
    if (v[i].first.second <= 50) R1 += bonus[v[i].first.second];
  }

  cin >> n;
  v.clear();
  for (int i = 1; i <= n; i++) {
    string team; cin >> team;
    int cnt, rank; cin >> cnt >> rank;
    v.push_back({{ -cnt, rank}, team});
  }

  sort(v.begin(), v.end());
  int R2 = 10 * -v[0].first.first;
  if (v[0].first.second <= 50) R2 += 2 * bonus[v[0].first.second];
  for (int i = 1; i < min((ll)v.size(), 3ll); i++) {
    if (v[i].first.second <= 50) R2 += bonus[v[i].first.second];
  }

  cin >> n;
  v.clear();
  for (int i = 1; i <= n; i++) {
    string team; cin >> team;
    int cnt, rank; cin >> cnt >> rank;
    v.push_back({{ -cnt, rank}, team});
  }

  sort(v.begin(), v.end());
  int R3 = 10 * -v[0].first.first;
  if (v[0].first.second <= 50) R3 += 2 * bonus[v[0].first.second];
  for (int i = 1; i < min((ll)v.size(), 3ll); i++) {
    if (v[i].first.second <= 50) R3 += bonus[v[i].first.second];
  }

  int R = 4 * R1 + 3ll * R2 + 2 * R3;

  cout << R << '\n';

  return 0;
}