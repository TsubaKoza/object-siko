#include "NewOrder1.h"
#include "NewOrder2.h"
#include <iostream>
using namespace std;

class FinalOrder : public NewOrder1, public NewOrder2 {
  public:
    void Cal_Total() override;
    static void Set_Price();

    void Set_Hamburger(int num) { Set_hamburger(num); }
    void Set_Cheeseburger(int num) { Set_cheeseburger(num); }
    void Set_Fishburger(int num) { Set_fishburger(num); }
    void Set_Drink(int num) { Set_drink(num); }
    void Set_Potato(int num) { Set_potato(num); }
};

void FinalOrder::Cal_Total() {
   Order::Cal_Total();
   NewOrder1::Cal_Total();
   NewOrder2::Cal_Total();
}

void FinalOrder::Set_Price() {
   Set_p_hamburger(200);
   Set_p_potato(150);
   Set_p_drink(180);
   Set_p_cheeseburger(250);
   Set_p_fishburger(300);
}

int main() {
    FinalOrder order;
    order.Set_Price();

    int hamburger_qty, cheeseburger_qty, fishburger_qty, drink_qty, potato_qty;

    // Prompt the user to enter the quantity for each item
    cout << "Enter the quantity of hamburgers: ";
    cin >> hamburger_qty;
    order.Set_Hamburger(hamburger_qty);

    cout << "Enter the quantity of cheeseburgers: ";
    cin >> cheeseburger_qty;
    order.Set_Cheeseburger(cheeseburger_qty);

    cout << "Enter the quantity of fishburgers: ";
    cin >> fishburger_qty;
    order.Set_Fishburger(fishburger_qty);

    cout << "Enter the quantity of drinks: ";
    cin >> drink_qty;
    order.Set_Drink(drink_qty);

    cout << "Enter the quantity of potatoes: ";
    cin >> potato_qty;
    order.Set_Potato(potato_qty);

    // Calculate and display the total amount
    order.Cal_Total();
    order.Disp_Total();

    return 0;
}
