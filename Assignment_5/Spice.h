#pragma once
#include <string>

class Spice{
    public:
    std::string color;
    double tPrice;      //total price
    int qty;            //quantity
    int uPrice;         //unit price


    void setPrice(double tPrice, double qty){   //function that simultaneously sets the price per unit, total price, and quantity
        this->tPrice = tPrice;
        this->qty = qty;
        this->uPrice = tPrice / qty;
        
    }
};
