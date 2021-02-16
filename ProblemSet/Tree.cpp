#include "Tree.h"

#include "TreeNode.h"

// 100. Same Tree
bool Tree::isSameTree(TreeNode* p, TreeNode* q) {
    if (p && q) {
        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    } else
        return !p && !q;
}

bool Tree::isSameTreeSerialize(TreeNode* p, TreeNode* q) {
    return serializeTreePreorder(p).str() == serializeTreePreorder(q).str();
}
ostringstream Tree::serializeTreePreorder(TreeNode* root) {
    ostringstream res;

    stack<TreeNode*> s;
    TreeNode *p = root;
    while (!s.empty() || p)
        if (p) {
            res << "|" << p->val;
            s.push(p);
            p = p->left;
        } else {
            res << "|#";
            p = s.top(); s.pop();
            p = p->right;
        }

    return res;
}

// 572. Subtree of Another Tree
bool Tree::isSubtree(TreeNode* s, TreeNode* t) {
    if (!s)
        return false;
    if (isSameTree(s, t))
        return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

bool Tree::isSubtreeSerialize(TreeNode* s, TreeNode* t) {
    ostringstream ss, st;
    isSubtreeSerializeHelper(s, ss);
    isSubtreeSerializeHelper(t, st);
    return ss.str().find(st.str()) != string::npos;
}
void Tree::isSubtreeSerializeHelper(TreeNode* node, ostringstream& os) {
    if (!node)
        os << "|#";
    else {
        os << "|" << node->val;
        isSubtreeSerializeHelper(node->left, os);
        isSubtreeSerializeHelper(node->right, os);
    }
}
