#include <string>
#include <iostream>
#include <ctime>
#include <time.h>

class ProductBase {
protected:
    float price;
    std::string name;
    int id;

public:
    ProductBase(float price,   std::string  name , int id) : price(price), name(name), id(id) {}
    virtual ~ProductBase() {}

    virtual float getPrice() const { return price; }
    virtual void setPrice(float price) { this->price = price; }

    virtual std::string getName() const { return name; }
    virtual void setName(std::string name) { this->name = name; }

    virtual int getId() const { return id; }
    virtual void setId(int id) { this->id = id; }

    virtual std::string toString() const {
        return std::string("productBase{") +
            "price=" + std::to_string(price) +
            ", name='" + name + '\'' +
            ", id=" + std::to_string(id) +
            '}';
    }
};

class ClothesProduct : public ProductBase {
private:
    bool brand_new;

public:
    ClothesProduct(float price, std::string name, int id, bool brand_new) : ProductBase(price, name, id), brand_new(brand_new) {}

    bool isBrandNew() const { return brand_new; }
    void setBrandNew(bool brand_new) { this->brand_new = brand_new; }

    std::string toString() const  {
        return std::string("clothesProduct{") +
            ProductBase::toString() +
            ", brand_new=" + std::to_string(brand_new) +
            '}';
    }
    virtual ~ClothesProduct(){}
};

class FurnitureProduct : public ProductBase {
private:
    float width;
    float height;
    float weight;

public:
    FurnitureProduct(float price, std::string name, int id, float width, float height, float weight) : ProductBase(price, name, id), width(width), height(height), weight(weight) {}

    float getWidth() const { return width; }
    void setWidth(float width) { this->width = width; }

    float getHeight() const { return height; }
    void setHeight(float height) { this->height = height; }

    float getWeight() const { return weight; }
    void setWeight(float weight) { this->weight = weight; }

    std::string toString() const  {
        return "furnitureProduct{" +
            ProductBase::toString() +
            ", width=" + std::to_string(width) +
            ", height=" + std::to_string(height) +
            ", weight=" + std::to_string(weight) +
            '}';
    }
    virtual ~FurnitureProduct(){}
};

class VegetablesProduct : public ProductBase {
private:
    std::time_t  from_time;

public:
    VegetablesProduct(float price, std::string name, int id, std::time_t from_time) : ProductBase(price, name, id), from_time(from_time) {}

    std::time_t  getFromTime() const { return from_time; }
    void setFromTime(std::time_t  from_time) { this->from_time = from_time; }

    int freshness() const {
       
        return (std::time(nullptr) - from_time) / (24 * 60 * 60);
    }

    std::string toString() const  {
        return "vegetablesProduct{" +
            ProductBase::toString() +
            ", freshness ='" + std::to_string (freshness()) + '\'' +
            '}';
    }
    ~VegetablesProduct(){}
};

class MilkProduct : public ProductBase {
public:
    MilkProduct(float price, std::string name, int id) : ProductBase(price, name, id) {}

    std::string toString() const  {
        return "milkProduct{" +
            ProductBase::toString() +
            '}';
    }
    virtual ~MilkProduct(){}
};





int main() {
    // Create a new clothesProduct object
    ClothesProduct my_clothes_product(100.0f, std::string("My Clothes Product"), 12345, true);

    // Get the price of the clothesProduct object
    float price = my_clothes_product.getPrice();

    // Set the price of the clothesProduct object
    my_clothes_product.setPrice(200.0f);

    // Get the name of the clothesProduct object
    std::string name = my_clothes_product.getName();

    // Set the name of the clothesProduct object
    my_clothes_product.setName("My New Clothes Product");

    // Get the brand new status of the clothesProduct object
    bool brand_new = my_clothes_product.isBrandNew();

    // Set the brand new status of the clothesProduct object
    my_clothes_product.setBrandNew(false);
    std::cout << my_clothes_product.toString() << std::endl;


    VegetablesProduct vegtable(100.0f, std::string("Tomato"), 12347,std::time(nullptr)- 3* 24 * 60 * 60 );
    std::cout << vegtable.toString() << std::endl;;
    // // ...

    return 0;
}