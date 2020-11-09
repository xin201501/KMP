#pragma once
#include<vector>
#include<string_view>
#include<optional>
auto getNextArr(std::string_view matcher) {
    std::vector<size_t> result;
    result.resize(matcher.size());
    result[0] = -1;
    if (result.size() == 1) {
        return result;
    }
    result[1] = 0;
    if (result.size() == 2) {
        return result;
    }
    size_t size = matcher.size(), pos = 2, matchPos = 0;
    while (pos < size) {
        if (matcher[pos - 1] == matcher[matchPos]) {
            result[pos++] = ++matchPos;
        }
        else if (matchPos > 0) {
            matchPos = result[matchPos];
        }
        else {
            result[pos++] = 0;
        }
    }
    return result;
}
auto KMPMainline(std::string_view matchedString, std::string_view matcher, const std::vector<size_t>& nextArr) {
    size_t pos1 = 0, pos2 = 0, size1 = matchedString.size(), size2 = matcher.size();
    while (pos1 < size1 && pos2 < size2) {
        if (matchedString[pos1] == matcher[pos2]) {
            pos1++;pos2++;
        }
        else if (pos2 == 0) {
            pos1++;
        }
        else {
            pos2 = nextArr[pos2];
        }
    }
    return pos2 == size2 ? std::make_optional(pos1 - pos2) : std::nullopt;
}
auto KMP(std::string_view matchedString, std::string_view matcher) {
    return KMPMainline(matchedString, matcher, getNextArr(matcher));
}