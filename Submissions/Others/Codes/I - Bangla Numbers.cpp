#include <bits/stdc++.h>
using namespace std;

bool solve(long long taka) {
    if(taka <= 0) {
        return false;
    }
    int shata = taka % 10;
    taka /= 10;
    int hajar = taka % 100;
    taka /= 100;
    int lakh = taka % 100;
    taka /= 100;
    int kuti = taka % 100;
    taka /= 100;
    bool ans = solve(taka);
    bool used = false;
    if(kuti > 0) {
        cout << ' ' << kuti << " kuti";
        used = true;
    }
    else if(ans && used == false) {
        cout << " kuti";
        used = true;
    }
    if(lakh > 0) {
        cout << ' ' << lakh << " lakh";
        used = true;
    }
    else if(ans && used == false) {
        cout << " lakh";
        used = true;
    }
    if(hajar > 0) {
        cout << ' ' << hajar << " hajar";
        used = true;
    }
    else if(ans && used == false) {
        cout << " hajar";
        used = true;
    }
    if(shata > 0) {
        cout << ' ' << shata << " shata";
        used = true;
    }
    else if(ans && used == false) {
        cout << " shata";
        used = true;
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
    long long taka; 
    int t = 0;
    while(cin >> taka) {
        stringstream ss;
        t++;
        ss << t;
        string s; ss >> s;
        int len = 4 - s.length();
        for(int i = 1; i <= len; i++) {
            cout << ' ';
        }
        cout << t << ".";
        if(taka == 0) {
            cout << " 0\n";
            continue;
        }
        solve(taka / 100);
        if(taka % 100 > 0) cout << ' ' << taka % 100;
        cout << '\n';
    }
    return 0;
}