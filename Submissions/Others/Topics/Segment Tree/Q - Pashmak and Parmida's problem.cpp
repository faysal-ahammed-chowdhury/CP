#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// @author: faysalahammedchowdhury

const int N = 1e6 + 9;
int a[N], freq_1_to_i[N], freq_i_to_n[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<int, int> freq;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    freq[a[i]]++;
    freq_1_to_i[i] = freq[a[i]];
  }

  for(int i = 1; i <= n; i++) {
    freq_i_to_n[i] = freq[a[i]] - freq_1_to_i[i] + 1;
  }

  long long ans = 0;
  o_set<pair<int, int>> se; 
  for(int i = n; i > 0; i--) {
    ans += se.order_of_key({freq_1_to_i[i], i});
    se.insert({freq_i_to_n[i], i});
  }

  cout << ans << '\n';

  return 0;
}