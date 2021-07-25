//
// Created by xuhuipeng on 2021/6/9.
//

#include <vector>
#include "math.h"
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class SolutionTwoSum {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> m;
        for (auto i = 0; i != nums.size(); ++i) {
            auto it = m.find(target - nums[i]);
            if (it != m.end()) {
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};


class SolutionIsPalindrome {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        string nums = to_string(x);
        auto beg = nums.begin();
        auto end = nums.end();
        while (beg < end) {
            if (*beg == *end) {
                ++beg;
                --end;
            } else {
                return false;
            }
        }
        return true;
    }
};


class SolutionIsPalindrome2 {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        int beg = -1;
        int x1 = x;
        while (x1 > 0) {
            x1 /= 10;
            ++beg;
        }
        int end = 1;
        int x2 = x;
        while (beg >= end) {
            int s = x / pow(10, beg);
            x = fmod(x, pow(10, beg));
            --beg;
            int e = fmod(x2, 10);
            x2 /= 10;
            ++end;

            if (s != e) return false;
        }
        return true;
    }
};

class SolutionIsValid {
private:
    unordered_map<char, char> symbols_map = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
    };
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        vector<char> symbols;
        for (char sym: s) {
            auto is_left = symbols_map.find(sym);
            if (is_left == symbols_map.end()) {
                if (!symbols.size()) {
                    return false;
                }
                char frontier = symbols.back();
                symbols.pop_back();
                if (symbols_map[frontier] != sym) {
                    return false;
                }
            } else {
                symbols.push_back(sym);
            }
        }
        return !symbols.size();
    }
};


class SolutionIsValid2 {
private:
    unordered_map<char, char> symbols_map = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
    };
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        stack<char> symbols;
        for (char sym: s) {
            if (!symbols_map.count(sym)) {
                if (symbols.empty() || symbols_map[symbols.top()] != sym) {
                    return false;
                }
                symbols.pop();
            } else {
                symbols.push(sym);
            }
        }
        return symbols.empty();
    }
};


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class mergeTwoListsSolution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        ListNode head;
        ListNode *head_ptr = &head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                head_ptr->next = l1;
                l1 = l1->next;
            } else {
                head_ptr->next = l2;
                l2 = l2->next;
            }
            head_ptr = head_ptr->next;
        }
        ListNode *tail = l1 ? l1 : l2;
        head_ptr->next = tail;
        return head.next;
    }
};


class mergeTwoListsSolution2 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

class removeDuplicatesSolution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int i = 1;
        for (int j = 1; j != nums.size(); ++j) {
            if (nums[j] != nums[i - 1]) {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};


class removeElementSolution {
public:
    int removeElement(vector<int> &nums, int val) {
        int i = 0, j = nums.size() - 1;
        while (j >= i) {
            if (nums[i] == val) {
                nums[i] = nums[j--];
            } else {
                ++i;
            }
        }
        return i;
    }
};

class mySqrtSolution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        while (high - low > 1) {
            int med = ((high - low) >> 1) + low;
            if (pow(med, 2) > x) {
                high = med;
            } else if (pow(med, 2) < x) {
                low = med;
            } else {
                return med;
            }
        }
        return low;
    }
};


class climbStairsSolution {
private:
    unordered_map<int, int> solution_map;
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int s1 = solution_map.count(n - 2) ? solution_map[n - 2] : climbStairs(n - 2);
        int s2 = solution_map.count(n - 1) ? solution_map[n - 1] : climbStairs(n - 1);
        solution_map[n - 2] = s1;
        solution_map[n - 1] = s2;

        return s1 + s2;
    }
};

