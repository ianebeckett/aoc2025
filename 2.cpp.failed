#include <bits/stdc++.h>
using namespace std;

typedef vector<int64_t> vi;
typedef pair<int64_t, int64_t> ii;
typedef vector<vector<int64_t>> vvi;
typedef vector<pair<int64_t, int64_t>> vii;

int64_t sumInvalid(){
    string input;
    long long sum = 0;
    //cerr << endl;
    while (getline(cin, input, ',')) {

        // The number of invalid IDs in the range of two equal-length numbers = (len/2) digits of 9, minus 1.
        // let i be len. Then:
        //
        //                  b
        // f(10^a, 10^b) = sum( f(10^i, 10^(i+1) - 1) ) - 1
        //                 i=a
        //


        //cerr << "input:" << input << endl;
        istringstream iss(input);
        auto dashPos = input.find_first_of('-');
        pair<long long, long long> range = {stoll(input.substr(0, dashPos)), stoll(input.substr(dashPos+1))};
        //cerr << "    range:" << range.first << "-" << range.second << endl;

        if (range.second < range.first) {
            //cerr << "second " << range.second << " < first: " << range.first << endl;
            continue;
        }
        if (range.second < 0) {
            //cerr << "second < 0" << endl;
            continue;
        }
        if (range.first < 0) {
            //cerr << "first < 0" << endl;
            range.first = 0;
        }

        for (long long i = range.first; i <= range.second; ++i) {

            if (i == range.second && range.first == range.second) {
                //cerr << "first and second are same number and already counted once. i == " << i  << endl;
                continue;
            }

            if (i >= 0 && i < 10) {
                //cerr << "single digit: " << i << endl;
                continue;
            }

            string istr = to_string(i);
            if (istr.size() % 2) {
                //cerr << "    istr has odd length: " << istr << endl;
                continue;
            }

            int mid = istr.size() / 2;
            if (istr.substr(0, mid) == istr.substr(mid)) {
                //cerr << i << " is invalid: " << istr.substr(0,mid) << " == " << istr.substr(mid) << endl;
                sum += i;
            }
        }
    }
     //30323879688 wrong
    return sum;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << endl << to_string(sumInvalid()) << endl;
    return 0;
}
