

#ifndef REALESTATEGAME_HOUSE_H
#define REALESTATEGAME_HOUSE_H

#include "Property.h"
#include "Tenant.h"


class House: public Property{

protected:
    Tenant* tenants;

public:
    House(int pV, string loc, int m, double pT, Tenant *t, string type);
    House(): Property(){};
    virtual void setNumTenants(int n);
    void initializeTenants();

};
#endif //REALESTATEGAME_HOUSE_H
