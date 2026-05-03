#ifndef CUTIE_HPP
#define CUTIE_HPP

#include <string>

class Cutie {
protected:
    std::string description;
    int cuteness_rating;

public:
    Cutie(std::string description, int cuteness_rating)
        : description(description), cuteness_rating(cuteness_rating) {}

    virtual std::string get_description() = 0;
    virtual int get_cuteness_rating() = 0;

    virtual ~Cutie() {}
};

#endif