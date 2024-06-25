#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int item)
    {
        Node *newNode = new Node(item);
        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        cout << temp->data << " dequeued from queue" << endl;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    Node *peek() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return nullptr;
        }

        return front;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.dequeue();
    q.dequeue();

    // cout << q.peek()->data << endl;

    q.enqueue(40);
    q.enqueue(50);
    cout << q.peek()->data << endl;
    return 0;
}