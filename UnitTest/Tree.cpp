#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "TreeNode.h"
#include "../ProblemSet/Tree.h"

using namespace std;

TEST(L572SubtreeOfAnotherTree, TreeRecursion) {
    Tree sln;

    unique_ptr<TreeNode> p = make_unique<TreeNode>(1);
    unique_ptr<TreeNode> pleft = make_unique<TreeNode>(2); p->left = pleft.get();
    unique_ptr<TreeNode> pright = make_unique<TreeNode>(3); p->right = pright.get();

    unique_ptr<TreeNode> q = make_unique<TreeNode>(1);
    unique_ptr<TreeNode> qleft = make_unique<TreeNode>(2); q->left = qleft.get();

    bool expected = false;
    bool result = sln.isSubtreeSerialize(p.get(), q.get());
    EXPECT_EQ(result, expected);
}

TEST(L126WordLadderII, BFS) {
    Tree sln;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
    vector<vector<string> > expected = { {"hit","hot","dot","dog","cog"}, {"hit","hot","lot","log","cog"} };

    auto result = sln.findLadders(beginWord, endWord, wordList);
    EXPECT_THAT(result, ::testing::UnorderedElementsAreArray(expected));

    result = sln.findLadders2(beginWord, endWord, wordList);
    EXPECT_THAT(result, ::testing::UnorderedElementsAreArray(expected));
}
