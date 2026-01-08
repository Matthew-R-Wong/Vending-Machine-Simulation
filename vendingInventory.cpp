
#include "vendingItem.h"
#include "vendingInventory.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


inventory::inventory() {
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            vending[i][j].setStock(4);
            switch(i) {
                case 0:
                case 2:
                    vending[i][j].setPrice(1.75);
                    break;                                          //initialize the vending machine array
                case 1:
                case 3:
                    vending[i][j].setPrice(2.25);
                    break;
                case 4:
                    vending[i][j].setPrice(2.00);
                    break;
            }
        }
    }
};

void inventory::resetMachine() {
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            vending[i][j].setStock(4);
            switch(i) {
                case 0:
                case 2:
                    vending[i][j].setPrice(1.75);                   //function to reset the array back to full stock
                    break;
                case 1:
                case 3:
                    vending[i][j].setPrice(2.25);
                    break;
                case 4:
                    vending[i][j].setPrice(2.00);
                    break;
            }
        }
    }
    
    costOfRefill = 0;
}

void inventory::printMachine() const {
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {                                //function to print out the stock of the array
            cout << "[" << vending[i][j].getStock() << "]";
        }
		cout << "\n";
    }
    
}

void inventory::printEmptyMachine() {
    const int maxStock = 4;
    for (int i = 0; i < 5; i++) {
        cout << "\n";
        for (int j = 0; j < 5; j++) {                               //function to print the stock missing from the array
            int missing = maxStock - vending[i][j].getStock();
            cout << "[" << missing << "]";
        }
    }
}

void inventory::buyItem(int x, int y) {
    
    if(vending[x][y].getStock() == 0) {
        cout << "Item [" << x << "][" << y<< "] out of stock\n";    //function to lower the stock of an array spot by one
        return;
    }
    
    vending[x][y].lowerStock();                                     //also prevents buying if array spot is empty, and alerts if an array spot is low
    
    if(vending[x][y].getStock() == 1) {
        cout << "ALERT: [" << x << "][" << y << "] IS LOW\n";
        return;
    }
}

void inventory::itemAlert() const {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(vending[i][j].getStock() == 4) {                     //function to print out when an array spot has not sold in a given week
                cout << "\nItem [" << i << "][" << j << "] has not sold this week";
            }
        }
    }
}

int inventory::getCostOfRefill() const {
    return costOfRefill;                                            //return function
}

void inventory::countCostOfRefill() {
    double temp = 0;
    costOfRefill = 0;
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {                                //function to get the cost of everything that the machine woule need refilled
            if(vending[i][j].getStock() != 4) {
               temp += (4 - vending[i][j].getStock()) * vending[i][j].getPrice();
            }
        }
    }
    
    costOfRefill = temp;
}

void inventory::printCostOfRefill() const {                         //function to print the cost
    cout << "The costOfRefill for this machine is " << costOfRefill << endl;
}

int inventory::getProfit() const {
    return profit;                                                  //return function
}

void inventory::setProfit() {
        countCostOfRefill();
        profit = 290 - costOfRefill;                                //function to set the profit of the machine by lowering the weekly number by cost to refill
}


int inventory::getWeekProfit() {
    totalProfit += profit;
    thisWeekProfit = profit;                                        //return the weekly profit of the machine
    profit = 0;
    return thisWeekProfit;     
}

void inventory::printProfitSummary(int weekNumber) const {          //function to print out the weekly profit
    cout << "Week " << weekNumber << " profit: $" << profit << endl;
}

void inventory::updateTotalProfit() {
    totalProfit += profit;                                          //function to update the total profit of every machine
}

int inventory::getTotalProfit() {
    return totalProfit;                                             //return function
}

void inventory::stuckItem() {                                       //function for when an item is stuck
    cout << "Item is stuck, please choose another\n";
}