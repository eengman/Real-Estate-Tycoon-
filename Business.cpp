

#include "Business.h"

/**
 * Constructor for the Business class
 * @param pV propertyValue
 * @param loc location
 * @param m mortgage
 * @param pT propertyTax
 * @param t tenant object
 * @param type propertyType
 */
Business::Business(int pV, string loc, int m, double pT, Tenant *t, string type) {
    propType = type;
    propertyValue = pV;
    location = loc;
    mortgage = m;
    propertyTax = pT;
    tenants = t;
}

/**
 * getter for the number of spaces in the business complex
 * @return number of spaces
 */
int Business::getNumSpaces() const {
    return numSpaces;
}

/**
 * getter for the size of the space
 * @return size of type string
 */
string Business::getSpaceSize() const {
    return spaceSize[rand() % 5 + 1];
}

/**
 * setter for number of tenants
 * @param n number of tenants
 */
void Business::setNumTenants(int n) {
    Property::setNumTenants(n);
}




