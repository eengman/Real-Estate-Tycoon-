
#include <iostream>

using namespace std;
#include "House.h"

/**
 * Constructor for the House class
 * @param pV propertyValue
 * @param loc location
 * @param m mortgage
 * @param pT propertyTax
 * @param t tenant object
 * @param type propertyType
 */
House::House (int pV, string loc, int m, double pT, Tenant * t, string type) {
    propType = type;
    propertyValue = pV;
    location = loc;
    mortgage = m;
    propertyTax = pT;
    tenants = t;
    numTenants = 1;
}

/**
 * Initializes the tenant (only initializes 1 tenant as house can only have 1 tenant)
 */
void House::initializeTenants() {
    tenants = new Tenant[numTenants];
    tenants[0].setAgreement(rand() % 5 + 1);
    tenants[0].setMaxRent(rand() % 5000 + 500);
    tenants[0].setRent(rand() % tenants[0].getMaxRent() + 500);
}

/**
 * setter for the number of tenants
 * @param n
 */
void House::setNumTenants(int n) {
    Property::setNumTenants(n);
}
