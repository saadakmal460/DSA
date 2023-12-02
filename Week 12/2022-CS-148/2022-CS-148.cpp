#include <iostream>


template<typename T>
class AVL
{
    //Part 1
    class Node
    {
    public:

        Node* left;
        Node* right;
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

    Node* root;
    AVL()
    {
        root = nullptr;
    }

    //Part 2
    int Height(Node* n)
    {
        if (n == nullptr)
        {
            return 0;
        }

        return n->height;
    }


    //Part 3
    int HeightDifference(Node* n)
    {
        if (n == nullptr)
        {
            return 0;
        }

        return Height(n->left) - Height(n->right);
    }



    //Part 4
    bool isBalanced(Node* n)
    {
        return HeightDifference(n) <= 1 && HeightDifference(n)>=-1;
    }




};


int main()
{
    std::cout << "Hello World!\n";
}
