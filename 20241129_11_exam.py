class PrefData:
    """
    都道府県の男女別の平均身長と平均体重を管理するクラス
    """
    def __init__(self, pref: str, m_height: float, m_weight: float, f_height: float, f_weight: float) -> None:
        self.pref = pref
        self.m_height = m_height
        self.m_weight = m_weight
        self.f_height = f_height
        self.f_weight = f_weight

    def display_data(self) -> None:
        """
        データを表示するメソッド
        """
        print(f"{self.pref}: 男性 - 身長: {self.m_height}cm, 体重: {self.m_weight}kg, 女性 - 身長: {self.f_height}cm, 体重: {self.f_weight}kg")

    def set_m_height(self, m_height: float) -> None:
        """
        男性の平均身長を設定するメソッド
        """
        self.m_height = m_height
   
    def set_m_weight(self, m_weight: float) -> None:
        """
        男性の平均体重を設定するメソッド
        """
        self.m_weight = m_weight

    def set_f_height(self, f_height: float) -> None:
        """
        女性の平均身長を設定するメソッド
        """
        self.f_height = f_height

    def set_f_weight(self, f_weight: float) -> None:
        """
        女性の平均体重を設定するメソッド
        """
        self.f_weight = f_weight


# インスタンスの作成
kanagawa = PrefData("神奈川", 171.3, 61.2, 158.5, 51.9)
tokyo = PrefData("東京", 171.4, 62.2, 158.9, 51.7)
chiba = PrefData("千葉", 170.8, 61.6, 158.1, 52.4)

# インスタンス情報を表示
kanagawa.display_data()  # 神奈川のデータを表示
tokyo.display_data()     # 東京のデータを表示
chiba.display_data()     # 千葉のデータを表示

# メソッドを使った変更
kanagawa.set_m_height(171.0)
kanagawa.display_data()  

tokyo.set_m_weight(63.0)
tokyo.display_data()

chiba.set_f_height(159.0) 
chiba.set_f_weight(53.0)
chiba.display_data() 

