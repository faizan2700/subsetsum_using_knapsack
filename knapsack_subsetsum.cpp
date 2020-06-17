#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


///Please select contact the author for well commented and readable code
///this code is written for demonstration purpose.
///this code also does not check for negative subset-sum. contact author for full functionalality.
///Author : faizan2700

ll dp[1000][1000];

int main(){
    ll n, w;cin >> n >> w;
    vector<ll> v(n, 0);
    ll i, j;
    if(w < 0){
        cout<<"Please contact author for this functionality. negative subset-sum is intentionally left. and will be provided after you buy full gig."<< endl;
        return 0;
    }
    for(i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(i = 0; i < n; ++i){
        for(j = 0; j <= w; ++j){
            if(dp[i][j]==1){
                ll new_sum = j + v[i];
                dp[i+1][j] = 1;
                if(new_sum >= 0 && new_sum <= w){
                    dp[i+1][new_sum] = 1;
                }
            }
        }
    }
    if(dp[n][w]){
        cout << "POSSIBLE" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}
