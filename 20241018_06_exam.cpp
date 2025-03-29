#include <iostream>
using namespace std;

class Order{
	private:
		int p_hamburger; // ハンバーガーの価格
		int p_potato;    // ポテトの価格
		int p_drink;     // ドリンクの価格

	public:
		int number;    // 注文No.
		int hamburger; // ハンバーガーの個数
		int potato;    // ポテトの個数
		int drink;     // ドリンクの個数
		int total;     // 支払金額

		void Set_Price();  // 各アイテムの価格を設定する関数
		void Cal_Total();  // 支払額を計算する関数
		void Disp_Total(); // 支払額を表示する関数
};

void Order::Set_Price() {
	// ハンバーガー200円、ポテト180円、ドリンク150円に設定
	p_hamburger = 200;
	p_potato = 180;
	p_drink = 150;
}

void Order::Cal_Total() {
	// 支払金額を計算する
	total = (p_hamburger * hamburger) + (p_potato * potato) + (p_drink * drink);
}

void Order::Disp_Total() {
	cout <<  "Payment amount: " << total << " yen\n";
}

int main() {
	Order o;
	
	// 各アイテムの価格を設定
	o.Set_Price();
	
	// ハンバーガー、ポテト、ドリンクの個数を入力
	cout << "Enter the number of hamburgers: ";
	cin >> o.hamburger;
	
	cout << "Enter the number of potatoes: ";
	cin >> o.potato;
	
	cout << "Enter the number of drinks: ";
	cin >> o.drink;
	
	// 支払額を計算
	o.Cal_Total();
	
	// 支払額を表示
	o.Disp_Total();
	
	return 0;
}
