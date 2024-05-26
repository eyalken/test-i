# create discount system
# no need to serialze to/from DB - 
# never change for each product seperatly - create rules
# first roll 10% discount for all products
# change the structure just once (not in secod phase) 
# no cart 

public class Product {

    private String name;
    private int id;
    private double price;

    public Product(String name, int id, double price) {
        this.name = name;
        this.id = id;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    // No implementation needed for visualizeAtHome in Java

}

class ClothesProduct extends Product {

    private boolean isNew;

    public ClothesProduct(String name, int id, double price, boolean isNew) {
        super(name, id, price);
        this.isNew = isNew;
    }

    public boolean getIsNew() {
        return isNew;
    }

    public void setIsNew(boolean isNew) {
        this.isNew = isNew;
    }
}

class FurnitureProduct extends Product {

    private double height;
    private double weight;
    private double width;

    public FurnitureProduct(String name, int id, double price, double height, double weight, double width) {
        super(name, id, price);
        this.height = height;
        this.weight = weight;
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }
}

class VegetablesProduct extends Product {

    private double freshness;

    public VegetablesProduct(String name, int id, double price, double freshness) {
        super(name, id, price);
        this.freshness = freshness;
    }

    public double getFreshness() {
        return freshness;
    }

    public void setFreshness(double freshness) {
        this.freshness = freshness;
    }
}

class MilkProduct extends Product {

    public MilkProduct(String name, int id, double price) {
        super(name, id, price);
    }
}

public class DiscountSystem {

    public static void main(String[] args) {
        Map<Integer, Product> products = new HashMap<>();
        products.put(12345, new FurnitureProduct("3 Legs Chair", 12345, 100, 10, 101, 20));
        products.put(12346, new FurnitureProduct("Sofa - Black", 12346, 200, 10, 101, 20));
        products.put(12347, new FurnitureProduct("Sofa - Red ", 12347, 250, 10, 101, 20));
        products.put(12348, new FurnitureProduct("Table - Vintage", 12348, 100, 10, 101, 20));
        products.put(12349, new ClothesProduct("T-shirt", 12349, 200, true));

        for (Product product : products.values()) {
            System.out.println("The name of the product is now " + product.getName() + ", price is: " + product.getPrice());
            // Implement discount logic here (e.g., product.setPrice(product.getPrice() * 0.9); for 10% discount)
        }
    }
}
