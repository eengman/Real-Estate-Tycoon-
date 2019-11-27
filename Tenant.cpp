
#include "Tenant.h"

/**
 * This is the default constructor which initializes the values
 */
Tenant::Tenant() {
    maxRent = rand() % 5000 + 500;
    agreement = rand() % 5 + 1;
    rent = rand() % 5000 + 1;
    tenantNum = 1;
}

/**
 * This is the constructor which accepts values and initializes them
 * @param maxRent max rent a tenant can afford
 * @param agreement agreement value
 * @param rent rent to be paid
 * @param tNum tenant number
 */
Tenant::Tenant(int maxRent, int agreement, int rent, int tNum) {
    this->maxRent = maxRent;
    this->agreement = agreement;
    this->rent = rent;
    this->tenantNum = tNum;
}

/**
 * Creates a tenant object and sets the values
 * @param tenantNum
 */
Tenant::Tenant(int tenantNum) {
    tenant = new Tenant[tenantNum];
    for(int i = 0; i < tenantNum; i++){
        tenant[i].setAgreement(rand() % 5 + 1);
        tenant[i].setRent(rand() % 5000 + 500);
        tenant[i].setMaxRent(rand() % 5000 + 500);
    }
}

/**
 * copy constructor for Tenant class
 * @param t tenant object
 */
Tenant::Tenant(const Tenant &t) {
    this->maxRent = t.maxRent;
    this->agreement = t.agreement;
    this->rent = t.rent;
    this->tenantNum = t.tenantNum;
}

/**
 * destructor
 */
Tenant::~Tenant() {
    delete tenant;
    tenant = NULL;
}

/**
 * setter for the max rent
 * @param maxRent
 */
void Tenant::setMaxRent(int maxRent) {
    this->maxRent = maxRent;
}
/**
 * setter for the agreement value
 * @param agreement
 */
void Tenant::setAgreement(int agreement) {
    this->agreement = agreement;
}

/**
 * setter for the rent
 * @param rent
 */
void Tenant::setRent(int rent) {
    this->rent = rent;
}

/**
 * getter for the max rent
 * @return max rent
 */
int Tenant::getMaxRent() const {
    return maxRent;
}

/**
 * getter for the agreement value
 * @return agreement value
 */
int Tenant::getAgreement() const {
    return agreement;
}

/**
 * getter for the rent value
 * @return rent
 */
int Tenant::getRent() const {
    return rent;
}

/**
 * getter for the number of tenants
 * @return number of tenants
 */
int Tenant::getNumTenants() const {
    return tenantNum;
}

/**
 * Raises the rent for this specific tenant
 * @param moreRent
 */
void Tenant::increaseRent(int moreRent) {
    rent += moreRent;
}

/**
 * Lowers the rent for this specific tenant
 * @param lessRent
 */
void Tenant::decreaseRent(int lessRent) {
    rent -= lessRent;
}





