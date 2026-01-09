
#include "vendingItem.h"


drinkType::drinkType(int p, int s) {
    price = p;                                  //initializer function
    inStock = s;
}

void drinkType::setStock(int stock) {
    inStock = stock;                            //function to set the number of items in stock
}

int drinkType::getStock() const {
    return inStock;                             //return function
}

void drinkType::setPrice(double priceSet) {
    price = priceSet;                           //function to set the price of each item in stock
}

double drinkType::getPrice() const {
    return price;                               //return function
}

void drinkType::lowerStock() {
    inStock--;                                  //function to lower the stock of an item when bought
}