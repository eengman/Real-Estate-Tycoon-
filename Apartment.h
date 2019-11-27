
#ifndef REALESTATEGAME_APARTMENT_H
#define REALESTATEGAME_APARTMENT_H

#include "Property.h"
#include "Tenant.h"

class Apartment: public Property{

protected:
    Tenant * tenants;
    int tenantNum;

public:
    Apartment(int pV, string loc, int m, double pT, Tenant* tenant, string type);
    Apartment(): Property(){};
    virtual void setNumTenants(int n);

};

#endif //REALESTATEGAME_APARTMENT_H
