#include "Pizza.h"
#include "PizzaBuilder.h"
#include "HawaiianPizzaBuilder.h"
#include "SpicyPizzaBuilder.h"
#include "Waiter.h"

// A customer ordering two pizza.
int main()
{ 
    Waiter waiter;
 
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    waiter.SetPizzaBuilder (&hawaiianPizzaBuilder);
    waiter.ConstructPizza();
    std::auto_ptr<Pizza> pizza = waiter.GetPizza();
    pizza->ShowPizza();
 
    SpicyPizzaBuilder spicyPizzaBuilder;
    waiter.SetPizzaBuilder(&spicyPizzaBuilder);
    waiter.ConstructPizza();
    pizza = waiter.GetPizza();
    pizza->ShowPizza();
 
    return EXIT_SUCCESS;
}
