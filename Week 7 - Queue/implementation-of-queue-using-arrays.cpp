#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[5];
    int front = -1, rear = -1;
    int capacity = sizeof(arr) / sizeof(arr[0]);

public:
    /** isFull()
     * @return true if the queue is full
     */
    bool isFull()
    {
        if (rear == capacity - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /** isEmpty
     * @return true if the queue is empty,
     */
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /** Enqueue
     * @param data to input data into the queue at rear position
     */
    void Enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
        cout << "Enqueued " << arr[rear] << endl;
    }

    /** Dequeue
     * @return it returns the data which is being removed from the queue
     */
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int temp = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }

        cout << "Dequeueing..." << temp << endl;
        return temp;
    }

    /** peek
     * @return the value at the front of the queue
     */
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    Queue q;
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(6);
    q.Enqueue(9);
    q.Enqueue(10);
    q.Enqueue(15);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    return 0;
}