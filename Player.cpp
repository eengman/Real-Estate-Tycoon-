
#include "Player.h"
#include "House.h"

/***********************************************************************************
 * Constructor for player
 */
Player::Player() {
    pOwned = new Property[9];
    numProps = 0;
}

/***********************************************************************************
 * Function: copy constructor
 * @param p player object
 */
Player::Player(const Player& p){
    pOwned = new Property[numProps];
    *pOwned = *p.pOwned;
}

/**********************************************************************************
 * Function: overloaded assignment operator
 * @param p player object
 * @return this
 */
Player &Player::operator=(const Player &p) {
    numProps = p.numProps;
    pOwned = new Property[numProps];
    for(int i = 0; i < numProps; i++){
        pOwned[i] = p.pOwned[i];
    }
    return *this;
}

/***********************************************************************************
 * Function: sellProperty
 * Description: sells the specified property and then updates the player owned properties
 * @param player player object
 * @param p property object
 * @return this
 */
Player &Player::sellProperty(Player &player, Property &p) {
    numProps = player.numProps--;
    pOwned = new Property[numProps];
    for(int i = 0; i < numProps; i++){
        if(player.pOwned[i].getPropertyType() != p.getPropertyType()){
            this->pOwned[i] = player.pOwned[i];
        }
        else{
            i--;
        }
    }
    return *this;
}

/*********************************************************************************
 * Function: addProperty
 * Description: adds the specified property to player property array
 * @param p property to be purchased
 */
void Player::addProperty(Property &p) {
    pOwned[numProps] = p;
    numProps++;
}

// accessors
int Player::getBankAccount() const {
    return bankAccount;
}
Property *Player::getProperties() const {
    return pOwned;
}
int Player::getNumProps() const {
    return numProps;
}
void Player::setName(string n) {
    name = n;
}
string Player::getName() const {
    return name;
}

/**
 * Description: decreases bankaccount value
 * @param propValue amount to be decreased by
 */
void Player::updatePurchase(int propValue) {
    bankAccount -= propValue;
}

/**
 * Description: increases bankaccount value
 * @param propValue amount to be increased by
 */
void Player::updateSell(int propValue) {
    bankAccount += propValue;
}

// destructor
Player::~Player() {
    delete pOwned;
    pOwned = NULL;
}

/********************************************************************************************************
 * Function: hurricane
 * Description: adjust player property values as well as all property values based on the event
 * @param p all properties
 * @return this
 */
Player &Player::hurricane(Property **p) {
    cout << "\n----------------------------------------";
    cout << "\nOh no, there has been a hurricane in the SE region!" << endl;
    cout << "All properties down 50% in this region" << endl;
    for(int i = 0; i < numProps; i++){
        if(pOwned[i].getLocation() == "SE"){
            cout << "\nYour property " << pOwned[i].getPropertyType() << " was hit hard. Property value down 50%" << endl;
            pOwned[i].setPropertyValue(pOwned[i].getPropertyValue() * 0.5);
        }
    }
    for(int i = 0; i < 9; i++){
        if(!p[i]->isOwned() && p[i]->getLocation() == "SE"){
            p[i]->setPropertyValue(p[i]->getPropertyValue() * 0.5);
        }
    }
    return *this;
}

/********************************************************************************************************
 * Function: tornado
 * Description: adjust player property values as well as all property values based on the event
 * @param p all properties
 * @return this
 */
Player &Player::tornado(Property **p) {
    cout << "\n----------------------------------------";
    cout << "\nOh no, there has been a tornado in the Midwest region!" << endl;
    cout << "All properties down 30% in this region" << endl;
    for(int i = 0; i < numProps; i++){
        if(pOwned[i].getLocation() == "Midwest"){
            cout << "\nYour property " << pOwned[i].getPropertyType() << " was hit hard. Property value down 30%" << endl;
            pOwned[i].setPropertyValue(pOwned[i].getPropertyValue() * 0.7);
        }
    }
    for(int i = 0; i < 9; i++){
        if(p[i]->getLocation() == "Midwest"){
            p[i]->setPropertyValue(p[i]->getPropertyValue() * 0.7);
        }
    }
    return *this;
}

/********************************************************************************************************
 * Function: earthquake
 * Description: adjust player property values as well as all property values based on the event
 * @param p all properties
 * @return this
 */
Player &Player::earthquake(Property **p) {
    cout << "\n----------------------------------------";
    cout << "\nOh no, there has been a earthquake in the NW region!" << endl;
    cout << "All properties down 10% in this region" << endl;
    for(int i = 0; i < numProps; i++){
        if(pOwned[i].getLocation() == "NW"){
            cout << "\nYour property " << pOwned[i].getPropertyType() << " was hit hard. Property value down 10%" << endl;
            pOwned[i].setPropertyValue(pOwned[i].getPropertyValue() * 0.9);
        }
    }
    for(int i = 0; i < 9; i++){
        if(p[i]->getLocation() == "NW"){
            p[i]->setPropertyValue(p[i]->getPropertyValue() * 0.9);
        }
    }
    return *this;
}

/********************************************************************************************************
 * Function: wildfire
 * Description: adjust player property values as well as all property values based on the event
 * @param p all properties
 * @return this
 */
Player &Player::wildfire(Property **p) {
    cout << "\n----------------------------------------";
    cout << "\nOh no, there has been a wildfire in the SW region!" << endl;
    cout << "All properties down 25% in this region" << endl;
    for(int i = 0; i < numProps; i++){
        if(pOwned[i].getLocation() == "SW"){
            cout << "\nYour property " << pOwned[i].getPropertyType() << " was hit hard. Property value down 25%" << endl;
            pOwned[i].setPropertyValue(pOwned[i].getPropertyValue() * 0.75);
        }
    }
    for(int i = 0; i < 9; i++){
        if(p[i]->getLocation() == "SW"){
            p[i]->setPropertyValue(p[i]->getPropertyValue() * 0.75);
        }
    }
    return *this;
}

/********************************************************************************************************
 * Function: stockMarketCrash
 * Description: adjust player property values as well as all property values based on the event
 * @param p all properties
 * @return this
 */
Player &Player::stockMarketCrash(Property **p) {
    cout << "\n----------------------------------------";
    cout << "\nOh no, there has been a stock market crash!" << endl;
    cout << "\nAll properties are down 30% in value" << endl;
    for(int i = 0; i < numProps; i++){
        pOwned[i].setPropertyValue(pOwned[i].getPropertyValue() * 0.7);
    }
    for(int i = 0; i < 9; i++){

        p[i]->setPropertyValue(p[i]->getPropertyValue() * 0.7);

    }
    return *this;
}

/********************************************************************************************************
 * Function: gentrification
 * Description: adjust player property values as well as all property values based on the event
 * @param p all properties
 * @return this
 */
Player &Player::gentrification(Property **p) {
    cout << "\n----------------------------------------";
    cout << "\nWoohoo for gentrification!" << endl;
    cout << "\nAll properties are up 20% in value" << endl;
    for(int i = 0; i < numProps; i++){
        pOwned[i].setPropertyValue(pOwned[i].getPropertyValue() + (pOwned[i].getPropertyValue() * 0.2));
    }
    for(int i = 0; i < 9; i++){
        p[i]->setPropertyValue(p[i]->getPropertyValue() + (p[i]->getPropertyValue() * 0.2));
    }

    return *this;
}










