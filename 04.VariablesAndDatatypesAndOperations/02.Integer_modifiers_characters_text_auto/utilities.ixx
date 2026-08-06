module;

#include<SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<fmt/format.h>
#include<iostream>
#include<cmath>
#include<string>


export module utilities;

export void compute_distance(double x1, double y1, double x2, double y2) {
    
    //Don't change anything above this line
    //Your code will go below this line.
    
    //Compute the distance and store it in the distance variable, then print the message as requested
    double distance = std::sqrt(std::pow((x2 - x1),2) + std::pow((y2 - y1),2));
    std::cout << "The distance between (" << x1 << ", " << y1 << ") and ("
              << x2 << ", " << y2 << ") is: " << distance << '\n';
              
    //Your code will go above this line 
    //Don't change anything below this line
}

export void check_even_odd(int number) {
    
    //Don't change anything above this line
    //Your code will go below this line
    if(number%2 == 0)
        std::cout<<number<<" is even.\n";
    else
        std::cout<<number<<" is odd.\n";
    //You have access to a variable named number that may contain either an odd or even value.
    
    
    //Your code will go above this line 
    //Don't change anything below this line 
}

export int digit_sum(int number) {
    if (number < 10 || number > 99) {
        std::cout << "Error: Please enter a two-digit number.\n";
        return -1;
    }
    
    //You have access to a variable named number containing a two digit integer.
    //Your job is to  extract the tens digit and the units digit. Make the code valid according to the C++ rules you know now.
        
    //Don't change anything above this line
    //Your code will go below this line
    
    int tens = number/10;  // Extract the tens digit and store it in the tens variable.
    int ones = number%10;  // Extract the units digit and store it in the ones variable
    
    //Your code will go above this line 
    //Don't change anything below this line
    
    return tens + ones;
}

export void traffic_light(bool green_light) {
    std::cout << "Green light: " << green_light << "\n";
    
    //Don't change anything above this line
    //Your code will go below this line
    if(green_light)
        std::cout<<"GO!";
    else
        std::cout<<"Stop!";
    //Your code will go above this line 
    //Don't change anything below this line
}

export void Coding_Exercise_2()
{
    //Don't modify anything above this line
    //Your code will go below this line
    
    char character1('a');
    char character2('r');
    char character3('r');
    char character4('o');
    char character5('w');
    char value = ('A');
    
    //Your code will go above this line
    //Don't modify anything below this line

    std::cout << character1 << '\n';
    std::cout << character2 << '\n';
    std::cout << character3 << '\n';
    std::cout << character4 << '\n';
    std::cout << character5 << '\n';
    
    std::cout << "value: " << value << '\n';
    std::cout << "value(int): " << static_cast<unsigned int>(value) << '\n';
}

export void testing_unsigned_int()
{
      fmt::println("{}", std::log10(10000));

      std::cout<<std::ceil(7.7)<<'\n';

      int value {5};
      fmt::println("{}", value++);
      fmt::println("{}", value--);
      fmt::println("{}", (value += 5));

      int result = (6 + 3) * 8 - 9 / 3 - 2 + 5;
      fmt::println("result: {}", result);

      std::string a = "hello, ";
      std::string b = "World!";
      std::string* p_a = &a;

      fmt::println("a : {}", *p_a);
      a.append(b);
      fmt::println("appending...  :");
      fmt::println("a : {}", *p_a);


      auto x = 10ul;
      auto y = 3.14f;
      auto z = "Hello";
      //auto xx;


      unsigned int foo_1=-3;
    //unsigned int foo_2{-3}; //Compiler error: Narrowing conversion
      unsigned int foo_3(-4294967291);

      fmt::println("foo_1 : {}", foo_1);
      fmt::println("foo_2 : throws compiler error");
      fmt::println("foo_3 : {}", 0/-2);

      fmt::println("{}", static_cast<unsigned int>(char(65)));
}

export void assignment_initialization()
{
// Assignment Initialization

    int bike_count = 2;
    int truck_count = 7;
    int vehicle_count = bike_count + truck_count;
    int narrowing_conversions_assignment = 2.9; // Using int to store float
                                    // truncates the value after
                                    // the decimal

    fmt::println("Bike count: {}", bike_count);
    fmt::println("Truck count: {}", truck_count);
    fmt::println("Vehicle count: {}", vehicle_count);
    fmt::println("Narrowing conversions: {}", narrowing_conversions_assignment);
    fmt::println("sizeof int: {}", sizeof(int));
    fmt::println("sizeof truck_count: {}", sizeof(truck_count));

}

export void braced_initialization()
{
//Braced Initialization
    int elephant_count; // Not explicitly initialized

    int lion_count {}; // Initialized to zero

    int dog_count {20}; // Initialized to 20

    int cat_count {15}; // Initialized to 15

    int domesticated_animals {dog_count + cat_count};

    int new_number {lion_count};

    //int narrowing_conversion{2.9}; // Error: Brased initialization
                                   // does not allow implicit 
                                   // conversions
    
    fmt::println("Elephant count: {}", elephant_count);
    fmt::println("Lion count: {}", lion_count);
    fmt::println("Dog count: {}", dog_count);
    fmt::println("Cat count: {}", cat_count);\
    fmt::println("Domesticated animals: {}", domesticated_animals);
}

export void functional_initialization()
{
// Functional Initialization

    int apple_count(5);
    int orange_count(10);
    int fruit_count(apple_count + orange_count);
    int narrowing_conversions_functional(2.9); // Using int to store float
                                              // truncates the value after
                                              // the decimal

    fmt::println("Apple count: {}", apple_count);
    fmt::println("Orange count: {}", orange_count);
    fmt::println("fruit count: {}", fruit_count);
    fmt::println("Narrowing conversions: {}", narrowing_conversions_functional);
    fmt::println("sizeof int: {}", sizeof(int));
    fmt::println("sizeof apple_count: {}", sizeof(apple_count));

}

