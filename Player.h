
#ifndef REALESTATEGAME_PLAYER_H
#define REALESTATEGAME_PLAYER_H
#include "Property.h"
#include "House.h"

class Player{
private:
    string name;
    Property* pOwned;
    int bankAccount = 500000;
    int numProps;

public:
    // constructors and overloaded
    Player();
    Player(const Player& p);
    Player& operator= (const Player& p);
    ~Player();

    // accessors and mutators
    void setName(string n);
    string getName() const;
    void addProperty(Property &p);
    Player& sellProperty(Player &player, Property &p);
    int getBankAccount() const;
    Property* getProperties() const;
    int getNumProps() const;
    void updatePurchase(int propValue);
    void updateSell(int propValue);

    // random events
    Player& hurricane(Property **p);
    Player& tornado(Property **p);
    Player& earthquake(Property **p);
    Player& wildfire(Property **p);
    Player& stockMarketCrash(Property **p);
    Player& gentrification(Property **p);

};

#endif //REALESTATEGAME_PLAYER_H
