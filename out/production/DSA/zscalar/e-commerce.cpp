#include <bits/stdc++.h>
using namespace std;

int minCostToPurchaseAll(vector<string>& products, vector<pair<char, int>>& discounts) {
    int totalCost = 0;

    int discountType0 = INT_MAX;
    int discountType1 = INT_MAX;

    for (int i = 0; i < products.size(); ++i) {
        int productCost = 0;

        for (char tag : products[i]) {
            if (tag == 'd') {
                int discount = discounts[i].second;
                char discountType = discounts[i].first;

                if (discountType == '0') {
                    productCost += discount;
                } else if (discountType == '1') {
                    discountType1 = min(discountType1, discount);
                }
            } else if (tag >= '0' && tag <= '9') {
                productCost += tag - '0';
            }
        }

        totalCost += productCost;
    }

    // Apply type 1 discount if available
    if (discountType1 != INT_MAX) {
        totalCost -= (totalCost * discountType1) / 100;
    }

    return totalCost;
}

int main() {
    vector<string> products = {"123d", "456d", "78d"};
    vector<pair<char, int>> discounts = {{'0', 5}, {'1', 10}, {'1', 15}};

    int result = minCostToPurchaseAll(products, discounts);
    cout << "Total cost after discounts: " << result << endl;

    return 0;
}
