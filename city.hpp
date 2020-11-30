//
// Created by eric on 2020-11-27.
//
#ifndef ASN2_CITY_HPP
#define ASN2_CITY_HPP


#include <string>
#include <random>

class City {
private:
    std::string name;
    int x;
    int y;
public:
    const int MAP_BOUNDARY = 1000;
    City(std::string name1);
    void setCoordinates(int x1, int y1);
    void setName(std::string name1);
    const std::string &getName() const;
    int getX() const;
    int getY() const;
    void operator = (const City &c);
    friend bool operator == (const City &a, const City &b);
    friend bool operator != (const City &a, const City &b);
    void swap(City &other);
};


#endif //ASN2_CITY_HPP
