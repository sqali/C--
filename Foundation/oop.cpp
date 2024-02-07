#include <iostream>
#include <string>

using namespace std;


// here we have defined the class rectangle
class rectangle
{
    private:
        int length;
        int breadth;
    public:
        void set_dimensions(int l, int b)
        {
            length = l;
            breadth = b;
        }
        int calculate_area()
        {
            return length*breadth;
        }
};

class animal
{
    protected:
        string name;
    public:
        void setName(string n) // This function cannot be used by the dog class the name variable is protected in the animal class, if it gets changed to public then you can use it
        {
            name = n;
        }
    virtual void sound()
    {
        cout << "Animal sound" << endl;
    }
    
};

class Dog : public animal // Dog class inherits the cnimal class publicly that is why
{
    public:
        void sound() override // here the sound function of the animal class is being overriden by the dog class
        {
            cout << "Bark" << endl;
        }
};

// Basically private and protected functions defined in a class cannot be accessed from outside the class
// They can be used within the class itself

int main()
{

    rectangle rect;
    rect.set_dimensions(45, 10);

    std::cout << rect.calculate_area() << " <- This is the area of the rectangle" << endl;

    Dog my_dog;
    my_dog.sound();

}

/* Notes on OOP

Best Practices:
    Encapsulation: Hide implementation details, expose only necessary functionalities.
    Inheritance: Use it judiciously to model "is-a" relationships.
    Polymorphism: Utilize virtual functions to enable runtime polymorphism.
    Composition over Inheritance: Prefer composition when possible to avoid complex inheritance hierarchies.
    Consistency in Naming: Follow naming conventions for classes, functions, and variables.
    Avoid Global Data: Minimize the use of global variables to prevent unintended dependencies.
Benefits of OOP in C++:
    Modularity: Code is organized into manageable and reusable modules.
    Abstraction: Focus on essential details, hide unnecessary complexities.
    Encapsulation: Data is protected and accessed through well-defined interfaces.
    Inheritance: Promotes code reuse and fosters hierarchical relationships.
    Polymorphism: Enables flexible behavior through overriding and runtime binding.

*/