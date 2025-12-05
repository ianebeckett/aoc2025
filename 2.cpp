#include <bits/stdc++.h>
using namespace std;

typedef vector<int64_t> vi;
typedef pair<int64_t, int64_t> ii;
typedef vector<vector<int64_t>> vvi;
typedef vector<pair<int64_t, int64_t>> vii;

// part 1
// bool isInvalid(long long n) {
//     string s = to_string(n);
//     if (s.size() % 2) {
//         return false;
//     }
//     if (s.substr(0, s.size()/2) == s.substr(s.size()/2)) {
//         return true;
//     }
//     return false;
// }

// part 2
bool isInvalid(long long num) {
    string s = to_string(num);
    for (int patternLen = 1; patternLen <= s.size()/2; ++patternLen) {
        if (s.size() % patternLen) continue;
        string pattern = s.substr(0, patternLen);
        bool isRepeating = true;
        for (int j = patternLen; j < s.size(); j += patternLen) {
            if (s.substr(j, patternLen) != pattern) {
                isRepeating = false;
                break;
            }
        }
        if (isRepeating) {
            return true;
        }
    }
    return false;
}

long long sumInvalid(){
    string range;
    long long sum = 0;
    while (getline(cin, range, ',')) {
        long long begin, end;
        sscanf(range.c_str(), "%lld-%lld", &begin, &end);
        for (long long n = begin; n <= end; ++n) {
            if (isInvalid(n)) {
                sum += n;
            }
        }
    }
    return sum;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << endl << to_string(sumInvalid()) << endl;
    return 0;
}
