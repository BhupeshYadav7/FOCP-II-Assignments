#include <iostream>
#include <cmath>
#include <numeric> 
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int count = 0;

        for (int i = 1; i <= sqrt(N); i++) {
            if (N % i == 0) {
                int a = i;
                int b = N / i;

            
                if (gcd(a, b) == 1) {
                    if (a == b) {
                        count += 1; 
                    } else {
                        count += 2; 
                    }
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}