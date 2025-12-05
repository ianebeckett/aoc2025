#include <bits/stdc++.h>
using namespace std;

//part 1

// int jolts() {
//
//     int sum{};
//     string input;
//     while (getline(cin, input)) {
//         if (input.empty()) break;
//
//         char tens = '0';
//         for (int i = 0; i < input.size() - 1; ++i) {
//             if (input[i] > tens) {
//                 tens = input[i];
//             }
//         }
//
//         int pos = input.find_first_of(tens);
//         string suffix = input.substr(pos+1);
//
//         char ones = '0';
//         for (int i = 0; i < suffix.size(); ++i) {
//             if (suffix[i] > ones) {
//                 ones = suffix[i];
//             }
//         }
//
//         int tensVal = tens - '0';
//         int onesVal = ones - '0';
//
//         sum += 10 * tensVal + onesVal;
//
//     }
//
//     return sum;
// }

pair<char, int> greatest(string s) {
    char greatest = '0';
    int idx = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] > greatest) {
            greatest = s[i];
            idx = i;
        }
    }
    return {greatest, idx};
}

//part 2
long long jolts() {
    long long sum{};
    string input;
    while (getline(cin, input)) {
        if (input.empty()) break;
        string joltage{};
        int need = 12;
        int nFound = 0;
        int i = 0;
        while (nFound < need) {
            int save = need - nFound;
            int j = input.size() - save + 1; // upper bound pos
            auto chosen = greatest(input.substr(i, j-i));
            joltage.push_back(chosen.first);
            i = i + chosen.second + 1;
            ++nFound;
        }
        //cerr << "joltage: " << joltage << endl;
        sum += stoll(joltage);
    }
    return sum;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << jolts() << endl;

    return 0;
}
