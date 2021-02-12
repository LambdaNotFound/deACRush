#ifndef ACRUSH_TREENODE_H
#define ACRUSH_TREENODE_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // helper methods
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* leftChild, TreeNode* rightChild) :
            val(x), left(leftChild), right(rightChild) {}

    std::size_t depth() const {
        const size_t leftDepth = left ? left->depth() : 0;
        const size_t rightDepth = right ? right->depth() : 0;
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
};


#endif //ACRUSH_TREENODE_H
