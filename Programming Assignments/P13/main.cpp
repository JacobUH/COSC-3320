// f6ba1ac3-4678-4fa3-b853-4b1a5bab1603

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct node{
    int val;
    int index;
    node *left;
    node *right;
};

class binaryTree{
    private:
        node *head;
        int size;
    public:
        binaryTree(){
            head = nullptr;
            size = 0;
        }

        node *createNode(int val, int index){
            node *newNode = new node;
            newNode->val = val;
            newNode->index = index;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        void insert(vector <int> nums){
            for (int i = 0; i < nums.size(); i++){
                // if binaryTree empty
                if (head == nullptr){
                    head = createNode(nums[i], i);
                }
                else{
                    node *current = head;
                    while(true){
                        if (nums[i] < current->val){
                            if (current->left == nullptr){
                                current->left = createNode(nums[i], i);
                                break;
                            }
                            else{
                                current = current->left;
                            }
                        }
                        else{
                            if (current->right == nullptr){
                                current->right = createNode(nums[i], i);
                                break;
                            }
                            else{
                                current = current->right;
                            }
                        }
                    }
                }
            }
        }

        int findDistance(node *root, int n){
            int dist = 0;
            while (root != nullptr){
                if (n == root->val){
                    return dist;
                }
                else if (n < root->val){
                    dist++;
                    root = root->left;
                }
                else{
                    dist++;
                    root = root->right;
                }
            }
        }

        int bstDistance(vector <int> nums, int n1, int n2){
            insert(nums);

            node *current = head;
            int distance = 0;

            while (current != nullptr){
                // if both nodes are on opposite sides of the current node (common ancestor)
                if ((n1 <= current->val && n2 >= current->val) || (n2 <= current->val && n1 >= current->val)){
                    int distance1 = findDistance(current, n1);
                    int distance2 = findDistance(current, n2);
                    if (distance1 != -1 && distance2 != -1){
                        distance = distance1 + distance2;
                        break;
                    }
                }

                // else if both nodes are on the left of the current node
                else if (n1 < current->val && n2 < current->val){
                    current = current->left;
                }

                // else (both nodes are on the right of the current node)
                else{
                    current = current->right;
                }
            }
            return distance;
        }
};


int main(){
    string in;
    vector <int> nums;

    getline(cin, in);
    istringstream iss(in);
    int num;
    while (iss >> num)
      nums.push_back(num);
        
    int node1, node2;
    cin >> node1 >> node2;

    binaryTree bt;
    cout << bt.bstDistance(nums, node1, node2);
}