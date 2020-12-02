#pragma once
#include <string>

class Spice{
    public:
    std::string color;
    double tPrice;
    int qty;
    int uPrice;


    void setPrice(double tPrice, double qty){
        this->tPrice = tPrice;
        this->qty = qty;
        this->uPrice = tPrice / qty;
        
    }
};
