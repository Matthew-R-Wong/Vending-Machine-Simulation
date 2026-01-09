
#ifndef VENDINGINVENTORY_H
#define VENDINGINVENTORY_H
#include "vendingItem.h"

enum class MachineState {
    IDLE,
    WAITING_FOR_SELECTION,
    CHECK_STOCK,
    DISPENSING,										//define state machine states
    OUT_OF_STOCK,
    RESTOCKING
};

class inventory {                                   //declare the class inventory
public:
	inventory();
	void printMachine() const;
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
    void printEmptyMachine();
	void update();
	void selectItem(int x, int y);
	void setState(MachineState newState);


private:
	MachineState state;
    int selectedRow;
    int selectedCol;
	drinkType vending[5][5];
	double costOfRefill;
	double profit;                                 //declare the screen array, and variables used for the vending machine
	double totalProfit;
	double thisWeekProfit;

};


#endif