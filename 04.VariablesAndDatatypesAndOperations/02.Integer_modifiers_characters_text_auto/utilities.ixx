module;

#include<SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<fmt/format.h>

export module utilities;

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

