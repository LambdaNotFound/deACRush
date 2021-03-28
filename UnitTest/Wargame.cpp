#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../Design/Read4.h"
#include "../ModernCpp/Wargame.h"

TEST(Facebook15, SortNumberAsString) {
    vector<int> input = { 1510, 5710, 358 };
    vector<int> expected = { 1510, 358, 5710};

    sort(input.begin(), input.end(), [](int a, int b){
        return to_string(a) < to_string(b);
    });

    EXPECT_EQ(input, expected);
}

TEST(Wayfair21, StringSanitizing) {
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

TEST(Wayfair21, LongestCommonSubstring) {
    vector<string> user0 = { "/start", "/green", "/blue", "/pink", "/register", "/orange", "/one/two" };
    vector<string> user1 = { "/start", "/pink", "/register", "/orange", "/red", "a" };
    vector<string> expected = { "/pink", "/register", "/orange" };

    vector<string> res = findContiguousHistory(user0, user1);
    EXPECT_EQ(res, expected);

    vector<string> user3 = { "/pink", "/orange", "/yellow", "/plum", "/blue", "/tan", "/red", "/amber", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow", "/BritishRacingGreen" };
    vector<string> user4 = { "/pink", "/orange", "/amber", "/BritishRacingGreen", "/plum", "/blue", "/tan", "/red", "/lavender", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow" };
    expected = { "/plum", "/blue", "/tan", "/red" };

    res = findContiguousHistory(user3, user4);
    EXPECT_EQ(res, expected);
}

/*

Suppose we have some input data describing a graph of relationships between parents and children over multiple generations. The data is formatted as a list of (parent, child) pairs, where each individual is assigned a unique positive integer identifier.

For example, in this diagram, 6 and 8 have common ancestors of 4 and 14.

             15
             |
         14  13
         |   |
1   2    4   12
 \ /   / | \ /
  3   5  8  9
   \ / \     \
    6   7     11

parent_child_pairs_1 = [
    (1, 3), (2, 3), (3, 6), (5, 6), (5, 7), (4, 5),
    (4, 8), (4, 9), (9, 11), (14, 4), (13, 12),
   (12, 9), (15, 13)
]

Write a function that takes the graph, as well as two of the individuals in our dataset, as its inputs and returns true if and only if they share at least one ancestor.

Sample input and output:

has_common_ancestor(parent_child_pairs_1, 3, 8) => false
has_common_ancestor(parent_child_pairs_1, 5, 8) => true
has_common_ancestor(parent_child_pairs_1, 6, 8) => true
has_common_ancestor(parent_child_pairs_1, 6, 9) => true
has_common_ancestor(parent_child_pairs_1, 1, 3) => false
has_common_ancestor(parent_child_pairs_1, 3, 1) => false
has_common_ancestor(parent_child_pairs_1, 7, 11) => true
has_common_ancestor(parent_child_pairs_1, 6, 5) => true
has_common_ancestor(parent_child_pairs_1, 5, 6) => true

Additional example: In this diagram, 4 and 12 have a common ancestor of 11.

        11
       /  \
      10   12
     /  \
1   2    5
 \ /    / \
  3    6   7
   \        \
    4        8

parent_child_pairs_2 = [
    (1, 3), (11, 10), (11, 12), (2, 3), (10, 2),
    (10, 5), (3, 4), (5, 6), (5, 7), (7, 8),
]

has_common_ancestor(parent_child_pairs_2, 4, 12) => true
has_common_ancestor(parent_child_pairs_2, 1, 6) => false
has_common_ancestor(parent_child_pairs_2, 1, 12) => false

n: number of pairs in the input


*/

TEST(Wayfair21, GraphCommonAncestorBFS) {
    vector<pair<int, int> > parent_child_pairs_1 = {
        make_pair(1, 3),
        make_pair(2, 3),
        make_pair(3, 6),
        make_pair(5, 6),
        make_pair(5, 7),
        make_pair(4, 5),
        make_pair(4, 8),
        make_pair(4, 9),
        make_pair(9, 11),
        make_pair(14, 4),
        make_pair(13, 12),
        make_pair(12, 9),
        make_pair(15, 13)
    };

    bool res = hasCommonAncestor(parent_child_pairs_1, 3, 8);
    EXPECT_EQ(res, false);

    res = hasCommonAncestor(parent_child_pairs_1, 5, 8);
    EXPECT_EQ(res, true);

    res = hasCommonAncestor(parent_child_pairs_1, 6, 8);
    EXPECT_EQ(res, true);

    vector<pair<int, int>> parent_child_pairs_2 = {
        make_pair(1, 3),
        make_pair(11, 10),
        make_pair(11, 12),
        make_pair(2, 3),
        make_pair(10, 2),
        make_pair(10, 5),
        make_pair(3, 4),
        make_pair(5, 6),
        make_pair(5, 7),
        make_pair(7, 8)
    };

    res = hasCommonAncestor(parent_child_pairs_2, 4, 12);
    EXPECT_EQ(res, true);

    res = hasCommonAncestor(parent_child_pairs_2, 1, 6);
    EXPECT_EQ(res, false);
}

TEST(Uber21, CountSubsegmentsPrefixSum) {
    vector<int> input{1, 1, 1};
    int expected = 1;

    int res = countSubsegments(input);
    EXPECT_EQ(res, expected);

    input = { 1, 2, 2, 2, 5, 0 };
    expected = 3;
    res = countSubsegments(input);
    EXPECT_EQ(res, expected);
}
