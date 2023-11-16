#include <iostream>
using namespace std;

//Question 1
template<typename T>
class LinkList
{
    class Node
    {


    public:
        T data;
        Node* next;

        Node(T val)
        {
            next = nullptr;
            data = val;
        }
    };

    Node* head;
    Node* tail;
public:
    LinkList()
    {
        head = nullptr;
        tail = nullptr;
    }

    
    bool isEmpty() //Part 1
    {
        return head == nullptr;
    }


    void InsertAtFront(T val) //Part 2
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
            head = newNode;
        }
    }

    void InsertAtTail(T  val) //Part 3
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
            tail = newNode;
        }
    }

    void InsertAtMid(T val) //Part 4
    {
        Node* nextToMiddle = head;
        Node* middle = head;
        Node* prev = nullptr;
        if (head == nullptr) {
            head = new Node(val);
            return;
        }
        while (nextToMiddle->next != nullptr && nextToMiddle != nullptr)
        {
            prev = middle;
            nextToMiddle = nextToMiddle->next->next;
            middle = middle->next;
        }

        Node* newNode = new Node(val);
        if (prev != nullptr)
        {
            prev->next = newNode;
        }
        else
        {
            head = newNode;
        }
        newNode->next = middle;

    }
    void InserAfter(T val, T key) //Part 5(a)
    {
        Node* temp;
        temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                Node* newNode = new Node(key);
                newNode->next = temp->next;
                temp->next = newNode;
                break;
                
            }
            else
            {
                temp = temp->next;
            }
        }
        
    }

    void InsertBefore(T val, T key) //Part5(b)
    {
        Node* temp;
        Node* prev = nullptr;

        temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {

                Node* newNode = new Node(key);
                
                if (temp == head)
                {
                    newNode->next = head;
                    head = newNode;
                }
                else
                {
                    prev->next = newNode;
                    newNode->next = temp;
                    
                }
                return;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }

    }

    Node* GetFront() //Part 6
    {
        return head;
    }

    Node* GetTail() //Part 7
    {
        return tail;
    }

    Node* Search(T val) //Part 8
    {
        Node* temp;
        temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return temp;
            }
            else
            {
                temp = temp->next;
            }
        }
        return NULL;
    }


    T RemoveAtFront() //Part 9(a)
    {
        if (head == nullptr || isEmpty())
        {
            return  NULL;
        }

        Node* temp = head;
        head = head->next;
        return temp->data;
        temp = nullptr;
    }


    T RemoveAtTail() //Part 9(b)
    {

        if (head == nullptr || isEmpty())
        {
            return NULL;
        }
        if (head->next == nullptr)
        {
            head = nullptr;
            tail = nullptr;
            return NULL;
        }
        else
        {
            Node* temp = head;
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }
            return temp->next;
            temp->next = nullptr;
            tail = temp;
        }
    }


    T RemoveAtMiddle() //Part 9(c)
    {
        Node* temp = head;
        Node* middle = head;
        Node* prev = nullptr;
        if (prev == nullptr || prev->next == nullptr)
        {
            return;
        }
        while (temp->next != nullptr && temp!=nullptr)
        {
            prev = middle;
            temp = temp->next->next;
            middle = middle->next;
        }

        Node* toRemove = prev->next;
        prev->next = toRemove->next;
        return toRemove->data;
        toRemove = nullptr;
        
    }


    void PrintRecursive(Node* head) //Question 3 part 1
    {
        if (head == nullptr)
        {
            return;
        }

        cout << head->data<<endl;
        PrintRecursive(head->next);
        cout << head->data << endl;;
    }

    T GetMiddle() //Question 3 part 2
    {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    void Reverse() //Question 3 part 4
    {
        Node* curr = head;
        Node* next = NULL;
        Node* prev = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;

    }
    
    bool isCircular() //Question 3 Part 3
    {

        if (!head)
        {
            return false;
        }


        Node* first = head;
        Node* second = head;

        
        while (first && first->next)
        {
            second = second->next->next;
            first = first->next;

            if (first == second)
            {
                return true;
            }
        }
        return false;
    }


    void Display()
    {
        Node* temp;
        temp = head;
        while (temp != nullptr)
        {
            cout << temp->data <<endl;
            temp = temp->next;
        }
    }


};


//Stack using LinkList
template<typename T>
class Stack
{
    LinkList<T>s;
public:
    Stack()
    {

    }

    void Push(T val)
    {
        s.InsertAtFront(val);
    }

    T Pop()
    {
        return s.RemoveAtFront();

    }

    bool isEmpty()
    {
        return s.isEmpty();
    }

    void Display()
    {
        s.Display();
    }
};


//Queue using LinkList
template<typename T>
class Queue
{
    LinkList<T> q;
public:
    Queue()
    {

    }

    void Enqueue(T val)
    {
        q.InsertAtTail(val);
    }

    T Dequeue()
    {
        return q.RemoveAtFront();
    }

    bool isEmpty()
    {
        return q.isEmpty();
    }

    void Display()
    {
        q.Display();
    }
};


int main()
{
    LinkList<int> l;
    l.InsertAtFront(1);
    l.InsertAtTail(2);
    l.InsertAtTail(3);

    cout << l.GetMiddle();
    
    
}

