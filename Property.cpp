
#include "Property.h"

/**
 * This is the constructor for the Property Class
 * @param pV propertyValue
 * @param loc location
 * @param m mortgage
 * @param pT propertyTax
 * @param t tenant object
 * @param pType propertyType
 */
Property::Property(int pV, string loc, int m, int pT, Tenant* t, string pType) {
    propType = pType;
    propertyValue = pV;
    location = loc;
    mortgage = m;
    propertyTax = pT;
    tenants = t;
    owned = false;
    sold = false;
}

/**
 * This is the default constructor for the property class
 */
Property::Property() {
    propertyValue = 0;
    location = "";
    mortgage = 0;
    propertyTax = 0.0;
    numTenants = 0;
    owned = false;
}

/**
 * This is the destructor for the Property class
 *  I couldn't figure out how to get this to work without crashing
 *  my program
 */
Property::~Property() {
    cout << "Property destroyed" << endl;
}

/**
 * Setter for property value
 * @param pV
 */
void Property::setPropertyValue(int pV) {
    propertyValue = pV;
}

/**
 * Getter for property value
 * @return propertyValue
 */
int Property::getPropertyValue() const {
    return propertyValue;
}


/**
 * Setter for location
 * @param loc
 */
void Property::setLocation(string loc) {
    this->location = loc;
}
/**
 * getter for location
 * @return location
 */
string Property::getLocation() const {
    return location;
}

/**
 * setter for mortgage
 * @param m
 */
void Property::setMortgage(int m) {
    mortgage = m;
}

/**
 * getter for mortgage
 * @return
 */
int Property::getMortgage() const {
    return mortgage;
}

/**
 * setter for property tax
 * @param pT
 */
void Property::setPropertyTax(double pT) {
    propertyTax = pT;
}

/**
 * getter for property tax
 * @return propertyTax
 */
double Property::getPropertyTax() const {
    return propertyTax;
}

/**
 * setter for number of tenants
 * @param t
 */
void Property::setNumTenants(int t) {
    numTenants = t;
}

/**
 * getter for number of tenants
 * @return numTenants
 */
int Property::getNumTenants() const {
    return numTenants;
}

/**
 * toString
 */
void Property::toString() {

    cout << "Property value: " << propertyValue << endl;
    cout << "Location: " << location << endl;
    cout << "Mortgage: " << mortgage << endl;
    cout << "Property Tax: " << propertyTax << "%" << endl;
    cout << "Number of Tenants: " << numTenants << endl;
    cout << endl;
}
/**
 * getter for propertyType
 * @return name of property
 */
string Property::getPropertyType() const {
    return propType;
}

/**
 * This is the copy constructor for the Property class
 * @param p
 */
Property::Property(const Property &p) {
    this->propertyValue = p.propertyValue;
    this->propType = p.propType;
    this->location = p.location;
    this->mortgage = p.mortgage;
    this->numTenants = p.numTenants;
    this->propertyTax = p.propertyTax;
    this->owned = p.owned;
    this->tenants = p.tenants;
    this->tenant = p.tenant;

}
/**
 * This is the overloaded assignment operator for the property class
 * @param p
 * @return this
 */
Property &Property::operator=(const Property &p) {
    if(&p != this){
        propType = p.getPropertyType();
        propertyValue = p.getPropertyValue();
        location = p.getLocation();
        mortgage = p.getMortgage();
        propertyTax = p.getPropertyTax();
        numTenants = p.getNumTenants();
        owned = p.owned;
        tenants = p.tenants;
        tenant = p.tenant;
    }

    return *this;
}
/**
 * getter for whether the property is owned by the player
 * @return bool owned
 */
bool Property::isOwned() const {
    return owned;
}
/**
 * setter for when the player adds a property
 * @param o
 */
void Property::setOwned(bool o) {
    owned = o;
}
/**
 * setter for the property type
 * @param pType
 */
void Property::setPropertyType(string pType) {
    this->propType = pType;
}

void Property::setSold(bool s) {
    sold = s;
}

bool Property::getSold() const {
    return sold;
}










