#include <bits/stdc++.h>
using namespace std;

int stockSpike(vector<int> prices, int k) {
    int n = prices.size();
    set<int> prev;
    set<int> next;
    vector<int> p, narr;
    int result = 0;


    for (int i = 0; i < n; i++) {
        if (prev.size() < k) {
            prev.insert(prices[i]);
        } else {
            auto max_prev = prev.rbegin();
            if (prices[i] > *max_prev) {
                p.push_back(prices[i]);
            }
            prev.insert(prices[i]);
            prev.erase(prev.begin());
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (next.size() < k) {
            next.insert(prices[i]);
        } else {
            auto max_next = next.rbegin();
            if (prices[i] > *max_next) {
                narr.push_back(prices[i]);
            }
            next.insert(prices[i]);
            next.erase(next.begin());
        }
    }

    map<int, int> temp;

    for (int i = 0; i < p.size(); i++) {
        temp[p[i]]++;
    }

    for (int i = 0; i < narr.size(); i++) {
        if (temp[narr[i]] > 0) {
            result++;
        }
    }

    return result;
}

int main() {
    int prices_count;
    cin >> prices_count;
    vector<int> prices(prices_count);

    for (int i = 0; i < prices_count; i++) {
        cin >> prices[i];
    }

    int k;
    cin >> k;

    int result = stockSpike(prices, k);
    cout << result << "\n";

    return 0;
}


// correct this code