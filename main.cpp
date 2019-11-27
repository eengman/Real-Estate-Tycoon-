/*********************************************************************************************************
 * Program: main.cpp
 * Description: This is the file that runs the game as well as contains helper functions for the game
 *
 * Author: Eric Engman
 * ID: 40855107
 * Honor code: I pledge that this is my work and I received no help
 *********************************************************************************************************/

#include <iostream>
#include "Property.h"
#include "House.h"
#include "Player.h"
#include "Apartment.h"
#include "Tenant.h"
#include "Business.h"

/*******************************************************************************************************
 * Function: payPropertyTax
 * Description: every twelve turns property tax is paid and player bankaccount is updated
 * @param player player object
 * @param prop properties
 */
void payPropertyTax(Player &player, Property**prop){
    int tax = 0;
    int taxOwed = 0;
    for(int i = 0; i <= 8; i++){
        if(prop[i]->isOwned()){
            tax = prop[i]->getPropertyValue() * 0.015;
            taxOwed += tax;
        }
    }
    cout << endl;
    cout << "Its Tax Time!! You have to pay: $" << taxOwed << " dollars" << endl;
    player.updatePurchase(taxOwed);
}
/*******************************************************************************************************
 * Function: setApartmentTenantsMax
 * Description: sets the max rent for the tenants in the apartment and business complex
 * @param numTenants pointer to tenant array
 * @param n number of tenants
 */
void setApartmentTenantsMax(int *numTenants, int n){
    for(int i = 0; i < n; i++){
        numTenants[i] = rand() % 5000 + 500;
    }
}
/********************************************************************************************************
 * Function: setRent
 * Description: sets the rent for each property
 * @param prop properties
 */
void setRent(Property **prop){
    for(int i = 0; i <= 8; i++){
        //if(prop[i]->getPropertyValue() < 400000){
            prop[i]->setRent(rand() % 5000 + 500);
            prop[i]->setMaxRent(rand() % 5000 + 500);
            prop[i]->setAgreement(rand() % 5 + 1);
        //}
    }
}

/********************************************************************************************************
 * Function: checkRent
 * Description: checks whether the tenants can afford their new rent if it is adjusted. If they cannot then
 *              a tenant will leave
 * @param prop properties
 */
void checkRent(Property **prop){
    for(int i = 0; i <= 8; i++){
        if(prop[i]->isOwned()){
            if(prop[i]->getMaxRent() < prop[i]->getRent()){
                prop[i]->setNumTenants(prop[i]->getNumTenants() - 1);
                cout << "\nI am sorry, one of your tenants has left from " << prop[i]->getPropertyType() << endl;
            }
        }
    }
}
/********************************************************************************************************
 * Function: changeRent
 * Description: Prompts the player for what property they would like to adjust rent on and does so accordingly
 * @param prop properties
 */
void changeRent(Property **prop){
    int choice = 0;
    int choice2 = 0;
    cout << "What property would you like to change rent for? " << endl;
    for(int i = 0; i < 9; i++){
        if(prop[i]->isOwned()){
            cout <<  i  << " " << prop[i]->getPropertyType() << ", $" << prop[i]->getPropertyValue() << " | ";
        }
    }
    cout << endl;
    cin >> choice;
    cout << "Would you like to raise or lower rent? 1: raise or 2: lower" << endl;
    cin >> choice2;
    if(choice2 == 1){
        prop[choice]->increaseRent(1000);
    }
    if(choice2 == 2 && prop[choice]->getRent() > 1000){
        prop[choice]->decreaseRent(500);
    }else if(prop[choice]->getRent() < 1000){
        cout << "I'm sorry, the rent cannot be lowered any further" << endl;
    }
}
/********************************************************************************************
 * Function: collectHouseRent
 * Description: collects rent from all player owned properties (not only house despite function name,
 *              taking in account # of tenants/spaces
 * @param player player object
 * @param prop all properties
 */
