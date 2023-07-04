#include <bits/stdc++.h>
using namespace std;
int evaluate_polynomial(vector<int> coefficients, int n) {
    int result = 0;
    
    for (int i = 0; i < coefficients.size(); i++) {
        result += coefficients[i] * pow(n, i);
    }
    
    return result;
}

int main() {
    vector<int> coefficients = {9, 2, 4};
    int n = 5;
    int result = evaluate_polynomial(coefficients, n);
    cout << "f(" << n << ") = " << result << endl;
    
    return 0;
}
