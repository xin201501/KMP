#pragma once
#include<cstring>
#include<optional>
auto violentMatch(const char s[], const char p[]) {
    size_t slen = strlen(s), plen = strlen(p);
    size_t i = 0, j = 0;
    while (i < slen && j < plen) {
        if (s[i] == p[j]) {
            i++;
            j++;
        }
        else {
            i = i - (j - 1);
            j = 0;
        }
    }
    return j == plen ? std::make_optional(i - j) : std::nullopt;
}