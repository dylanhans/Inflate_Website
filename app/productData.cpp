#include <iostream>
#include <string>
// #include "date.cpp"

using namespace std;

class productData {
private:
    string productType;
    string productPrice;
    string productName;
    // Date dateOfPurchase;
public:
    productData(string, string, string);
    // productData(string, string, string, Date);
    string getProductType();
    string getProductPrice();
    string getProductName();
    // Date getDateOfPurchase();

    void setProductType(string);
    void setProductPrice(string);
    void setProductName(string);
    // void setDateOfPurchase(Date);
};

productData::productData(string PT, string PN, string PP){
    productType = PT, productName = PN, productPrice = PP;
}

// productData::productData(string PT, string PN, string PP) {
//     productType = PT, productName = PN, productPrice = PP;
//     // dateOfPurchase = dOP;
// }

string productData::getProductType() {
    string copy = productType;
    return copy;
}

string productData::getProductPrice() {
    string copy = productPrice;
    return copy;
}

string productData::getProductName() {
    string copy = productName;
    return copy;
}

// Date productData::getDateOfPurchase() {
//     Date copy = Date(dateOfPurchase.getMonth(), dateOfPurchase.getDay(), dateOfPurchase.getYear());
//     return copy;
// }

void productData::setProductType(string PT) { productType = PT; }

void productData::setProductPrice(string PP) { productPrice = PP; }

void productData::setProductName(string PN) { productName = PN; }

// void productData::setDateOfPurchase(Date dOP) { dateOfPurchase = dOP; }
