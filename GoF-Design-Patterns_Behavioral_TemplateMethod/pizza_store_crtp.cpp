#include <iostream>
#include <type_traits>

template <typename Derived>
class PizzaStore
{
public:
    virtual ~PizzaStore() = default;

    void MakePizza()
    {
        auto& derived = static_cast<Derived&>(*this);
        derived.MakeDough_();
        derived.PutTopping_();
        derived.BakePizza_();
    }
};

class DeliciousPizzaStore : public PizzaStore<DeliciousPizzaStore>
{
    friend class PizzaStore<DeliciousPizzaStore>;

private:
    void MakeDough_()
    {
        std::cout << "Make delicious dough!" << std::endl;
    }

    void PutTopping_()
    {
        std::cout << "Put delicious topping!" << std::endl;
    }

    void BakePizza_()
    {
        std::cout << "Bake pizza in an expensive oven!" << std::endl;
    }
};

class PoorPizzaStore : public PizzaStore<PoorPizzaStore>
{
    friend class PizzaStore<PoorPizzaStore>;

private:
    void MakeDough_()
    {
        std::cout << "Make poor dough!" << std::endl;
    }

    void PutTopping_()
    {
        std::cout << "Put poor topping!" << std::endl;
    }

    void BakePizza_()
    {
        std::cout << "Bake pizza in a cheap oven!" << std::endl;
    }
};


int main()
{
    DeliciousPizzaStore deliciousPizzaStore;
    PoorPizzaStore poorPizzaStore;

    deliciousPizzaStore.MakePizza();
    std::cout << "----------------------------" << std::endl;
    poorPizzaStore.MakePizza();
}
