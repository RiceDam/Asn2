//
// Created by eric on 2020-11-27.
//
#ifndef ASN2_CITY_HPP
#define ASN2_CITY_HPP


#include <string>

class City {
private:
    std::string name;
    int x;
    int y;
public:
    City(std::string name1);

    void setCoordinates(int x1, int y1);

    void setName(std::string name1);

    const std::string &getName() const;

    int getX() const;

    int getY() const;
};


#endif //ASN2_CITY_HPP
