#include<iostream>
#include<KMP.h>
#include<violentstringmatch.h>
#include<string>
#include<array>
#include<ctime>
using std::cin, std::cout, std::endl, std::cerr;
int main(int argc, char const* argv[]) {
    std::string source = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string matchedString, matcher;
    srand(time(0));
    auto time = std::time(0);
    for (size_t i = 1;i <= 500000;i++) {
        if (0 == i % 10000) {
            cout << i << endl;
        }
        for (size_t j = 0;j < 10000;j++) {
            matchedString += source[rand() % 52];
        }
        for (size_t j = 0;j < 1000;j++) {
            matcher += source[rand() % 52];
        }
        KMP(matchedString, matcher);
        //violentMatch(matchedString.c_str(), matcher.c_str());
        // auto res1 = KMP(matchedString, matcher), res2 = violentMatch(matchedString.c_str(), matcher.c_str());
        // if (res1 != res2) {
        //     cerr << "error:matchedString:" << matchedString << ' ' << "matcher:" << matcher << endl
        //         << "res1:" << res1.value_or(-1) << ' ' << "res2:" << res2.value_or(-1);
        //     return 0;
        // }
        matchedString.clear();
        matcher.clear();
    }
    cout << std::time(0) - time << endl;
    return 0;
}