#include <iostream>
using namespace std;

// 树节点结构体
struct TreeNode {
    double val = 0.0;
    TreeNode* Left = nullptr;
    TreeNode* Right = nullptr;
  
    // 构造函数
    TreeNode(double x) : val(x), Left(nullptr), Right(nullptr) {}
};

// 二叉搜索树类
class BinarySearchTree {
private:
    TreeNode* root = nullptr;

    // 递归插入辅助函数
    TreeNode* insertHelper(TreeNode* node, double val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
  
        if (val < node->val) {
            node->Left = insertHelper(node->Left, val);
        } else {
            node->Right = insertHelper(node->Right, val);
        }
  
        return node;
    }

    // 递归中序遍历辅助函数
    void inorderHelper(TreeNode* node) {
        if (node == nullptr) return;
  
        inorderHelper(node->Left);
        cout << node->val << " ";
        inorderHelper(node->Right);
    }

    // 递归查找辅助函数
    bool searchHelper(TreeNode* node, double val) {
        if (node == nullptr) return false;
  
        if (val == node->val) return true;
        if (val < node->val) return searchHelper(node->Left, val);
        return searchHelper(node->Right, val);
    }

    // 递归删除树辅助函数
    void clearHelper(TreeNode* node) {
        if (node == nullptr) return;
        clearHelper(node->Left);
        clearHelper(node->Right);
        delete node;
    }

public:
    ~BinarySearchTree() {
        clear();
    }

    // 插入节点
    void insert(double val) {
        root = insertHelper(root, val);
    }

    // 中序遍历
    void inorderTraversal() {
        inorderHelper(root);
        cout << endl;
    }

    // 查找值
    bool search(double val) {
        return searchHelper(root, val);
    }

    // 清空树
    void clear() {
        clearHelper(root);
        root = nullptr;
    }
};

// 验证代码
int main() {
    BinarySearchTree bst;
  
    // 插入节点
    bst.insert(5.0);
    bst.insert(3.0);
    bst.insert(7.0);
    bst.insert(2.0);
    bst.insert(4.0);
    bst.insert(6.0);
    bst.insert(8.0);
    bst.insert(5.5); // 测试相同值
  
    // 中序遍历 (应该输出有序序列)
    cout << "Inorder traversal: ";
    bst.inorderTraversal(); // 预期输出: 2 3 4 5 5.5 6 7 8
  
    // 查找测试
    cout << "Search 4.0: " << (bst.search(4.0) ? "Found" : "Not found") << endl; // 应找到
    cout << "Search 5.5: " << (bst.search(5.5) ? "Found" : "Not found") << endl; // 应找到
    cout << "Search 1.0: " << (bst.search(1.0) ? "Found" : "Not found") << endl; // 不应找到
  
    return 0;
}