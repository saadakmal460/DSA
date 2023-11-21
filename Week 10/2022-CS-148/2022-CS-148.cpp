#include <iostream>
#include<vector>
#include<queue>


template<typename T>
//Question 1
class BST
{
	//Part a
	class Node
	{
	public:
		T data;
		Node* left;
		Node* Right;

		Node(T data)
		{
			this->data = data;
			left = nullptr;
			right = nullptr;
		}
	};

	//Part 1(b)
	class RandomizedBinaryTree
	{
	public:
		Node* root;
		RandomizedBinaryTree()
		{
			root = nullptr;
		}

		void Insert(Node* current, T data)
		{
			if (current == nullptr)
			{
				current = new Node(data);
				return;
			}

			if (rand() % 2 == 0)
			{
				current->left = Insert(current->left, data);
			}
			else
			{
				current->right = Insert(current->right, data);
			}
		}
	};

	Node* root;
public:
	BST()
	{
		root = nullptr;
	}

	//Part b
	void InsertInBST(Node* current, T data)
	{
		if (current == nullptr)
		{
			current = new Node(data);
			return;
		}
		if (data < current->data)
		{
			current->left = InsertInBST(current->left, data);
		}
		if (data > current->data)
		{
			current->right = InsertInBST(current->right, data);
		}
	}

	//Part c
	Node* SearchBST(Node* current, T val)
	{
		if (current == nullptr)
		{
			return nullptr;
		}
		if (current->data == val)
		{
			return current;
		}
		if (val > current->data)
		{
			return SearchBST(current->right, val);
		}
		else
		{
			return SearchBST(current->left, val);
		}

	}

	//Part d
	void RecursivePrinting(Node* current)
	{
		if (current == nullptr)
		{
			return;
		}

		RecursivePrinting(root->left);
		cout << current->data << " ";
		RecursivePrinting(root->right);
	}

	//Part e
	Node* Start(Node* root)
	{
		if (root->left == nullptr)
		{
			return root;
		}
		Start(root->left);
	}

	//Part f
	Node* End(Node* root)
	{
		if (root->right == nullptr)
		{
			return root;
		}
		Start(root->right);
	}

	//Question 2
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == nullptr)
		{
			root = new TreeNode(val);
		}
		if (val < root->val)
		{
			root->left = insertIntoBST(root->left, val);
		}
		if (val > root->val)
		{
			root->right = insertIntoBST(root->right, val);
		}
		return root;
	}


	//Qustion 3
	bool IdenticelTrees(Node* tree1, Node* tree2)
	{
		if (tree1 == nullptr && tree2 == nullptr)
		{
			return tree1 == tree2;
		}
		return (tree1->data == tree2->data) && IdenticelTrees(tree1->left && tree2->left) && IdenticelTrees(tree1->right && tree2->right)
	}

	//Question 4

	//Part a
	void InOrder(TreeNode* current, vector<int>& res)
	{

		if (current == nullptr)
		{
			return;
		}

		InOrder(current->left, res);
		res.push_back(current->val);
		InOrder(current->right, res);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>res;
		InOrder(root, res);
		return res;
	}

	//Part b
	void postOrder(TreeNode* root, vector<int>& res)
	{
		if (root == NULL)
		{
			return;
		}


		postOrder(root->left, res);
		postOrder(root->right, res);
		res.push_back(root->val);

	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int>res;
		postOrder(root, res);
		return res;
	}


	//Part c
	void preOrder(TreeNode* root, vector<int>& res)
	{
		if (root == NULL)
		{
			return;
		}

		res.push_back(root->val);
		preOrder(root->left, res);
		preOrder(root->right, res);



	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int>res;
		preOrder(root, res);
		return res;
	}


	//Question 5
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)
		{
			return res;
		}
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			int count = q.size();
			vector<int> curr;

			for (int i = 0; i < count; i++)
			{
				TreeNode* current = q.front();
				q.pop();
				curr.push_back(current->val);

				if (current->left != NULL)
				{
					q.push(current->left);
				}
				if (current->right != NULL)
				{
					q.push(current->right);
				}

			}
			res.push_back(curr);

		}

		return res;

	}

	//Question 6
	int EvenCounts(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return (root->data % 2 == 0) + IdenticelTrees(root->left) + IdenticelTrees(root->right)
	}


	//Question 7
	int TreeHeight(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int left = TreeHeight(root->left);
		int right = TreeHeight(root->Right);

		return 1 + max(left, right);
	}

	//Question 8
	bool IsBST(Node* root)
	{
		return CheckBST(root, INT16_MIN, INT16_MAX);
	}

	bool CheckBST(Node* root, int min, int max)
	{
		if (root == nullptr)
		{
			return true;
		}
		if (root->data >= max || root->data <= min)
		{
			return false;
		}
		return CheckBST(root->left , min , root->data) && CheckBST(root->right, min, root->data)
	}



	//Question 9
	void Sort(int arraySize, int arr[])
	{
		for (int i = 0; i < arraySize; i++)
		{
			InsertInBST(a[i]);
		}

		inorderTraversal(newNode);

	}

	//Question 10
	int BranchCount(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		if ((root->left == nullptr && root->right != nullptr) || ((root->left != nullptr && root->right == nullptr)))
		{
			return 1 + BranchCount(root->left) + BranchCount(root->right);
		}

		return BranchCount(root->left) + BranchCount(root->right);
	}


	//Question 11
	void PrintTreeByRow(Node* root)
	{
		queue<Node*>q;
		q.push(root);
		q.push(nullptr);

		while (!q.empty())
		{
			Node* temp = q.front();
			
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
				cout << temp->data << " ";
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


	//Question 12
	int CountLeaves(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		if (root->left != nullptr && root->right != nullptr)
		{
			return 1;
		}

		return CountLeaves(root->left) + CountLeaves(root->right);
	}

};





int main()
{

}

