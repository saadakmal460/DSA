#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
template <typename T>
class AVL
{
    // Part 1
    class Node
    {
    public:
        Node *left;
        Node *right;
        int val;
        int height;

        Node(T val)
        {
            this->val = val;
            left = nullptr;
            right = nullptr;
        }
    };

public:
    Node *root;
    AVL()
    {
        root = nullptr;
    }

    // Part 2
    int Height(Node *n)
    {
        if (n == nullptr)
        {
            return 0;
        }

        return n->height;
    }

    // Part 3
    int HeightDifference(Node *n)
    {
        if (n == nullptr)
        {
            return 0;
        }

        return Height(n->left) - Height(n->right);
    }

    // Part 4
    bool isBalanced(Node *n)
    {
        return HeightDifference(n) <= 1 && HeightDifference(n) >= -1;
    }

    // Part 5
    Node *Insert(Node *root, int val)
    {
        if (root == nullptr)
        {
            return new Node(val);
        }

        if (val < root->val)
        {
            root->left = Insert(root->left, val); // Fix: Added assignment to left child
        }
        else if (val > root->val)
        {
            root->right = Insert(root->right, val); // Fix: Added assignment to right child
        }

        root->height = 1 + max(Height(root->left), Height(root->right));

        int balance = HeightDifference(root);

        if (balance > 1 && val < root->left->val)
        {
            return RotateRight(root);
        }

        if (balance < -1 && val > root->right->val)
        {
            return RotateLeft(root);
        }

        if (balance > 1 && val > root->left->val)
        {
            root->left = RotateLeft(root->left);
            return RotateRight(root);
        }

        if (balance < -1 && val < root->right->val)
        {
            root->right = RotateRight(root->right);
            return RotateLeft(root);
        }

        return root;
    }

    Node *RotateRight(Node *b)
    {
        Node *a = b->left;
        Node *temp = b->right;

        a->right = b;
        b->left = temp;

        b->height = 1 + max(Height(b->left), Height(b->right));
        a->height = 1 + max(Height(a->left), Height(a->right));

        return a;
    }

    Node *RotateLeft(Node *a)
    {
        Node *b = a->right;
        Node *temp = a->left;

        b->left = a;
        a->right = temp;

        a->height = 1 + max(Height(a->left), Height(a->right));
        b->height = 1 + max(Height(b->left), Height(b->right));

        return b;
    }

    void PrintTreeByRow(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty())
        {
            Node *temp = q.front();

            q.pop();

            if (temp == nullptr)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(nullptr);
                }
            }
            else
            {
                cout << temp->val << " ";
                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }
};

int main()
{
    AVL<int> avlTree;

    avlTree.root = avlTree.Insert(avlTree.root, 10);
    avlTree.root = avlTree.Insert(avlTree.root, 20);
    avlTree.root = avlTree.Insert(avlTree.root, 30);
    avlTree.root = avlTree.Insert(avlTree.root, 75);
    avlTree.root = avlTree.Insert(avlTree.root, 85);
    avlTree.root = avlTree.Insert(avlTree.root, 95);
    avlTree.root = avlTree.Insert(avlTree.root, 15);




    avlTree.PrintTreeByRow(avlTree.root);

    return 0;
}
