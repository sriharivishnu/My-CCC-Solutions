// Solution by Srihari Vishnu

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<std::pair<int, int>> vii;

int ta[2501], tb[2501];

int growth;

struct Node {
    int val = 0;
    Node *left = nullptr, *right = nullptr;
    int best[2501] = {0};

    ~Node() {
        delete left, delete right;
        left = right = nullptr;
    }
};

void solve(Node* root) {
    // leaf node
    if (!root->left) {
        for (int i = 0; i <= growth; ++i) {
            root->best[i] = root->val + i;
        }
        return;
    }

    // internal node
    solve(root->left);
    solve(root->right);

    for (int i = 0; i <= growth; ++i) {
        ta[i] = 0;
        for (int j = 0; j <= i; ++j) {
            ta[i] = std::max(
                ta[i], std::min((1 + j) * (1 + j), root->left->best[i - j]));
        }
    }

    for (int i = 0; i <= growth; ++i) {
        tb[i] = 0;
        for (int j = 0; j <= i; ++j) {
            tb[i] = std::max(
                tb[i], std::min((1 + j) * (1 + j), root->right->best[i - j]));
        }
    }

    for (int i = 0; i <= growth; ++i) {
        for (int j = 0; j <= i; ++j) {
            root->best[i] = std::max(root->best[i], ta[j] + tb[i - j]);
        }
    }
}

Node* parse(string& s, int& i) {
    const auto skipWs = [&]() {
        while (i < s.size() && s[i] == ' ') {
            ++i;
        }
    };

    skipWs();
    if (i >= s.size()) return nullptr;
    Node* node = new Node{};
    if (s[i] == '(') {
        ++i;
        skipWs();
        node->left = parse(s, i);
        skipWs();
        node->right = parse(s, i);
        skipWs();
        ++i;
    } else {
        int val = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            val = val * 10 + (s[i++] - '0');
        }
        node->val = val;
    }
    return node;
}

int main() {
    std::string s;
    getline(std::cin, s);
    int i = 0;
    Node* root = parse(s, i);
    cin >> growth;
    solve(root);
    cout << root->best[growth] << endl;
    delete root;
}
