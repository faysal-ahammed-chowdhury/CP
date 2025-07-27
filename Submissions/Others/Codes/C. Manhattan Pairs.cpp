#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<pair<pair<int, int>, int>> v, v1_tmp, v2_tmp, v1, v2, v3, v4;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    v.push_back({{x, y}, i + 1});
  }
  sort(v.begin(), v.end());
  int half = n / 2;
  for (int i = 0; i < half; i++) {
    swap(v[i].first.first, v[i].first.second);
    v1_tmp.push_back(v[i]);
  }
  for (int i = half; i < n; i++) {
    swap(v[i].first.first, v[i].first.second);
    v2_tmp.push_back(v[i]);
  }

  sort(v1_tmp.begin(), v1_tmp.end());
  sort(v2_tmp.begin(), v2_tmp.end());

  int halfhalf = half / 2;
  for (int i = 0; i < halfhalf; i++) {
    swap(v2_tmp[i].first.first, v2_tmp[i].first.second);
    v1.push_back(v2_tmp[i]);
  }
  for (int i = halfhalf; i < half; i++) {
    swap(v2_tmp[i].first.first, v2_tmp[i].first.second);
    v4.push_back(v2_tmp[i]);
  }
  halfhalf = (half + 1) / 2;
  for (int i = 0; i < halfhalf; i++) {
    swap(v1_tmp[i].first.first, v1_tmp[i].first.second);
    v2.push_back(v1_tmp[i]);
  }
  for (int i = halfhalf; i < half; i++) {
    swap(v1_tmp[i].first.first, v1_tmp[i].first.second);
    v3.push_back(v1_tmp[i]);
  }

  assert(v1.size() == v3.size());
  assert(v2.size() == v4.size());

  ll sum = 0;
  vector<pair<int, int>> ans;
  for (int i = 0, j = ((int)v1.size()) - 1; i < v1.size(); i++, j--) {
    sum += abs(v1[i].first.first - v3[j].first.first);
    sum += abs(v1[i].first.second - v3[j].first.second);
    ans.push_back({v1[i].second, v3[j].second});
  }
  for (int i = 0, j = ((int)v2.size()) - 1; i < v2.size(); i++, j--) {
    sum += abs(v2[i].first.first - v4[j].first.first);
    sum += abs(v2[i].first.second - v4[j].first.second);
    ans.push_back({v2[i].second, v4[j].second});
  }

  // cout << sum << '\n';
  sort(ans.begin(), ans.end());
  for (auto [x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}