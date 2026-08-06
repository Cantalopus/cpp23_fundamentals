module;

#include<SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<fmt/format.h>
#include<limits>

export module utilities;

export void moving_rectangle() {

    sf::RenderWindow* p_window = new sf::RenderWindow(sf::VideoMode{{800, 600}}, "Moving Rectangle");
    sf::RectangleShape* rectangle = new sf::RectangleShape{{100.f, 50.f}};

    rectangle->setPosition({350.f, 275.f});
    rectangle->setFillColor(sf::Color::Red);

    while(p_window->isOpen())
    {
        while(const std::optional<sf::Event> event = p_window->pollEvent())
        {
            if(((*event).is<sf::Event::Closed>()))
                p_window->close();
        }
    

    /////////Keyboard Input///////////////////////////
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        rectangle->move({-2.f, 0.f});
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        rectangle->move({2.f, 0.f});
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        rectangle->move({0.f, -2.f});
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        rectangle->move({0.f, 2.f});

    /////////Update Window///////////////////////////
    p_window->clear();
    p_window->draw(*rectangle);
    p_window->display();
    }
    delete p_window;
    delete rectangle;
}

export void draw_rectangle(){
    //Draw Rectangle
    sf::RenderWindow window(sf::VideoMode{{800,600}},"Draw Rectangle");
    sf::RectangleShape rectangle({200.f, 100.f});
    rectangle.setPosition({300.f,250.f});
    rectangle.setFillColor(sf::Color::Green);

    while(window.isOpen()){
        while(const std::optional<sf::Event>event = window.pollEvent()){
            if(event->is<sf::Event::Closed>())
                window.close();
        }
    window.clear();

    window.draw(rectangle);

    window.display();
    }
}

export void explicit_window(){
    //Creating A Window
    sf::VideoMode* p_video = new sf::VideoMode{{800,600}};
    sf::RenderWindow* p_window = new sf::RenderWindow{
                                *p_video,
                                "My Window",
                                1 << 2};
    while(p_window->isOpen()){
        while(const std::optional<sf::Event> event = p_window->pollEvent()){
            if((*event).is<sf::Event::Closed>()){
                p_window->close();
            }
        }
        p_window->clear();

        p_window->display();
    }
    delete p_window;
    delete p_video;
}

export void number_systems(){
    //Integers and number system
    int number1 = 15;         // Decimal
    int number2 = 017;        // Octal
    int number3 = 0x0F;       // Hexidecimal
    int number4 = 0b00001111; // Binary

    fmt::println("number1: {}", number1);
    fmt::println("number2: {}", number2);
    fmt::println("number3: {}", number3);
    fmt::println("number4: {}", number4);
}

export void floating_point_types(){
    // Floating point types
    // floats offer 7 digits of precision while double offers 15
    // long double offers 18 digits of percision
    // The range of float is 1.17549e-38 to 3.40282e+38
    // The range of double is 2.22507e-308 to 1.79769e+308
    // The range of long double is 3.3621e-4932 to 1.18973e+4932

    //Single precision (float)
    float single_precision = 1.123456789123456789f;

    //Double precision (double)
    double double_precision = 1.123456789123456789;

    //Extended precision (long double)
    long double long_double_precision = 1.123456789123456789;

    //Print results with 30 decimal places for comparison
    fmt::println("Float (single precision): {:.30f}", single_precision);
    fmt::println("Double (double precision): {:.30f}", double_precision);
    fmt::println("Long double (extended precision): {:.30L}", long_double_precision);

    fmt::println("Size of float: {} bytes", sizeof(float));
    fmt::println("Size of double: {} bytes", sizeof(double));
    fmt::println("Size of long double: {} bytes", sizeof(long double));
}

export void numeric_limits(){
    fmt::println("The range for int is from {} to {}",
                                    std::numeric_limits<int>::min(),
                                    std::numeric_limits<int>::max());
    fmt::println("The range for float is from {} to {}",
                                    std::numeric_limits<float>::min(),
                                    std::numeric_limits<float>::max());
    fmt::println("The range for double is from {} to {}",
                                    std::numeric_limits<double>::min(),
                                    std::numeric_limits<double>::max());
    fmt::println("The range for long double is {} to {}",
                                    std::numeric_limits<long double>::min(),
                                    std::numeric_limits<long double>::max());
}

export void print_type_ranges(){
    //Ranges
    fmt::println("The range for short is from {} to {}", std::numeric_limits<short>::min(), std::numeric_limits<short>::max());
    fmt::println("The range for unsinged short is from {} to {}", std::numeric_limits<unsigned short>::min(), std::numeric_limits<unsigned short>::max());
    fmt::println("The range for int is from {} to {}", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    fmt::println("The range for unsigned int is from {} to {}", std::numeric_limits<unsigned int>::min(), std::numeric_limits<unsigned int>::max());
    fmt::println("The range for long is from {} to {}", std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    fmt::println("The range for float is from {} to {}", std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
    fmt::println("The range(with lowest) for float is from {} to {}", std::numeric_limits<float>::lowest(), std::numeric_limits<float>::max());
    fmt::println("The range(with lowest) for double is from {} to {}", std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max());
    fmt::println("The range(with lowest) for long double is from {} to {}", std::numeric_limits<long double>::lowest(), std::numeric_limits<long double>::max());
    fmt::println("int is signed: {}", std::numeric_limits<int>::is_signed);
    fmt::println("int digits: {}", std::numeric_limits<int>::digits);
}