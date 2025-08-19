#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    char Color;
    Node *left, *right;
    Node() : Color('\0'), left(nullptr), right(nullptr) {};
    Node(char letter) : Color(letter), left(nullptr), right(nullptr) {};
};

// Function to generate a binary tree from a level ordered vector
Node* levelOrderedTreeGenerator(vector<char> &order) {
    if(order.empty()) return nullptr;

    Node* root = new Node(order[0]);
    queue<Node*> q; q.push(root);
    
    int i = 1;
    while(i < order.size()) {
        Node* curr = q.front(); q.pop();
        
        if(i < order.size()) {
            if(order[i] != '\0') {
                curr->left = new Node(order[i]);
                q.push(curr->left);
            }
            i++;
        }
        
        if(i < order.size()) {
            if(order[i] != '\0') {
                curr->right = new Node(order[i]);
                q.push(curr->right);
            }
            i++;
        }
    }

    return root;
}

// Function to perform level order traversal and store nodes in a vector
vector<Node*> levelOrderTraversal(Node* root) {
    vector<Node*> res;
    if(!root) return res;
    
    queue<Node*> q; q.push(root);
    res.push_back(root);

    while(!q.empty()) {
        Node* curr = q.front(); q.pop();
        if(curr->left) {
            q.push(curr->left);
            res.push_back(curr->left);
        }
        if(curr->right) {
            q.push(curr->right);
            res.push_back(curr->right);
        }
    }
    return res;
}

// Solution class for coloring a blankTree
class Solution {
private:
    Node* blankTree;

public:
    // Initialize all nodes of level order vector to green G
    Solution(vector<char> levelOrder) {
        for(int i = 0; i < levelOrder.size(); i++) {
            if(levelOrder[i] != '\0') levelOrder[i] = 'G';
        }
        blankTree = levelOrderedTreeGenerator(levelOrder);
    };

    // Function to invert a Blue Color to Green & Vice-Versa
    char invert(char color) {
        if(color == 'B') return 'R';
        else if(color == 'R') return 'B';
    }

    // Depth First Search to Color the left Boundary of blankTree excluding the Leaf Node
    // parentColor is used to color alternatively R & B
    // lastColor is used to track last Colored Node which will be later used to continue other DFS
    char leftsideDFS(Node *root, char &parentColor) {
        if(!root) return '\0';

        char lastColor = parentColor;
        if(root->left) {
            root->Color = invert(parentColor);
            lastColor = leftsideDFS(root->left, root->Color);
        } else if(root->right) {
            root->Color = invert(parentColor);
            lastColor = leftsideDFS(root->right, root->Color);
        }
        return lastColor;
    }

    // Depth First Search to Color the Leaf Nodes of blankTree excluding the Leaf Node 
    // currColor is used to color alternatively R & B
    // lastColor is used to keep track color of the last Leaf Node
    char bottomsideDFS(Node *root, char &currColor) {
        if(!root) return currColor;
        
        char lastColor = bottomsideDFS(root->left, currColor);
        if(!root->left && !root->right) {
            root->Color = invert(currColor);
            currColor = root->Color;
        }
        lastColor = bottomsideDFS(root->right, currColor);
        return lastColor;
    }

    // Depth First Search to Color the right Boundary of blankTree excluding the Leaf Node
    // childColor is used to color alternatively R & B while Backtracking.
    // lastColor is used to keep track color of the last Leaf Node (Its Redundant but Just For consistency of code)
    char rightsideDFS(Node *root, char &childColor) {
        if(!root) return '\0';

        char lastColor = childColor;
        if(root->right) {
            lastColor = rightsideDFS(root->right, childColor);
            root->Color = invert(lastColor);
            lastColor = root->Color;
        } else if(root->left) {
            lastColor = rightsideDFS(root->left, childColor);
            root->Color = invert(lastColor);
            lastColor = root->Color;
        }
        return lastColor;
    }

    // Function Implementation to color the tree.
    void TreeColor(Node* tree) {
        if(!tree) return;
        
        // Initializing the root Color to Blue
        char rootColor = 'B';
        tree->Color = rootColor;
        
        // Coloring left boundary
        char lastColorOfLeftBoundary = (tree->left) ? leftsideDFS(tree->left, rootColor) : rootColor;
        
        // Coloring leaf nodes
        char lastColorOfLeftSubTree = (tree->left) ? bottomsideDFS(tree->left, lastColorOfLeftBoundary) : rootColor;
        char lastColorOfRightSubTree = (tree->right) ? bottomsideDFS(tree->right, lastColorOfLeftSubTree) : rootColor;
        
        //Coloring right boundary
        char lastColorOfRightBoundary = (tree->right) ? rightsideDFS(tree->right, lastColorOfRightSubTree) : rootColor;
    }

    // Printing the tree in level ordered manner
    void printColoredTree() {
        TreeColor(blankTree);
        vector<Node*> ans = levelOrderTraversal(blankTree);
        for(auto &each : ans) cout<<each->Color<<" ";
        cout << '\n';
    }
};

int main() {

    // Level ordered tree test cases
    // 'N' is to represent Initialy Non-Colored Nodes. 
    vector<char> test0 = {};
    vector<char> test1 = {'N'};
    vector<char> test2 = {'N', 'N', '\0', '\0', 'N', 'N'};
    vector<char> test3 = {'N', 'N', 'N', 'N', '\0', 'N', 'N'};
    vector<char> test4 = {'N', 'N', 'N', 'N', '\0', '\0', 'N'};
    vector<char> test5 = {'N', 'N', 'N', 'N', 'N', 'N', 'N', '\0', 'N', '\0', 'N', '\0', '\0', 'N', 'N'};
    vector<char> test6 = {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N'};
    vector<char> test7 = {'N', 'N', '\0', 'N', '\0', 'N', '\0'};
    vector<char> test8 = {'N', '\0', 'N'};
    vector<char> test9 = {'N', '\0', 'N', '\0', 'N'};
    vector<char> test10 = {'N', '\0', 'N', 'N', 'N'};

    vector<vector<char>> testCases = {test0, test1, test2, test3, test4, test5, test6, test7, test8, test9, test10};

    // Print colored trees in level order 
    for(vector<char> Case : testCases) {
        Solution obj(Case);
        obj.printColoredTree();
    }
    
    return 0;
}