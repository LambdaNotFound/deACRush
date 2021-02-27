#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../Design/Read4.h"
#include "../ModernCpp/Wargame.h"

TEST(Facebook2015, SortNumberAsString) {
    vector<int> input = { 1510, 5710, 358 };
    vector<int> expected = { 1510, 358, 5710};

    sort(input.begin(), input.end(), [](int a, int b){
        return to_string(a) < to_string(b);
    });

    EXPECT_EQ(input, expected);
}

TEST(Wayfair0221, StringSanitizing) {
    string input = "1,2,3,4,5";
    string token = ",";
    vector<string> expected = { "1", "2", "3", "4", "5" };

    auto res = split(input, token);
    EXPECT_EQ(res, expected);

    input = "1,2,3,";
    expected = { "1", "2", "3" };
    res = split(input, token);
    EXPECT_EQ(res, expected);

    input = "1";
    expected = { "1" };
    res = split(input, token);
    EXPECT_EQ(res, expected);

    input = "";
    expected = { };
    res = split(input, token);
    EXPECT_EQ(res, expected);

    input = ",";
    expected = { };
    res = split(input, token);
    EXPECT_EQ(res, expected);

    input = ",,,1";
    expected = { "1" };
    res = split(input, token);
    EXPECT_EQ(res, expected);
}

/*
We have some clickstream data that we gathered on our client's website. Using cookies, we collected snippets of users' anonymized URL histories while they browsed the site. The histories are in chronological order, and no URL was visited more than once per person.

Write a function that takes two users' browsing histories as input and returns the longest contiguous sequence of URLs that appears in both.

Sample input:

user0 = ["/start", "/green", "/blue", "/pink", "/register", "/orange", "/one/two"]
user1 = ["/start", "/pink", "/register", "/orange", "/red", "a"]
user2 = ["a", "/one", "/two"]
user3 = ["/pink", "/orange", "/yellow", "/plum", "/blue", "/tan", "/red", "/amber", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow", "/BritishRacingGreen"]
user4 = ["/pink", "/orange", "/amber", "/BritishRacingGreen", "/plum", "/blue", "/tan", "/red", "/lavender", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow"]
user5 = ["a"]
user6 = ["/pink","/orange","/six","/plum","/seven","/tan","/red", "/amber"]

Sample output:

findContiguousHistory(user0, user1) => ["/pink", "/register", "/orange"]
findContiguousHistory(user0, user2) => [] (empty)
findContiguousHistory(user2, user1) => ["a"]
findContiguousHistory(user5, user2) => ["a"]
findContiguousHistory(user3, user4) => ["/plum", "/blue", "/tan", "/red"]
findContiguousHistory(user4, user3) => ["/plum", "/blue", "/tan", "/red"]
findContiguousHistory(user3, user6) => ["/tan", "/red", "/amber"]

n: length of the first user's browsing history
m: length of the second user's browsing history
*/

TEST(Wayfair0221, LongestCommonSubstring) {


}
