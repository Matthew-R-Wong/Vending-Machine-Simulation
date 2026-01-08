
#ifndef VENDINGITEM_H
#define VENDINGITEM_H


class drinkType {                                   //declare the class drinkType
public:
    drinkType(int price = 0, int inStock = 0);
    void setStock(int stock);
    int getStock() const;
    void setPrice(double priceSet);                 //function declarations
    double getPrice() const;
    void lowerStock();
    
    
private:
    double price;                                   //declare the price and inStock variables
    int inStock;
    
};


#endif