class Product:
    def __init__(self, name, id, price):
        self._name = name
        self._id = id
        self._price = price

    def get_name(self):
        return self._name

    def set_name(self, name):
        self._name = name

    def get_id(self):
        return self._id

    def set_id(self, id):
        self._id = id

    def get_price(self):
        return self._price

    def set_price(self, price):
        self._price = price

    def visualizeAtHome(self, photo):
        pass


class ClothesProducts(Product):
    def __init__(self, name, id, price, isNew):
        super().__init__(name, id, price)
        self._isNew = isNew

    def get_isNew(self):
        return self._isNew

    def set_isNew(self, isNew):
        self._isNew = isNew


class FurnitureProducts(Product):
    def __init__(self, name, id, price, height, weight, width):
        super().__init__(name, id, price)
        self._height = height
        self._weight = weight
        self._width = width

    def get_height(self):
        return self._height

    def set_height(self, height):
        self._height = height

    def get_weight(self):
        return self._weight

    def set_weight(self, weight):
        self._weight = weight

    def get_width(self):
        return self._width

    def set_width(self, width):
        self._width = width


class VegetablesProducts(Product):
    def __init__(self, name, id, price, freshness):
        super().__init__(name, id, price)
        self._freshness = freshness

    def get_freshness(self):
        return self._freshness

    def set_freshness(self, freshness):
        self._freshness = freshness


class MilkProducts(Product):
    def __init__(self, name, id, price):
        super().__init__(name, id, price)


products = {
    FurnitureProducts("3 Legs Chair", 12345, 100,10,101,20),
    FurnitureProducts("Sofa - Black", 12346, 200,10,101,20),
    FurnitureProducts("Sofa - Red ", 12347, 250,10,101,20),
    FurnitureProducts("Table - Vintage", 12348, 100,10,101,20),
    ClothesProducts("T-shirt", 12349, 200,True)
}

for product in products:
    print("The name of the product is now", product.get_name(), ",price is:", product.get_price())
