#include "Tree.h"

#include "TreeNode.h"

// 129. Sum Root to Leaf Numbers
int sumNumbers(TreeNode* root) {
    int sum;
    vector<TreeNode*> s;
    TreeNode *p = root, *pre;
    while (!s.empty() || p) {
        if (p) {
            s.push_back(p);
            p = p->left;
        } else {
            p = s.back();
            if (!p->left && !p->right) {
                int tmp = 0;
                for (int i = 0; i < s.size(); ++i)
                    tmp = tmp * 10 + s[i]->val;
                sum += tmp;
            }

            if (p->right && pre != p->right) {
                p = p->right;
            } else {
                s.pop_back();
                pre = p;
                p = nullptr;
            }
        }
    }

    return sum;
}

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

// 114. Flatten Binary Tree to Linked List
void Tree::flatten(TreeNode *root) {
    if (!root)
        return;
    if (root->left) // flatten left or right first doesn't matter
        flatten(root->left);
    if (root->right)
        flatten(root->right);

    TreeNode *tmp = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (root->right)
        root = root->right;
    root->right = tmp;
}

void flatten(TreeNode *root) {
    TreeNode *cur = root;
    while (cur) {
        if (cur->left) {
            TreeNode *p = cur->left;
            while (p->right)
                p = p->right;
            p->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
        cur = cur->right;
    }
}

void flattenWithStack(TreeNode *root) {
    vector<TreeNode*> preorder;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while (!s.empty() || p) {
        if (p) {
            preorder.push_back(p);
            s.push(p);
            p = p->left;
        } else {
            p = s.top(); s.pop();
            p = p->right;
        }
    }

    for (int i = 0; i < preorder.size(); ++i) {
        preorder[i]->left = nullptr;
        preorder[i]->right = (i == preorder.size() - 1 ? nullptr : preorder[i + 1]);
    }
}
