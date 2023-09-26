#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

class binaryTree {
private:
    node* head;
    int size;

public:
    binaryTree() {
        head = nullptr;
        size = 0;
    }

    node* createNode(int val) {
        node* newNode = new node;
        newNode->val = val;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void insert(vector<int> nums) {
        
    }

    void postorder(node* root) {
        if (root == nullptr)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }

    void intialize(vector<int> nums) {
        insert(nums);
        postorder(head);
    }
};

int main() {
    int size;
    vector<int> nums;

    cin >> size;
    cin.ignore();

    string input;
    getline(cin, input);
    stringstream iss(input);

    int num;
    while (iss >> num)
        nums.push_back(num);

    binaryTree bt;
    bt.intialize(nums);

    return 0;
}