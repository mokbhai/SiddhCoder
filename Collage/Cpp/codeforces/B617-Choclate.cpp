#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int n, e, cnt = 1, ans = 1; cin >> n;
    int prevIdx = 0;
    for (int i = 0; i < n; i++) {
        cin >> e;
        if (e == 1) {
            if (cnt > 1) {
                ans *= i - prevIdx;
            } 
            
            prevIdx = i;
            cnt++;
        }
    }
    
    cout << ans;
    return 0;
}