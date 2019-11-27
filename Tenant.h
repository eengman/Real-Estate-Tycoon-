

#ifndef REALESTATEGAME_TENANT_H
#define REALESTATEGAME_TENANT_H
#include <iostream>


class Tenant {

protected:
    int maxRent;
    int agreement;
    int rent;
    int tenantNum;
    Tenant * tenant;
    int* ten;

public:
    Tenant();
    Tenant(int maxRent, int agreement, int rent, int tenantNum);
    Tenant(int tenantNum);
    Tenant(const Tenant &t);
    ~Tenant();

    void setMaxRent(int maxRent);
    void setAgreement(int agreement);
    void setRent(int rent);
    void increaseRent(int moreRent);
    void decreaseRent(int lessRent);


    int getMaxRent() const;
    int getAgreement() const;
    int getRent() const;
    int getNumTenants() const;


};


#endif //REALESTATEGAME_TENANT_H
