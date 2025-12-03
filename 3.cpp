#include <bits/stdc++.h>
using namespace std;

part 1
int jolts(){

    int sum{};
    string input;
    while (getline(cin, input)) {
        if (input.empty()) break;

        char tens = '0';
        for (int i = 0; i < input.size() - 1; ++i) {
            if (input[i] > tens) {
                tens = input[i];
            }
        }

        int pos = input.find_first_of(tens);
        string suffix = input.substr(pos+1);

        char ones = '0';
        for (int i = 0; i < suffix.size(); ++i) {
            if (suffix[i] > ones) {
                ones = suffix[i];
            }
        }

        int tensVal = tens - '0';
        int onesVal = ones - '0';

        sum += 10 * tensVal + onesVal;

    }

    return sum;
}

//part 2 failed, doesn't terminate
// long long jolts(){
//
//     long long sum{};
//     string input;
//     while (getline(cin, input)) {
//         if (input.empty()) break;
//
//         string found{};
//         int need = 12;
//         int nFound = 0;
//         while (nFound < need) {
//
//             char digit = '0';
//             int j = 0;
//             for (int i = 0; i < input.size() - need + nFound + 1; ++i) {
//                 if (input[i] > digit) {
//                     digit = input[i];
//                     j = i;
//                 }
//                 i = j;
//             }
//
//             found.push_back(digit);
//             ++nFound;
//         }
//         sum += stoll(found);
//     }
//
//     return sum;
// }

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << jolts() << endl;

    return 0;
}
