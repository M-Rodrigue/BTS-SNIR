#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

// Information sur les variables
// nom de la variable | type | description

int main()
{
    cout << "Billing application" << endl << endl;

    // consummer | char | name of the consumer
    char consumer[30];
    cout << "Enter the name of the consumer : ";
    cin >> consumer;

    // product | char | name of the product
    char product[30];
    cout << "Enter the name of the product : ";
    cin >> product;

    // quantity | int | quantity of the product
    int quantity;
    cout << "Enter the quantity : ";
    cin >> quantity;

    // price | double | price of the product without the VAT
    double price;
    cout << "Enter the price without the VAT : ";
    cin >> price;
    cout << endl;

    // pourcentVAT | double | pourcent of the VAT
    double pourcentVAT;
    cout << "Choose the exact pourcent of VAT : " << endl;
    cout << "1 = 20%" << endl;
    cout << "2 = 10%" << endl;
    cout << "3 = 5.5%" << endl;
    cout << "4 = 2.1%" << endl;

    // car | char | save the character
    char car = getch();
    cin >> car;
    switch (car) {
    case '1':
        pourcentVAT = 20;
        break;
    case '2':
        pourcentVAT = 10;
        break;
    case '3':
        pourcentVAT = 5.5;
        break;
    case '4':
        pourcentVAT = 2.1;
        break;
    }

    // totalPrice | double | calculate the total price without VAT
    double totalPrice = quantity*price;

    // totalVAT | double | calculate the total VAT
    double totalVAT = totalPrice*pourcentVAT/100;

    // totalPriceVAT | double | calculate the total price with VAT
    double totalPriceVAT = totalPrice+(pourcentVAT/100*totalPrice);

    // billingFile | ofstream | create the billing file with all informations
    ofstream billingFile("Billing.txt");
    billingFile << "Compagnie DORIAN-CFA" << endl;
    billingFile << "74 av. Philippe Auguste" << endl;
    billingFile << "75011 PARIS" << endl;
    billingFile << "N. Siret 54678-1234" << endl << endl;
    billingFile << "Consumer : " << consumer << endl << endl;
    billingFile << "Product : " << product << " | Qantity : " << quantity << " | Price without VAT : " << price << "€" << " | Total price without VAT : " << totalPrice << "€" << " | Total price : " << totalPriceVAT << "€" << endl << endl;
    billingFile << "TOTAL TO PAY ......... " << totalPriceVAT << "€" << endl;
    billingFile << "VAT " << "(" << pourcentVAT << "%)" << " ............ " << totalVAT << "€";
    billingFile.close();

    return 0;
}
