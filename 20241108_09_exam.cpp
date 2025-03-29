#include <iostream>
using namespace std;

class Polygon {
public:
    // 各辺の長さをセットする仮想関数
    virtual void set_sides(double a, double b = 0, double c = 0) = 0;
    
    // 外周の長さを計算し表示する仮想関数
    virtual void perimeter() const = 0;
    
    // 面積を計算し表示する仮想関数
    virtual void area() const = 0;
};

class Triangle : public Polygon {
private:
    double base, height, side1, side2, side3;
public:
    // 三角形の3辺の長さをセット
    void set_sides(double a, double b, double c) override {
        if (a + b > c && b + c > a && c + a > b) {
            side1 = a;
            side2 = b;
            side3 = c;
            base = a;       // 任意の辺を底辺として選択
            height = 2 * area_by_heron() / base;
        } else {
            cout << "Error: Invalid triangle sides." << endl;
        }
    }

    // 外周の長さを計算し表示
    void perimeter() const override {
        double p = side1 + side2 + side3;
        cout << "Triangle perimeter: " << p << endl;
    }

    // 面積を計算し表示（ヘロンの公式の計算を関数として再利用）
    void area() const override {
        cout << "Triangle area: " << area_by_heron() << endl;
    }
    
private:
    // ヘロンの公式を使わずに三角形の面積を計算
    double area_by_heron() const {
        return (base * height) / 2;
    }
};

class Rectangle : public Polygon {
private:
    double length, width;
public:
    // 長辺と短辺の長さをセット
    void set_sides(double a, double b, double c = 0) override { // 3つ目の引数にデフォルト値を追加
        length = a;
        width = b;
    }

    // 外周の長さを計算し表示
    void perimeter() const override {
        double p = 2 * (length + width);
        cout << "Rectangle perimeter: " << p << endl;
    }

    // 面積を計算し表示
    void area() const override {
        double area = length * width;
        cout << "Rectangle area: " << area << endl;
    }
};

int main() {
    Triangle sankaku;
    Rectangle shikaku;

    sankaku.set_sides(4, 5, 6);
    sankaku.perimeter();
    sankaku.area();

    shikaku.set_sides(5, 7); // デフォルト引数を使用して 2 つの引数で呼び出し可能
    shikaku.perimeter();
    shikaku.area();

    return 0;
}
