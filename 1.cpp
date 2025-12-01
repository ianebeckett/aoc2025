#include <bits/stdc++.h>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;

// //part 1
// int zeroes() {
//     string step;
//     int pos = 50;
//     int zeroes{};
//     while (cin >> step) {
//         if (step[0] == 'L') {
//             pos -= stoi(step.substr(1));
//         } else if (step[0] == 'R') {
//             pos += stoi(step.substr(1));
//         }
//         pos = (pos % 100);
//         if (pos == 0) {
//             ++zeroes;
//         }
//     }
//     return zeroes;
// }


//part 2
int zeroes() {
    string step;
    int prev = 50;
    int zeroes = 0;
    while (cin >> step) {
        int amount = stoi(step.substr(1));
        if (!amount) continue;
        int curr = (step[0] == 'L') ? prev - amount : prev + amount;
        if (prev && curr <= 0) {
            ++zeroes;
        }
        zeroes += (curr < 0) ? -curr / 100 : curr / 100;
        prev = (curr < 0) ? 100 - (-curr % 100) : curr % 100;
        if (prev == 100) prev = 0; // oops
        //cout << "prev: " << prev << endl;
    }
    return zeroes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << zeroes() << endl;
    return 0;
}
