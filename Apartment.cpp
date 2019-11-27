
#include "Apartment.h"

/**
 * this is the constructor for the Apartment class
 * @param pV propertyValue
 * @param loc location
 * @param m mortgage
 * @param pT propertyTax
 * @param t tenant object
 * @param type propertyType
 */
Apartment::Apartment(int pV, string loc, int m, double pT, Tenant *t, string type) {
    propType = type;
    propertyValue = pV;
    location = loc;
    mortgage = m;
    propertyTax = pT;
    tenants = t;
}

/**
 * setter for the number of tenants in the apartment
 * @param n number of tenants
 */
void Apartment::setNumTenants(int n) {
    Property::setNumTenants(n);
}