class mergeSolution {
public:
    void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int p = m + n - 1;
        int i = m - 1, j = n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] >= nums2[j]) {
                nums1[p--] = nums1[i--];
            } else {
                nums1[p--] = nums2[j--];
            }
        }
        return;
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = n + m - 1, j = m - 1;
        while (i >= n) {
            nums1[i--] = nums1[j--];
        }
        i = n;
        j = 0;
        int p = 0;
        while (i < m + n && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums1[p++] = nums1[i++];
            } else {
                nums1[p++] = nums2[j++];
            }
        }
        while (j < n) {
            nums1[p++] = nums2[j++];
        }
        return;
    }
};


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class inorderSolution {
public:
    void inorder(TreeNode *root, vector<int> &ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

class isSameTreeSolution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) {
            return false;
        }
        if (p == nullptr && q == nullptr) {
            return true;
        }
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

class isSymmetricSolution {
public:
    bool symmetric(TreeNode* left, TreeNode* right) {
        if ((left == nullptr) ^ (right == nullptr)) {
            return false;
        }
        if ((left == nullptr) && (right == nullptr)) {
            return true;
        }
        if (left->val == right->val) {
            return symmetric(left->left, right->right) && symmetric(left->right, right->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return symmetric(root, root);
    }
};

class sortedArrayToBSTSolution {
public:
    TreeNode* buildBST(vector<int>& nums, size_t start, size_t end) {
        if (end - start < 1) {
            return nullptr;
        }
        size_t mid = (end - start) / 2 + start;
        auto* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, start, mid);
        root->right = buildBST(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return buildBST(nums, 0, nums.size());
    }
};


class minDepthSolution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t len = q.size();
            ++ans;
            while (len > 0) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left == nullptr && cur->right == nullptr) {
                    return ans;
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                --len;
            }
        }
        return ans;
    }
};


class hasPathSumSolution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, root->val);
        while (!q.empty()) {
            TreeNode* curNode = q.front().first;
            int curSum = q.front().second;
            q.pop();
            if (curNode->left == nullptr && curNode->right == nullptr && curSum == targetSum) {
                return true;
            }
            if (curNode->left != nullptr) {
                q.emplace(curNode->left, curSum + curNode->left->val);
            }
            if (curNode->right != nullptr) {
                q.emplace(curNode->right, curSum + curNode->right->val);
            }
        }
        return false;
    }
};

class maxProfitSolution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size, {0, 0});
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i=1; i != size; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[size-1][0];
    }
};

class preorderTraversalSolution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> nums;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* cur = nodes.top();
            nodes.pop();
            nums.push_back(cur->val);
            if (cur->right != nullptr) nodes.push(cur->right);
            if (cur->left != nullptr) nodes.push(cur->left);
        }
        return nums;
    }
};

class preorderTraversalSolution1 {
public:
    void recursivePreorder(TreeNode* root, vector<int> &nums) {
        if (root == nullptr) {
            return;
        }
        nums.push_back(root->val);
        recursivePreorder(root->left, nums);
        recursivePreorder(root->right, nums);
   }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums;
        recursivePreorder(root, nums);
        return nums;
    }
};


class postorderTraversalSolution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        stack<TreeNode*> nodes;
        TreeNode* prev = nullptr;
        vector<int> nums;
        while (root != nullptr || !nodes.empty()) {
            while (root != nullptr) {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            if (root->right == nullptr || root->right == prev) {
                nums.push_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                nodes.push(root);
                root = root->right;
            }
        }
        return nums;
    }
};

class majorityElementSolution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int &num: nums) {
            if (counter.find(num) == counter.end()) {
                counter[num] = 1;
            } else {
                ++counter[num];
            }
        }
        vector<int>::size_type th = nums.size() / 2;
        for (auto &v: counter) {
            if (v.second > th) {
                return v.first;
            }
        }
        return -1;
    }
};

class majorityElementSolution1 {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, counter = 0;
        for (auto &num: nums) {
            if (counter == 0) {
                ans = num;
                ++counter;
            } else if (num == ans) {
                ++counter;
            } else {
                --counter;
            }
        }
        return ans;
    }
};


class isHappySolution {
public:
    int squareSum(int n) {
        int ans = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            ans += pow(digit, 2);
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_map<int, int> counter;
        while (n != 1) {
            n = squareSum(n);
            if (counter.find(n) != counter.end()) {
                return false;
            }
            counter[n] += 1;
        }
        return true;
    }
};


class reverseListSolution1 {
public:
    ListNode* recurReverse(ListNode* head, ListNode* dummy) {
        if (head->next == nullptr) {
            dummy->next = head;
        } else {
            ListNode* next = recurReverse(head->next, dummy);
            next->next = head;
        }
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode();
        recurReverse(head, dummy);
        head->next = nullptr;
        return dummy->next;
    }
};

class reverseListSolution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};


class MyStack {
private:
    queue<int> q1;

public:
    /** Initialize your data structure here. */
    MyStack() = default;

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (q1.size() > 1) {
            int num = q1.front();
            q1.pop();
            q1.push(num);
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    /** Get the top element. */
    int top() {
        return q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};


class invertTreeSolution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        swap(root->left, root->right);
        invertTree(root->right);
        invertTree(root->left);
        return root;
    }
};