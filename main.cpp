/**


Name: Matthew Wong
Date: 07/29/2025
Program Description: This program simulates the workings of three vending machines. You input the menu that you want to select and any additional information it asks for.
the program will then go through the days and weeks that your vending machines are active, and will give you updates on your progress in making money and affording
future machines. Option 1 will print out the array for each machine, option two will allow you to pick a specific drink from the machine array, option 3 will auto simulate the
given algorithm for vending purchases, option 4 will print out the cost to refill each vending machine, and finally 0 will quit the program.

**/

#include "vendingItem.h"
#include "vendingInventory.h"
#include <iostream>                                                     //definitions and inclusions
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
#define COSTOF8MACHINES 2915
using namespace std;

int main()
{
	int input, day = 1, week = 0, x, y, i, increment = 0, profitMade, allProfit, paymentMethod, totalSavings = 0, timeline = 0, estimatedDays, weeklySavings, weeklyProfit;
	double savingsPerDay, savingsAmount, withdrawalAmount, combinedProfit;
	inventory machine[3];												//declare variables

	do {                                                                //loop while input != 0
        
		cout << "\n\nWeek " << week << " Day " << day << endl;
		cout << "\nPlease Choose an Option: " << endl;					//print out instructions for menu
		cout << "1 for print\n2 for purchase\n3 for simulation\n4 to print cost to refill machine\n5 to skip the week\n0 to end program" << endl;
		cin >> input;
        
		for(i = 0; i < 3; i++) {
		    srand(time(0));                                             //rendomize
		    cout << "\n\nMachine[" << i + 1 << "]\n";
		    
    		switch(input) {                                             //switch function to read menu inputs
    		case 1:
    			machine[i].printMachine();                              //call to print function
    			break;
    		case 2:
    			cout << "Enter the drink row and column separated by a space" << endl;
    			cin >> x;
    			cin >> y;                                               //function to buy a single specific item from the machine
    			machine[i].selectItem(x, y);
				machine[i].update();
    			break;
            case 3:
 				for(int j=0; j<2; j++) {
					machine[i].selectItem(2, rand() % 5);
					machine[i].update();								//Simulating people buying drinks
				}
				
                if(rand() % 10 == 4) {
                    cout << "ALERT: Coins have been used to pay\n";     //simulate random coin purchases
                }
                
				for(int j=0; j<2; j++) {
	 			 	machine[i].selectItem(3, rand() % 5);
					machine[i].update();								//2 from row 4
                }
				
    			for(int j=0; j<3; j++) {
					machine[i].selectItem(1, 2);
					machine[i].update();								//3 from row 2 slit 3
				}
				
                if(rand() % 10 == 4) {
                    cout << "ALERT: Card has been used to pay\n";       //simulate random card purchases
                }
                
				for(int j=0; j<2; j++) {
					machine[i].selectItem(0, rand() % 5);
					machine[i].update();
                }
				
				machine[i].selectItem(4, rand() % 5);
				machine[i].update();									//1 from row 5
                
    			for(int j=0; j<3; j++) {
					machine[i].selectItem(4, 3);
					machine[i].update();								//3 from row 5 slit 4
				}
                
                if(rand() % 10 == 4) {
                    cout << "ALERT: Coins have been used to pay\n";
                }
                
				for(int j=0; j<3; j++) {
					machine[i].selectItem(0, rand() % 5);
					machine[i].update();				                //3 from row 1 random slits
                }

                if(rand() % 10 == 4) {
                    cout << "ALERT: Card has been used to pay\n";
                }
                
				
				for(int j=0; j<5; j++) {
					machine[i].selectItem(j, rand() % 5);
					machine[i].update();								//1 from each row
                }

                break;
            case 4:
                machine[i].countCostOfRefill();
                machine[i].printCostOfRefill();                         //get the cost to refill machine, and print the cost
                break;
			case 5:
				printf("Skipped to end of week");
				day = 7;
				break;
            case 0:
                return 0;
    		}
    		std::this_thread::sleep_for(std::chrono::seconds(1));       //input a time buffer so numbers can randomize
		}

		day++;

        if(day == 8) {                                                  //functions that happen at the start/end of the week
            
            cout << "\n\nMachine 1";    
            machine[0].itemAlert();    
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "\n\nMachine 2";    
            machine[1].itemAlert();                                     //check to see what drinks haven't sold in the week
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "\n\nMachine 3";    
            machine[2].itemAlert();    
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "\n\n";
        
            cout << "\nDrinks sold from each slot: ";
            for(int g = 0; g < 3; g++) {
                std::this_thread::sleep_for(std::chrono::seconds(1));   //prints out the number of missing drinks for each spot
                cout << "\n\nMachine[" << g + 1 << "]";
                machine[g].printEmptyMachine();
            }
        
			std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "\n\n----- Weekly Profit Summary (Week " << week << ") -----\n\n";
        
            combinedProfit = 0.0;
            for(int g = 0; g < 3; g++) {
                machine[g].setProfit();
                weeklyProfit = machine[g].getWeekProfit();              //tracks the weekly profit of each machine
                combinedProfit += weeklyProfit;                         //then calculates the total combined profit of the three machines
                cout << "Machine " << g + 1 << " profit: $" << weeklyProfit << endl;
            }
			std::this_thread::sleep_for(std::chrono::seconds(1));
        
            savingsAmount = combinedProfit * 0.5035;                    //Applies percentages of profit to savings and personal withdrawl
            withdrawalAmount = combinedProfit * 0.3995;                 //I already counted the restocking costs into my program, so I took the
            ;                                                           //percentage for restocking and gave half of it to both savings and withdrawl
            totalSavings += savingsAmount;                              //This is the total savings of all weeks added together
        
            cout << "\nCombined profit from all machines: $" << combinedProfit << endl;
            cout << "-> Personal savings (39.95%): $" << savingsAmount << endl;      
            cout << "-> Withdrawal (60.05%):       $" << withdrawalAmount << endl;  //print out the percentages and total savings
			std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "\nTotal savings so far: $" << totalSavings << endl;
            
            estimatedDays = 0;
            if (savingsAmount > 0) {
                weeklySavings = (int)savingsAmount;                     //calculate the approximate number of days to get 5 machines
                savingsPerDay = weeklySavings / 7;
                
                if (savingsPerDay > 0) {
                    estimatedDays = COSTOF8MACHINES / savingsPerDay;
                    cout << "It will take approximately " << estimatedDays << " days to afford 5 machines." << endl;
                } else {
                    cout << "Not enough savings per day to estimate timeline." << endl;
                }
                
            } else {
                cout << "No savings this week to estimate timeline." << endl;
            }

        
            for(int g = 0; g < 3; g++) {                                //reset the machines at the end of the week after taking out the restock costs from profit
				machine[g].setState(MachineState::RESTOCKING);
				machine[g].update();
            }
            cout << "\nMachines have been restocked";
        
            day = 1;                                                    //set the start of a new week and increment week by 1
            week++;
        }

	} while(input != 0);

	return 0;
}