#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class cirQueue
{
    int *arr;
    int currSize, cap;
    int f, r;

public:
    cirQueue(int size)
    {
        cap = size;
        arr = new int(cap); // dynamically memory allocation
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int data)
    {
        if (currSize == cap)
        {
            cout << "CQ is full";
            return;
        }
        else
        {
            r = (r + 1) % cap;
            arr[r] = data;
            currSize++;
        }
    }
    void pop()
    {
        if (empty())
        {
            cout << "empty queue";
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }
    int front()
    {
        return arr[f];
    }
    bool empty()
    {
        return currSize = 0;
    }
    void printArr()
    {
        for (int i = 0; i < currSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cirQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);

    cq.printArr();
    return 0;
}