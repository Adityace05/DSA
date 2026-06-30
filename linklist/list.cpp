#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val) // 0(1)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) // 0(1)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front() // 0(n)
    {
        if (head == NULL)
            return;
        Node *temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back() // 0(n)
    {
        if (head == NULL)
            return;
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    void insert(int val, int pos) // insert any node between two nodes. with data/val and at position pos.
    {                             // 0(n)
        if (pos < 0)
            return;
        if (pos == 0)
            push_front(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
                return;
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    int searchLL(int key)
    { // 0(n)
        Node *temp = head;
        int idx = 0;
        while (temp == NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    void printll() // 0(n)
    {
        Node *temp;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_back(4);
    l1.printll();
    l1.insert(4, 1);
    l1.pop_front();
    l1.pop_back();
    l1.printll();

    return 0;
}