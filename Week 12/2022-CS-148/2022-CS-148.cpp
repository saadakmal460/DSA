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
        //Simple BST insertion
        if (root == nullptr)
        {
            return new Node(val);
        }

        if (val < root->val)
        {
            root->left = Insert(root->left, val); 
        }
        else if (val > root->val)
        {
            root->right = Insert(root->right, val); 
        }

        //Updating height
        root->height = 1 + max(Height(root->left), Height(root->right));

        int balance = HeightDifference(root);


        //Maintaining balance
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

    // Part 6
    Node *DeleteNode(Node* root, int val)
    {

        //Simple BST deletion
        if (root == nullptr)
        {
            return root;
        }

        if (val < root->val)
        {
            root->left = DeleteNode(root->left, val);
        }

        else if (val > root->val)
        {
            root->right = DeleteNode(root->right, val);
        }

        else
        {
            //Node with one child or no child
            if (root->left == nullptr || root->right == nullptr)
            {
                Node *temp;
                if (root->left != nullptr)
                {
                    temp = root->left;
                }
                else
                {
                    temp = root->right;
                }

                if (temp == nullptr) // No child
                {
                    temp = root;
                    root = nullptr;
                }
                else //if one child
                {
                    root = temp;
                    temp = nullptr;
                }
            }

            else
            {
                //Node with two childern
                Node *temp = minNode(root->right);
                root->val = temp->val;
                root->right = DeleteNode(root->right, temp->val);
            }
        }

        if (root == nullptr)
        {
            return root;
        }

        root->height = 1 + max(Height(root->left), Height(root->right));

        int balance = HeightDifference(root);
        
        //Left-Left case
        if (balance > 1 && HeightDifference(root->left) >= 0) 
        {
            return RotateRight(root); 
        }

        //Left Right case
        if (balance > 1 && HeightDifference(root->left) < 0)
        {
            root->left = RotateLeft(root->left);
            return RotateRight(root);
        }

        // Right Right Case
        if (balance < -1 &&HeightDifference(root->right) <= 0)
        {
            return RotateLeft(root);
        }
        // Right Left Case
        if (balance < -1 && HeightDifference(root->right) > 0)
        {
            root->right = RotateRight(root->right);
            return RotateLeft(root);
        }

        return root;
    }

    //Leetcode Problem 2
    bool isBalanced(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return true;
        }
        int balance = HeightDifference(root);
        if (balance > 1 || balance < -1)
        {
            return false;
        }
        if (!isBalanced(root->left) || !isBalanced(root->right))
        {
            return false;
        }
        return true;

    }

    int HeightDifference(TreeNode* n)
    {
        if (n == nullptr)
        {
            return 0;
        }

        return Height(n->left) - Height(n->right);
    }

    int Height(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        return 1 + max(Height(root->left), Height(root->right));
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

    Node *minNode(Node *root)
    {
        Node *curr = root;
        while (curr->left)
        {
            curr = curr->left;
        }

        return curr;
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
    AVL<int> t;

    t.root = t.Insert(t.root, 10);
    t.root = t.Insert(t.root, 20);
    t.root = t.Insert(t.root, 30);
    t.root = t.Insert(t.root, 75);
    t.root = t.Insert(t.root, 85);
    t.root = t.Insert(t.root, 95);
    t.root = t.Insert(t.root, 15);

    cout << t.isBalanced(t.root)<<endl;

    t.PrintTreeByRow(t.root);

    t.root = t.DeleteNode(t.root, 30);

    cout << t.isBalanced(t.root) << endl;

    cout << endl;

    t.PrintTreeByRow(t.root);

    return 0;
}
