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

public:
    Node *head;
    Node *tail;

    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail->next = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = newNode;
        }
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail->next = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    void printll() // 0(n)
    {
        Node *temp = head;
        cout << head->data << "->";
        temp = temp->next;

        while (temp != head)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
    void pop_front()
    {
        Node *temp = head;
        if (head == NULL)
            return;
        if (head == tail != NULL)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
    void pop_back()
    {
        Node *temp = tail;
        Node *prev = head;
        if (head == NULL)
            return;
        if (head == tail != NULL)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            while (prev->next != tail)
            {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
};

int main()
{
    List cll;
    cll.push_front(1);
    cll.push_front(2);
    cll.push_front(3);
    cll.push_back(4);

    cll.printll();

    return 0;
}