#include <iostream>
using namespace std;

class Order {
protected:
    static int p_hamburger;
    static int p_potato;
    static int p_drink;

    int hamburger;
    int potato;
    int drink;
    int total;

public:
    Order(); // コンストラクタ
    static void Set_p_hamburger(int);
    static void Set_p_potato(int);
    static void Set_p_drink(int);
    void Set_hamburger(int);
    void Set_potato(int);
    void Set_drink(int);

    virtual void Cal_Total(); // 仮想関数として宣言
    void Disp_Total();
};

// 静的メンバ変数の初期化
int Order::p_hamburger;
int Order::p_potato;
int Order::p_drink;

// コンストラクタ
Order::Order() : hamburger(0), potato(0), drink(0), total(0) {}

void Order::Set_p_hamburger(int val) {
    p_hamburger = val;
}

void Order::Set_p_potato(int val) {
    p_potato = val;
}

void Order::Set_p_drink(int val) {
    p_drink = val;
}

void Order::Set_hamburger(int val) {
    hamburger = val;
}

void Order::Set_potato(int val) {
    potato = val;
}

void Order::Set_drink(int val) {
    drink = val;
}

void Order::Cal_Total() {
    total = p_hamburger * hamburger + p_potato * potato + p_drink * drink;
}

void Order::Disp_Total() {
    cout << "Payment amount: " << total << " yen" << endl;
}

// NewOrderクラス
class NewOrder : public Order {
protected:
    static int p_cheeseburger;
    int cheeseburger;

public:
    NewOrder(); // コンストラクタ
    static void Set_p_cheeseburger(int);
    void Set_cheeseburger(int);
    void Cal_Total() override; // Cal_Totalをオーバーライド
};

// 静的メンバ変数の初期化
int NewOrder::p_cheeseburger;

// コンストラクタ
NewOrder::NewOrder() : cheeseburger(0) {}

void NewOrder::Set_p_cheeseburger(int val) {
    p_cheeseburger = val;
}

void NewOrder::Set_cheeseburger(int val) {
    cheeseburger = val;
}

void NewOrder::Cal_Total() {
    total = 0;  // total を 0 に初期化
    Order::Cal_Total();
    total += p_cheeseburger * cheeseburger;
}


// メイン関数
int main() {
    // 価格設定
    Order::Set_p_hamburger(200);
    Order::Set_p_potato(100);
    Order::Set_p_drink(150);
    NewOrder::Set_p_cheeseburger(250);

    NewOrder order;
    int num;

    // 各商品の個数をユーザから入力
    cout << "Enter the number of hamburgers: ";
    cin >> num;
    order.Set_hamburger(num);

    cout << "Enter the number of potatoes: ";
    cin >> num;
    order.Set_potato(num);

    cout << "Enter the number of drinks: ";
    cin >> num;
    order.Set_drink(num);

    cout << "Enter the number of cheeseburgers: ";
    cin >> num;
    order.Set_cheeseburger(num);

    // 支払額を計算して表示
    order.Cal_Total();
    order.Disp_Total();

    return 0;
}
