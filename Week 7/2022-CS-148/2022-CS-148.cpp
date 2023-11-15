#include <iostream>
using namespace std;

template<typename T>

//Part A
class LinkList
{
    class Node
    {
    public:
        T data;
        Node* next;
        Node* prev;

        Node(T val){
            data = val;
            next = nullptr;
            prev = nullptr;
        }
    };

public:
    class iterator //General iterator Question 3
    {
        
    public:
        Node* iter;

        iterator(Node* curr)
        {
            iter = curr;
        }

        iterator& operator++()
        {
            iter = iter->next;
            return *this;
        }

        iterator& operator--()
        {
            iter = iter->prev;
            return *this;
        }

        T& operator*()
        {
            return iter->data;
        }

        bool operator==(const iterator& other) const
        {
            return iter == other.iter;
        }

        bool operator!=(const iterator& other) const
        {
            return iter != other.iter;
        }

        

    };

public:
    class ForwardIterator //Forward iterator Question 1
    {

    public:
        Node* iter;

        ForwardIterator(Node* curr)
        {
            iter = curr;
        }

        ForwardIterator& operator++()
        {
            iter = iter->next;
            return *this;
        }

        T& operator*()
        {
            return iter->data;
        }

        bool operator==(const ForwardIterator& other) const
        {
            return iter == other.iter;
        }

        bool operator!=(const ForwardIterator& other) const
        {
            return iter != other.iter;
        }



    };



public:

    class ReverseIterator // Reverse iterator Question 2
    {

    public:
        Node* iter;

        ReverseIterator(Node* curr)
        {
            iter = curr;
        }

        ReverseIterator& operator++()
        {
            iter = iter->prev;
            return *this;
        }

        T& operator*()
        {
            return iter->data;
        }

        bool operator==(const ReverseIterator& other) const
        {
            return iter == other.iter;
        }

        bool operator!=(const ReverseIterator& other) const
        {
            return iter != other.iter;
        }


    };

private:
    Node* head;
    Node* tail;

public:

    //Question 4

    LinkList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void InsertAtFront(T val) //Part 3
    {
        Node* newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void InsertAtTail(T  val) //Part 4
    {
        Node* newNode = new Node(val);
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void InsertAfter(T key, T val) //Part 2(a)
    {
        Node* temp;
        temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                Node* newNode = new Node(val);
                newNode->prev = temp;
                newNode->next = temp->next;
                temp->next->prev = newNode;
                temp->next = newNode;

                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    void InsertBefore(T key, T val) //Part 2(b)
    {
        Node* temp;
        temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                Node* newNode = new Node(val);
                if (temp == head)
                {
                    newNode->next = head;
                    temp->prev = newNode;
                    head = newNode;
                    newNode->prev = nullptr;
                }
                else
                {
                    temp->prev->next = newNode;
                    newNode->prev = temp->prev;
                    newNode->next = temp;
                    temp->prev = newNode;
                }
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    void Splice(LinkList<T>& source, LinkList<T>& destination, iterator position) //Part 5 
    {
        if (position.iter->prev == nullptr)
        {
            
            source.tail->next = position.iter;
            position.iter->prev = source.tail;

            destination.head = source.head;
        }
        else if (position.iter == nullptr)
        {
            position.iter->next = source.head;
            source.head->prev = position.iter;
            destination.tail = source.tail;
        }

        
        source.head = nullptr;
        source.tail = nullptr;
    }

    bool Empty() //Part 1
    {
        return head == nullptr;
    }

    ReverseIterator Rbegin()
    {
        return ReverseIterator(tail);
    }

    ReverseIterator Rend()
    {
        return ReverseIterator(nullptr);
    }

    ForwardIterator Fbegin()
    {
        return ForwardIterator(head);
    }

    ForwardIterator Fend()
    {
        return ForwardIterator(nullptr);
    }

    iterator begin()
    {
        return iterator(head);
    }

    iterator end()
    {
        return iterator(nullptr);
    }



    void Display()
    {
        for (ForwardIterator it = Fbegin(); it != Fend(); ++it)
        {
            cout << *it << endl;
        }
    }
};


//Leetcode Problems

//Part 1
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* temp = new ListNode(-1);
        ListNode* l3 = temp;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }

        if (l1 != NULL) {
            l3->next = l1;
        }
        else {
            l3->next = l2;
        }

        return temp->next;
    }
};

//Part 2
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(-1, head);
        ListNode* left = temp;
        ListNode* right = head;

        while (n > 0 && right)
        {
            right = right->next;
            n--;
        }

        while (right)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return temp->next;


    }

};

//Part 3
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (!head || !head->next)
        {
            return head;
        }


        ListNode* temp = new ListNode(-1);
        ListNode* curr = head;
        ListNode* prev = temp;

        while (curr && curr->next)
        {
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;

            prev = curr;
            curr = curr->next;
        }

        return temp->next;



    }
};

//Part 4
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* preLeft = temp;
        ListNode* curr = head;

        for (int i = 0; i < left - 1; i++)
        {
            preLeft = preLeft->next;
            curr = curr->next;
        }

        ListNode* tempHead = curr;
        ListNode* prev = NULL;

        for (int i = 0; i <= right - left; i++)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        preLeft->next = prev;
        tempHead->next = curr;

        return temp->next;


    }
};



//Part 5
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList {
public:
    int size = 0;
    Node* head = NULL;
    Node* tail = NULL;
    MyLinkedList()
    {

    }

    int get(int index) {
        if (index >= size)
        {
            return -1;
        }
        Node* temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (size == 0)
        {
            tail = newNode;
        }
        size++;
    }

    void addAtTail(int val) {
        if (size == 0)
        {
            addAtHead(val);
            return;
        }
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size)
        {
            return;
        }
        else if (index == size)
        {
            addAtTail(val);
        }
        else if (index == 0)
        {
            addAtHead(val);
        }
        else
        {
            Node* temp = head;
            Node* newNode = new Node(val);
            for (int i = 0; i < index - 1; ++i)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= size)
        {
            return;
        }
        else if (index == size - 1)
        {

            if (index == 0)
            {
                head == NULL;
                tail == NULL;
            }

            else
            {
                Node* temp = head;
                while (temp->next != tail)
                {
                    temp = temp->next;
                }
                tail = temp;
                temp->next = NULL;
            }

        }
        else if (index == 0)
        {
            Node* temp = head;
            head = head->next;
            temp = NULL;
        }

        else
        {
            Node* temp = head;
            for (int i = 0; i < index - 1; ++i)
            {
                temp = temp->next;
            }
            Node* t = temp->next;
            temp->next = temp->next->next;
            t->next = NULL;

        }
        size--;
    }
};


int main()
{
    LinkList<int> l;
    LinkList<int> l2;
    
    l.InsertAtTail(1);
    l.InsertAtTail(2);
    
    
    l.Display();

    
    return 0;
}