void collectHouseRent(Player &player, Property **prop){
    int rent = 0;
    for(int i = 0; i <= 2; i++ ){
        if(prop[i]->isOwned() && prop[i]->getNumTenants() > 0){
            rent += prop[i]->getRent();
        }else if(prop[i]->isOwned() && prop[i]->getNumTenants() <= 0){
            cout << "\nI'm sorry, there are no tenants to pay rent in " << prop[i]->getPropertyType() << endl;
        }
    }
    for(int i = 3; i <= 8; i++){
        if(prop[i]->isOwned() && prop[i]->getNumTenants() > 0){
            rent += prop[i]->getRent() * prop[i]->getNumTenants();
        }else if(prop[i]->isOwned() && prop[i]->getNumTenants() <= 0){
            cout << "\nI'm sorry, there are no tenants to pay rent in " << prop[i]->getPropertyType() << endl;
        }
    }
    cout << "\n> Rent collected last turn: $" << rent << endl;
    player.updateSell(rent);
}
/***************************************************************************************
 * Function: Buy property
 * Description: asks the player what property they would like to buy and calls Player Class buyProperty function
 * @param player player object
 * @param prop all properties
 */
void buyProperty(Player &player, Property **prop){
    int choice;
    cout << "What property would you like to buy?" << endl;
    for(int i = 0; i <= 8; i++){
        if(!prop[i]->isOwned() && !prop[i]->getSold()){
            cout << i << ": " << " '" << prop[i]->getPropertyType() << "' " << ", Price: $" << prop[i]->getPropertyValue() <<
            ", Location: " << prop[i]->getLocation() << endl;
        }
    }
    cin >> choice;
    player.addProperty(*prop[choice]);
    player.updatePurchase(prop[choice]->getPropertyValue());        // update bank account
    prop[choice]->setOwned(true);
}

/**************************************************************************************
 * Function: sellProperty
 * Description: asks the player what property it would like to sell and calls Player class sellProperty function
 * @param player player object
 * @param prop all properties
 */
void sellProperty(Player &player, Property **prop){
    int choice;
    cout << "What property would you like to sell?" << endl;
    for(int i = 0; i <= 8; i++){
        if(prop[i]->isOwned()){
            cout << i << ": " << prop[i]->getPropertyType() << endl;
            cout << "Value: $" << prop[i]->getPropertyValue() << endl;
        }
    }
    cin >> choice;
    prop[choice]->setOwned(false);
    prop[choice]->setSold(true);
    player.updateSell(prop[choice]->getPropertyValue());
    player.sellProperty(player, *prop[choice]);

}

/*********************************************************************************************
 * Fucntion: randomEvent
 * Description: Picks a random event to occur and adjust property values accordingly
 * @param player: player object
 * @param n: a number randomly generated
 * @param props: all properties
 * @return: player object
 */
Player& randomEvent(Player &player, int n, Property** props){
    switch(n){
        case 1: player.hurricane(props);
        break;
        case 2: player.tornado(props);
        break;
        case 3: player.earthquake(props);
        break;
        case 4: player.wildfire(props);
        break;
        case 5: player.stockMarketCrash(props);
        break;
        case 6: player.gentrification(props);
        break;
    }
    return player;
}

