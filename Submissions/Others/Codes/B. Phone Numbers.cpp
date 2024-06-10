#include <bits/stdc++.h>
using namespace std;

int unique_number_count(string s) {
    set<char> se;
    for(auto i: s) {
        if(isdigit(i)) {
            se.insert(i);
        }
    }
    return (int)se.size();
}

bool is_pizza_number(string s) {
    int last = s[0] - '0';
    for(auto i: s) {
        if(isdigit(i)) {
            if((i - '0') > last) {
                return false;
            }
            last = i - '0';
        }
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<map<string, int>> a(n);
    vector<string> names(n);
    int max_taxi = INT_MIN, max_pizza = INT_MIN, max_girl = INT_MIN;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        string name; cin >> name;
        names[i] = name;
        while(x--) {
            string s; cin >> s;
            int count = unique_number_count(s);
            if(count == 1) {
                a[i]["taxi"]++;
            }
            else if(count == 6 && is_pizza_number(s)) {
                a[i]["pizza"]++;
            }
            else {
                a[i]["girl"]++;
            }
        }
        max_girl = max(max_girl, a[i]["girl"]);
        max_pizza = max(max_pizza, a[i]["pizza"]);
        max_taxi = max(max_taxi, a[i]["taxi"]);
    }

    vector<string> taxi, pizza, girl;
    for(int i = 0; i < n; i++) {
        if(a[i]["taxi"] == max_taxi) taxi.push_back(names[i]);
        if(a[i]["pizza"] == max_pizza) pizza.push_back(names[i]);
        if(a[i]["girl"] == max_girl) girl.push_back(names[i]);
    }
    cout << "If you want to call a taxi, you should call: ";
    for(int i = 0; i + 1 < (int)taxi.size(); i++) {
        cout << taxi[i] << ", ";
    }
    cout << taxi.back() << ".\n";
    cout << "If you want to order a pizza, you should call: ";
    for(int i = 0; i + 1 < (int)pizza.size(); i++) {
        cout << pizza[i] << ", ";
    }
    cout << pizza.back() << ".\n";
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    for(int i = 0; i + 1 < (int)girl.size(); i++) {
        cout << girl[i] << ", ";
    }
    cout << girl.back() << ".\n";

    return 0;
}