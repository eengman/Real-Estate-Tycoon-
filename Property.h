

#ifndef REALESTATEGAME_PROPERTY_H
#define REALESTATEGAME_PROPERTY_H

#include <iostream>
#include <string>
#include "Tenant.h"

using namespace std;

class Property: public Tenant{
protected:
    string propType;
    int propertyValue;
    string location;
    int mortgage;
    int propertyTax;
    int numTenants;
    bool owned;
    Tenant* tenants;
    int mortgageDuration;
    bool sold;

public:
    Property(int pV, string loc, int m, int pT, Tenant* t, string pType);
    Property();
    ~Property();
    Property(const Property &p);
    Property &operator=(const Property &p);
    void setPropertyValue(int);
    int getPropertyValue() const;
    void setLocation(string);
    string getLocation() const;
    void setMortgage(int);
    int getMortgage() const;
    void setPropertyTax(double);
    double getPropertyTax() const;
    void setNumTenants(int);
    int getNumTenants() const;
    string getPropertyType() const;
    bool isOwned() const;
    void setOwned(bool o);
    void setPropertyType(string propType);
    void setSold(bool s);
    bool getSold() const;


    virtual void toString();


};

#endif //REALESTATEGAME_PROPERTY_H