int main() {

    /****************************************************************************************************************
     *                                          Game Setup
     * Description: the following sets up the properties and the tenants for each property
     ****************************************************************************************************************/

    // Locations to be passed in the constructors
    string loc[] = {"SE", "NE", "Midwest", "SW", "NW"};
    // Creates tenant objects that will be passed
    Tenant * houseTenant[9];

    // This holds all the properties
    Property* props[9] = {new House(rand() % 200000 + 100000,loc[rand() % 4] , rand() % 5000 + 1000, 1.5, houseTenant[0], "Riverbrook House"),
                          new House(rand() % 200000 + 100000, loc[rand() % 4], rand() % 5000 + 1000, 1.5, houseTenant[1], "Bill Gates House"),
                          new House(rand() % 200000 + 100000, loc[rand() % 4], rand() % 5000 + 1000, 1.5, houseTenant[2], "Ellensburg House"),
                          new Apartment(rand() % 400000 + 300000,loc[rand() % 4] , rand() % 5000 + 1000, 1.5, houseTenant[3], "Luxury Apartments"),
                          new Apartment(rand() % 400000 + 300000, loc[rand() % 4], rand() % 5000 + 1000, 1.5, houseTenant[4], "Ellensburg Apartments"),
                          new Apartment(rand() % 400000 + 300000, loc[rand() % 4], rand() % 5000 + 1000, 1.5, houseTenant[5], "The Verge Apartments"),
                          new Business(rand() % 500000 + 400000, loc[rand() % 4], rand() % 10000 + 2000, 1.5, houseTenant[6], "Business Complex 1"),
                          new Business(rand() % 500000 + 400000, loc[rand() % 4], rand() % 10000 + 2000, 1.5, houseTenant[7], "Business Complex 2"),
                          new Business(rand() % 500000 + 400000, loc[rand() % 4], rand() % 10000 + 2000, 1.5, houseTenant[8], "Business Complex 3")
                             };

    /*****************************************************************************************************
     * I could not get the number of tenants to initialize correctly for some reason so I had to write this
     * monstrosity to get everything to work properly
     */
    props[3]->setNumTenants(rand() % 10 + 1);
    props[4]->setNumTenants(rand() % 10 + 1);
    props[5]->setNumTenants(rand() % 10 + 1);
    props[6]->setNumTenants(rand() % 5 + 1);
    props[7]->setNumTenants(rand() % 5 + 1);
    props[8]->setNumTenants(rand() % 5 + 1);
    int * aptTenants1 = new int[props[3]->getNumTenants()];
    int * aptTenants2 = new int[props[4]->getNumTenants()];
    int * aptTenants3 = new int[props[5]->getNumTenants()];
    int * bTenants1 = new int[props[6]->getNumTenants()];
    int * bTenants2 = new int[props[7]->getNumTenants()];
    int * bTenants3 = new int[props[8]->getNumTenants()];
    setApartmentTenantsMax(aptTenants1, props[3]->getNumTenants());
    setApartmentTenantsMax(aptTenants2, props[4]->getNumTenants());
    setApartmentTenantsMax(aptTenants3, props[5]->getNumTenants());
    setApartmentTenantsMax(bTenants1, props[6]->getNumTenants());
    setApartmentTenantsMax(bTenants2, props[7]->getNumTenants());
    setApartmentTenantsMax(bTenants3, props[8]->getNumTenants());

    // set the rent for all of the properties
    setRent(props);

    // create player object
    Player player;

    // miscellaneous setup and greeting
    bool isGame = true;
    int turn = 1;
    int turnCheck = 12;
    int choice = 0;
    int numProps = 0;
    string name;
    cout << endl;
    cout << "Hello, and welcome to the game Real Estate Tycoon" << endl;
    cout << endl;
    cout << "Please enter your name: " << endl;
    getline(cin,name);
    player.setName(name);
    cout << endl;
    cout << "Hello " << name << ", I wish you good fortune!" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << endl;

    /**
     * This is the game loop
     */
    while(isGame){
        // check if player has won
        if(player.getBankAccount() >= 1000000){
            cout << "\nYour bank account is over $1,000,000. You Won!!!" << endl;
            isGame = false;
            return 0;
        }
        // check if player has gone bankrupt
        if(player.getBankAccount() < 0){
            cout << "\nYou went bankrupt. Sorry you lose :(((((" << endl;
            isGame = false;
            return 0;
        }

        // Print out current game info
        cout << "> Turn number: " << turn << endl;
        cout << "> Current Bank Account: $" << player.getBankAccount() << endl;
        cout << "> Number of Properties owned: " << numProps << endl;
        cout << "> Properties Owned: " << endl;

        // Print out current properties owned by the player
        for(int i = 0; i < 9; i++){
            if(props[i]->isOwned()){
                cout << "         -- '" << props[i]->getPropertyType() << "' " << ", Price: $" <<
                props[i]->getPropertyValue() << ", Location: " << props[i]->getLocation() <<
                ", # of Occupants: " << props[i]->getNumTenants() << endl;
            }
        }

        // Pay Property tax every 12 turns (months)
        if(turn == turnCheck){
            payPropertyTax(player, props);
            turnCheck += 12;
        }

        // Player choices
        cout << endl;
        cout << "What would you like to do? (Please enter a number)" << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << "|                                                                |" << endl;
        cout << "|   Buy Property: 1  Sell Property: 2  Change Rent: 3   Pass: 4  |" << endl;
        cout << "|                                                                |" << endl;
        cout << "------------------------------------------------------------------" << endl;
        cin >> choice;

        // choices
        switch(choice){
            case 1: buyProperty(player, props);     // buy a property
                numProps++;
                break;
            case 2: sellProperty(player, props);        // sell a property
                numProps--;
                break;
            case 3: changeRent(props);      // adjust the rent for a property
                    checkRent(props);       // checks if tenants can afford the changed rent
                break;
            case 4:         // pass if the player doesn't want to do any of the options
                break;
        }
        int ran = rand() % (6 - 1) + 1;
        randomEvent(player, ran, props);        // call random event
        collectHouseRent(player, props);        // collect rent on owned properties
        turn++;     // increment turn
    }

    return 0;
}