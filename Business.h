
#ifndef REALESTATEGAME_BUSINESS_H
#define REALESTATEGAME_BUSINESS_H

#include "Property.h"
#include "Tenant.h"

class Business: public Property{

protected:
    Tenant* tenants;
    int numSpaces;
    string locations[5] = {"SE", "NE", "Midwest", "SW", "NW"} ;
    string spaceSize[3] = {"Small", "Medium", "Large"};

public:
    Business(int pV, string loc, int m, double pT, Tenant* tenant, string type);
    Business(): Property(){};
    virtual void setNumTenants(int n);
    int getNumSpaces() const;
    string getSpaceSize() const;
};

#endif //REALESTATEGAME_BUSINESS_H
