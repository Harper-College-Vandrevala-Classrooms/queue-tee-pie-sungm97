#include <iostream>
#include <string>
#define MAX_QUEUE_SIZE 10

using namespace std;

class Cutie {
public:
    virtual string description() = 0;  
    virtual int cuteness_rating() = 0; 
};

class Puppy : public Cutie {
public:
    string description() override {
        return "A little puppy with big, sad eyes";
    }
    int cuteness_rating() override {
        return 11; 
    }
};

class Kitty : public Cutie {
public:
    string description() override {
        return "A fluffy kitten with soft fur";
    }
    int cuteness_rating() override {
        return 11; 
    }
};

class PygmyMarmoset : public Cutie {
public:
    string description() override {
        return "A tiny monkey that melt your heart";
    }
    int cuteness_rating() override {
        return 11; 
    }
};

class QueueTees {
private:
    Cutie* queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int currentSize;

public:
    QueueTees() : front(0), rear(0), currentSize(0) {}

    void enqueue(Cutie& cutie) {
        if (currentSize >= MAX_QUEUE_SIZE) {
            cout << "The queue is full!" << endl;
            return;
        }
        queue[rear] = &cutie;
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        currentSize++;
    }

    Cutie* dequeue() {
        if (currentSize == 0) {
            cout << "The queue is empty!" << endl;
            return nullptr;
        }
        Cutie* cutie = queue[front];
        front = (front + 1) % MAX_QUEUE_SIZE;
        currentSize--;
        return cutie;
    }

    int size() {
        return currentSize;
    }
};

int main() {
    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;

    QueueTees queue;

    cout << "Initial queue size: " << queue.size() << endl;

    queue.enqueue(puppy);
    queue.enqueue(kitty);
    queue.enqueue(marmoset);

    cout << "Queue size after enqueuing: " << queue.size() << endl;

    Cutie* dequeued = queue.dequeue();
    if (dequeued) cout << "Dequeued: " << dequeued->description() << endl;

    dequeued = queue.dequeue();
    if (dequeued) cout << "Dequeued: " << dequeued->description() << endl;

    dequeued = queue.dequeue();
    if (dequeued) cout << "Dequeued: " << dequeued->description() << endl;

    dequeued = queue.dequeue();

    return 0;
}
