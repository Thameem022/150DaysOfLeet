#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Tree 
{
public:
    int val;
    Tree* left;
    Tree* right;
    Tree(int value): val(value), left(nullptr), right(nullptr) {}
    Tree(int value, Tree* l): val(value), left(l), right(nullptr) {}
    Tree(int value, Tree* l, Tree* r): val(value), left(l), right(r) {}
};

class Solution
{
public:
    
    vector<int> travserseTree(Tree* root)
    {
        stack<Tree*> s;
        s.push(root);
        vector<int> res;
        while(!s.empty())
        {
            Tree* node = s.top();
            s.pop();

            res.push_back(node->val);

            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }

        return res;
    }

    vector<int> recursiveTraverse(Tree* root)
    {
        
        if(!root) return vector<int>();
        vector<int> res;
        res.push_back(root->val);
        vector<int> leftArray = recursiveTraverse(root->left);
        vector<int> rightArray = recursiveTraverse(root->right);

        res.insert(res.end(), leftArray.begin(), leftArray.end());
        res.insert(res.end(), rightArray.begin(), rightArray.end());
        return res;
    }

    vector<Tree*> bfsTraversal(Tree* root)
    {
        if(!root) return vector<Tree*>();

        queue<Tree*> treeQueue;
        treeQueue.push(root);

        vector<Tree*> res;

        while(!treeQueue.empty())
        {
            int size = treeQueue.size();
            for(int i=0; i<size; i++)
            {
                Tree* node = treeQueue.front();
                treeQueue.pop();
                if(node->left) treeQueue.push(node->left);
                if(node->right) treeQueue.push(node->right);
                
                res.push_back(node);
            }
        }
        return res;
    }
    bool isNode(Tree* root, Tree* target)
    {
        queue<Tree*> nodeQueue;
        nodeQueue.push(root);

        while(!nodeQueue.empty())
        {
            Tree* node = nodeQueue.front();
            nodeQueue.pop();

            if(node == target) return true;

            if(node->right) nodeQueue.push(node->right);
            if(node->left) nodeQueue.push(node->left);
        }
        return false;
    }
};

int main()
    {
        Tree* a = new Tree(1);
        Tree* b = new Tree(2);
        Tree* c = new Tree(3);
        Tree* d = new Tree(4);
        Tree* e = new Tree(5);
        Tree* f = new Tree(6);
        Tree* x = new Tree(6);
        a->left = b;
        a->right = e;
        e->right = f;
        b->left = c;
        b->right = d;

        Solution sol;
        // vector<int> res = sol.recursiveTraverse(a);
        // for(int a : res)
        // {
        //     cout<<a<<endl;
        // }
        // vector<Tree*> bfsRes = sol.bfsTraversal(a);
        // for(Tree* a: bfsRes)
        // {
        //     cout<<a->val<<endl;
        // }

        cout<<sol.isNode(a,x);
        return 0;
    }