#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/hello.hpp"

// Dummy Cutie implementations
class Puppy : public Cutie {
public:
    Puppy() : Cutie("Puppy", 10) {}
    std::string get_description() override { return description; }
    int get_cuteness_rating() override { return cuteness_rating; }
};

class Kitty : public Cutie {
public:
    Kitty() : Cutie("Kitty", 9) {}
    std::string get_description() override { return description; }
    int get_cuteness_rating() override { return cuteness_rating; }
};

class PygmyMarmoset : public Cutie {
public:
    PygmyMarmoset() : Cutie("Pygmy Marmoset", 11) {}
    std::string get_description() override { return description; }
    int get_cuteness_rating() override { return cuteness_rating; }
};

TEST_CASE("Queue starts empty") {
    QueueTees queue(3);
    REQUIRE(queue.size() == 0);
}

TEST_CASE("Enqueue increases size") {
    QueueTees queue(3);
    Puppy p; Kitty k; PygmyMarmoset m;

    queue.enqueue(&p);
    queue.enqueue(&k);
    queue.enqueue(&m);

    REQUIRE(queue.size() == 3);
}

TEST_CASE("FIFO order works") {
    QueueTees queue(3);
    Puppy p; Kitty k; PygmyMarmoset m;

    queue.enqueue(&p);
    queue.enqueue(&k);
    queue.enqueue(&m);

    REQUIRE(queue.dequeue()->get_description() == "Puppy");
    REQUIRE(queue.dequeue()->get_description() == "Kitty");
    REQUIRE(queue.dequeue()->get_description() == "Pygmy Marmoset");
}

TEST_CASE("Dequeue on empty returns nullptr") {
    QueueTees queue(3);
    REQUIRE(queue.dequeue() == nullptr);
}

TEST_CASE("Queue does not exceed capacity") {
    QueueTees queue(3);
    Puppy p; Kitty k; PygmyMarmoset m;

    queue.enqueue(&p);
    queue.enqueue(&k);
    queue.enqueue(&m);
    queue.enqueue(&p); // should not add

    REQUIRE(queue.size() == 3);
}