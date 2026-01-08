
#ifndef VENDINGINVENTORY_H
#define VENDINGINVENTORY_H
#include "vendingItem.h"


class inventory {                                   //declare the class inventory
public:
	inventory();
	void printMachine() const;
	void buyItem(int x, int y);
	void itemAlert() const;
	int getCostOfRefill() const;
	void countCostOfRefill();
	void printCostOfRefill() const;
	int getProfit() const;                          //function declarations
	void setProfit();
	int getWeekProfit();
	void resetMachine();
    void printProfitSummary(int weekNumber) const;
    int getTotalProfit();
    void updateTotalProfit();
    void stuckItem();
    void printEmptyMachine();


private:
	drinkType vending[5][5];
	double costOfRefill;
	double profit;                                 //declare the screen array, and variables used for the vending machine
	double totalProfit;
	double thisWeekProfit;

};


#endif