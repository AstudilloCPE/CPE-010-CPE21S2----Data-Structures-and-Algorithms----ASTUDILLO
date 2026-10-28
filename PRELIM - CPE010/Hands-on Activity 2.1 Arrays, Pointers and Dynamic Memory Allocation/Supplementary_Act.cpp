#include <iostream>
#include <string>

class Fruits {
    private:
    std::string* Fruit_Name;
    int* Fruit_Price;
    int* Fruit_Quantity;

    //Constructor
    public:
    Fruits(std::string NewFruit_Name = "Place_Holder", int NewFruit_Price = 5, int NewFruit_Quantity = 5) {
        Fruit_Name = new std::string(NewFruit_Name);
        Fruit_Price = new int(NewFruit_Price);
        Fruit_Quantity = new int(NewFruit_Quantity);

        std::cout << "Constructor Successfully Called." << std::endl;

    }

    // Deconstructor
    ~Fruits() {
        std::cout << "Destructor Successfully Called." << std::endl;
    }

    // Copy Constructor
    Fruits(const Fruits& NewFruit) {
        std::cout << "Copy Constructor Successfully Called." << std::endl;

        Fruit_Name = NewFruit.Fruit_Name;
        Fruit_Price = NewFruit.Fruit_Price;
        Fruit_Quantity = NewFruit.Fruit_Quantity;
    }

    // Copy Assignment Operator
    Fruits& operator=(const Fruits& NewFruit) {
        std::cout << "Copy Assignment Operator Successfully Called" << std::endl;

        if (this != &NewFruit) {

            delete Fruit_Name;
            delete Fruit_Price;
            delete Fruit_Quantity;

            Fruit_Name = new std::string(*NewFruit.Fruit_Name);
            Fruit_Price = new int(*NewFruit.Fruit_Price);
            Fruit_Quantity = new int(*NewFruit.Fruit_Quantity);
        }
        return *this;
    }

    // Display function
    void display() const {
        std::cout << *Fruit_Name << " PHP" << *Fruit_Price <<  " x" << *Fruit_Quantity << std::endl;
    }

    // Display Total Sum
    double Fruit_totalsum() {
        return (*Fruit_Price) * (*Fruit_Quantity);
    }

};

class Vegetables {
    private:
    std::string* Vegetable_Name;
    int* Vegetable_Price;
    int* Vegetable_Quantity;

    //Constructor
    public:
    Vegetables(std::string NewVegetable_Name = "Place_Holder", int NewVegetable_Price = 5, int NewVegetable_Quantity = 5) {
        Vegetable_Name = new std::string(NewVegetable_Name);
        Vegetable_Price = new int(NewVegetable_Price);
        Vegetable_Quantity = new int(NewVegetable_Quantity);

        std::cout << "Constructor Successfully Called." << std::endl;

    }

    // Deconstructor
    ~Vegetables() {
        std::cout << "Destructor Successfully Called." << std::endl;
    }

    // Copy Constructor
    Vegetables(const Vegetables& NewVegetable) {
        std::cout << "Copy Constructor Successfully Called." << std::endl;

        Vegetable_Name = NewVegetable.Vegetable_Name;
        Vegetable_Price = NewVegetable.Vegetable_Price;
        Vegetable_Quantity = NewVegetable.Vegetable_Quantity;
    }

    // Copy Assignment Operator
    Vegetables& operator=(const Vegetables& NewVegetable) {
        std::cout << "Copy Assignment Operator Successfully Called" << std::endl;

        if (this != &NewVegetable) {

            delete Vegetable_Name;
            delete Vegetable_Price;
            delete Vegetable_Quantity;

            Vegetable_Name = new std::string(*NewVegetable.Vegetable_Name);
            Vegetable_Price = new int(*NewVegetable.Vegetable_Price);
            Vegetable_Quantity = new int(*NewVegetable.Vegetable_Quantity);
        }
        return *this;
    }

    // Display function
     void display() const {
        std::cout << *Vegetable_Name << " PHP" << *Vegetable_Price <<  " x" << *Vegetable_Quantity << std::endl;
    }

        // Display Total Sum
    double Vegetable_totalsum() {
        return (*Vegetable_Price) * (*Vegetable_Quantity);

    }

};

int main() {
    Fruits* ShoppingList_Fruits[2];
    Vegetables* ShoppingList_Vegetables[2];

    ShoppingList_Fruits[0] = new Fruits("Apple", 10, 7);
    ShoppingList_Fruits[1] = new Fruits("Banana", 10, 8);

    ShoppingList_Vegetables[0] = new Vegetables("Brocolli", 60, 12);
    ShoppingList_Vegetables[1] = new Vegetables("Lettuce", 50, 10);

    for(int i = 0; i < 2; i++) {
        ShoppingList_Fruits[i] -> display();
        std::cout << "SubTotal for All Fruit/s: " << ShoppingList_Fruits[i] -> Fruit_totalsum() << std::endl;
    }
    for(int i = 0; i < 2; i++) {
        ShoppingList_Vegetables[i] -> display();
        std::cout << "SubTotal for All Vegetable/s: " << ShoppingList_Vegetables[i] -> Vegetable_totalsum() << std::endl;
    }

    double TotalofAllItems = 0;
    for(int i = 0; i < 2; i++) {
        TotalofAllItems += ShoppingList_Fruits[i]->Fruit_totalsum();
        TotalofAllItems += ShoppingList_Vegetables[i]->Vegetable_totalsum();
    }

    std::cout << "The Total for all items is: " << TotalofAllItems << std::endl;


    delete ShoppingList_Vegetables[1];
    ShoppingList_Vegetables[1] = nullptr;
    std::cout << "Item 2 Successfully Deleted." << std::endl;

    return 0;
}
