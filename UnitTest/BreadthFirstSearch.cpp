#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../ProblemSet/BreadthFirstSearch.h"

TEST(L126WordLadderII, BFS) {
    BreadthFirstSearch sln;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
    vector<vector<string> > expected = { {"hit","hot","dot","dog","cog"}, {"hit","hot","lot","log","cog"} };

    auto result = sln.findLadders(beginWord, endWord, wordList);
    EXPECT_THAT(result, ::testing::UnorderedElementsAreArray(expected));

    result = sln.findLadders2(beginWord, endWord, wordList);
    EXPECT_THAT(result, ::testing::UnorderedElementsAreArray(expected));
}s
