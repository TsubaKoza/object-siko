class Order:
    """ハンバーガー店のオーダーと支払額の計算・表示"""

    # クラス変数（初期価格設定）
    __p_hamburger = 200
    __p_poteto = 180
    __p_drink = 150

    @classmethod
    def set_p_hamburger(cls, price):
        if isinstance(price, int) and price > 0:
            cls.__p_hamburger = price

    @classmethod
    def set_p_poteto(cls, price):
        if isinstance(price, int) and price > 0:
            cls.__p_poteto = price

    @classmethod
    def set_p_drink(cls, price):
        if isinstance(price, int) and price > 0:
            cls.__p_drink = price

    @classmethod
    def get_p_hamburger(cls):
        return cls.__p_hamburger

    @classmethod
    def get_p_poteto(cls):
        return cls.__p_poteto

    @classmethod
    def get_p_drink(cls):
        return cls.__p_drink

    def __init__(self, hamburger=0, poteto=0, drink=0):
        self.hamburger = hamburger
        self.poteto = poteto
        self.drink = drink
        self.__total = 0

    @property
    def hamburger(self):
        return self.__hamburger

    @hamburger.setter
    def hamburger(self, value):
        self.__hamburger = value if isinstance(value, int) and value >= 0 else 0

    @property
    def poteto(self):
        return self.__poteto

    @poteto.setter
    def poteto(self, value):
        self.__poteto = value if isinstance(value, int) and value >= 0 else 0

    @property
    def drink(self):
        return self.__drink

    @drink.setter
    def drink(self, value):
        self.__drink = value if isinstance(value, int) and value >= 0 else 0

    def cal_total(self):
        self.__total = (
            self.hamburger * self.__class__.__p_hamburger +
            self.poteto * self.__class__.__p_poteto +
            self.drink * self.__class__.__p_drink
        )

    def disp_total(self):
        print(f"Order Details:\n  Hamburger: {self.hamburger} \n  Poteto: {self.poteto} \n  Drink: {self.drink} \nTotal payment: {self.__total} yen")

# テストコード
order = Order(hamburger=1, poteto=1, drink=1)
order.cal_total()
order.disp_total()

Order.set_p_hamburger(300)
order.hamburger = 2
order.poteto = 2
order.drink = 2
order.cal_total()
order.disp_total()

order.hamburger = 2
order.poteto = -1
order.drink = '二個'
order.cal_total()
order.disp_total()

order1 = Order(hamburger=1, poteto=1, drink=1)
order1.cal_total()
order1.disp_total()
