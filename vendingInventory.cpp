
#include "vendingItem.h"
#include "vendingInventory.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


inventory::inventory() {
    state = MachineState::IDLE;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            vending[i][j].setStock(4);
            switch(i) {
                case 0:
                case 2: vending[i][j].setPrice(1.75); break;
                case 1:                                          	//initialize the vending machine array
                case 3: vending[i][j].setPrice(2.25); break;
                case 4: vending[i][j].setPrice(2.00); break;
            }
        }
    }
}


void inventory::update() {
    while(state != MachineState::IDLE) {
        switch (state) {
            case MachineState::IDLE:
                state = MachineState::WAITING_FOR_SELECTION;
                break;
            case MachineState::WAITING_FOR_SELECTION:
                return;
            case MachineState::CHECK_STOCK:
                if (vending[selectedRow][selectedCol].getStock() == 0) {
                    state = MachineState::OUT_OF_STOCK;
                } else {
                    state = MachineState::DISPENSING;
                }													//cycle through state machine states
                break;
            case MachineState::DISPENSING:
                vending[selectedRow][selectedCol].lowerStock();
                cout << "Dispensing item [" 
                     << selectedRow << "][" << selectedCol << "]\n";
                if (vending[selectedRow][selectedCol].getStock() == 1)
                    cout << "ALERT: Item running low\n";
                state = MachineState::IDLE;
                break;
            case MachineState::OUT_OF_STOCK:
                cout << "Item [" << selectedRow 
                     << "][" << selectedCol << "] OUT OF STOCK\n";
                state = MachineState::IDLE;
                break;
            case MachineState::RESTOCKING:
                resetMachine();
                cout << "Machine restocked\n";
                state = MachineState::IDLE;
                break;
        }
    }
}


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

void inventory::selectItem(int x, int y) {
    selectedRow = x;
    selectedCol = y;
    state = MachineState::CHECK_STOCK;
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

void inventory::setState(MachineState newState) {
    state = newState;
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

int inventory::getTotalProfit() {
    return totalProfit;                                             //return function
}