#include <iostream>
#include "src/hello.hpp"

using namespace std;

class Puppy : public Cutie {
public:
    Puppy() : Cutie("Puppy", 10) {}
    string get_description() override { return description; }
    int get_cuteness_rating() override { return cuteness_rating; }
};

class Kitty : public Cutie {
public:
    Kitty() : Cutie("Kitty", 9) {}
    string get_description() override { return description; }
    int get_cuteness_rating() override { return cuteness_rating; }
};

class PygmyMarmoset : public Cutie {
public:
    PygmyMarmoset() : Cutie("Pygmy Marmoset", 11) {}
    string get_description() override { return description; }
    int get_cuteness_rating() override { return cuteness_rating; }
};

int main() {
    QueueTees queue(3);

    Puppy puppy;
    Kitty kitty;
    PygmyMarmoset marmoset;

    cout << queue.size() << endl;

    queue.enqueue(&puppy);
    queue.enqueue(&kitty);
    queue.enqueue(&marmoset);

    cout << queue.size() << endl;

    cout << queue.dequeue()->get_description() << endl;
    cout << queue.dequeue()->get_description() << endl;
    cout << queue.dequeue()->get_description() << endl;

    return 0;
}