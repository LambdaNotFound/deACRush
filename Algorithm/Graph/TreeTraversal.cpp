#include "TreeTraversal.h"

#include "../DataStructure/TreeNode.h"

// 144. Binary Tree Preorder Traversal
vector<int> TreeTraversal::preorderTraversal(TreeNode* root) {
    vector<int> res;

    stack<TreeNode*> s;
    TreeNode *p = root;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            res.push_back(p->val);
            p = p->left;
        } else {
            p = s.top(); s.pop();
            p = p->right;
        }
    }

    return res;
}

vector<int> TreeTraversal::preorderTraversalMorris(TreeNode* root) {
    vector<int> res;
    if (!root)
        return res;

    TreeNode *cur = root, *pre = nullptr;
    while (cur)
        if (!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
        } else {
            pre = cur->left;
            while (pre->right && pre->right != cur)
                pre = pre->right;

            if (!pre->right) {
                pre->right = cur;
                res.push_back(cur->val);
                cur = cur->left;
            } else {
                pre->right = nullptr;
                cur = cur->right;
            }
        }

    return res;
}

// 94. Binary Tree Inorder Traversal
vector<int> TreeTraversal::inorderTraversal(TreeNode* root) {
    vector<int> res;

    stack<TreeNode*> s;
    TreeNode* p = root;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top(); s.pop();
            res.push_back(p->val);
            p = p->right;
        }
    }

    return res;
}

vector<int> TreeTraversal::inorderTraversalMorris(TreeNode* root) {
    vector<int> res;
    if (!root)
        return res;

    TreeNode *cur = root, *pre = nullptr;
    while (cur)
        if (!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
        } else {
            pre = cur->left;
            while (pre->right && pre->right != cur)
                pre = pre->right;

            if (!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                res.push_back(cur->val);
                cur = cur->right;
            }
        }

    return res;
}

// 145. Binary Tree Postorder Traversal
vector<int> TreeTraversal::postorderTraversal(TreeNode* root) {
    vector<int> res;

    stack<TreeNode*> s;
    TreeNode *p = root, *pre = nullptr;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            if (p->right && pre != p->right)
                p = p->right;
            else {
                s.pop();
                res.push_back(p->val);
                pre = p;
                p = nullptr;
            }
        }
    }

    return res;
}

vector<int> TreeTraversal::postorderTraversal2(TreeNode* root) {
    vector<int> res;

    stack<TreeNode*> s;
    TreeNode* p = root;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            res.insert(res.begin(), p->val);
            p = p->right;
        } else {
            p = s.top(); s.pop();
            p = p->left;
        }
    }

    return res;
}
