/*
    . Exploring variables and data types
*/

#include <fmt/format.h>
#include <SFML/Graphics.hpp>

#include <cmath>
#include <optional>
#include <random>
#include <vector>

struct Particle
{
    sf::Vector2f position;
    sf::Vector2f velocity;
    float radius;
    sf::Color color;
};

float length(sf::Vector2f vector)
{
    return std::sqrt(
        vector.x * vector.x +
        vector.y * vector.y
    );
}

// One line comment
import utilities;

int main(){

constexpr unsigned int window_width  = 1200;
    constexpr unsigned int window_height = 800;

    sf::RenderWindow window{
        sf::VideoMode{{window_width, window_height}},
        "Particle Gravity Well"
    };

    window.setFramerateLimit(144);

    std::mt19937 random_engine{std::random_device{}()};

    std::uniform_real_distribution<float> x_distribution{
        0.0f,
        static_cast<float>(window_width)
    };

    std::uniform_real_distribution<float> y_distribution{
        0.0f,
        static_cast<float>(window_height)
    };

    std::uniform_real_distribution<float> velocity_distribution{
        -30.0f,
        30.0f
    };

    std::uniform_real_distribution<float> radius_distribution{
        1.0f,
        3.5f
    };

    std::uniform_int_distribution<int> color_distribution{
        100,
        255
    };

    std::vector<Particle> particles;

    constexpr std::size_t particle_count = 1'200;

    particles.reserve(particle_count);

    for(std::size_t index = 0; index < particle_count; ++index)
    {
        Particle particle;

        particle.position = {
            x_distribution(random_engine),
            y_distribution(random_engine)
        };

        particle.velocity = {
            velocity_distribution(random_engine),
            velocity_distribution(random_engine)
        };

        particle.radius = radius_distribution(random_engine);

        particle.color = sf::Color{
            static_cast<std::uint8_t>(color_distribution(random_engine)),
            static_cast<std::uint8_t>(color_distribution(random_engine)),
            255,
            180
        };

        particles.push_back(particle);
    }

    sf::Clock clock;

    sf::CircleShape particle_shape;

    sf::CircleShape gravity_marker{18.0f};

    gravity_marker.setOrigin({18.0f, 18.0f});
    gravity_marker.setFillColor(sf::Color{80, 140, 255, 80});
    gravity_marker.setOutlineColor(sf::Color{150, 210, 255, 220});
    gravity_marker.setOutlineThickness(2.0f);

    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if((*event).is<sf::Event::Closed>())
            {
                window.close();
            }

            if(const auto* key_pressed =
                   (*event).getIf<sf::Event::KeyPressed>())
            {
                if(key_pressed->scancode ==
                   sf::Keyboard::Scancode::Escape)
                {
                    window.close();
                }
            }
        }

        float delta_time = clock.restart().asSeconds();

        /*
         * Prevent particles from jumping enormous distances if the
         * program pauses momentarily.
         */
        if(delta_time > 0.033f)
        {
            delta_time = 0.033f;
        }

        const sf::Vector2i mouse_pixel_position =
            sf::Mouse::getPosition(window);

        const sf::Vector2f gravity_position =
            window.mapPixelToCoords(mouse_pixel_position);

        float gravity_strength = 75'000.0f;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            gravity_strength = 220'000.0f;
        }

        for(Particle& particle : particles)
        {
            sf::Vector2f direction{
                gravity_position.x - particle.position.x,
                gravity_position.y - particle.position.y
            };

            float distance = length(direction);

            /*
             * This prevents division by zero and keeps the force from
             * becoming infinitely strong near the mouse.
             */
            if(distance < 20.0f)
            {
                distance = 20.0f;
            }

            sf::Vector2f normalized_direction{
                direction.x / distance,
                direction.y / distance
            };

            /*
             * Gravity becomes weaker with distance.
             *
             * The added 400 prevents the force from becoming too extreme
             * near the center.
             */
            const float force =
                gravity_strength /
                ((distance * distance) + 1.0f);

            particle.velocity.x +=
                normalized_direction.x * force * delta_time;

            particle.velocity.y +=
                normalized_direction.y * force * delta_time;

            /*
             * Add a sideways force to create the swirling motion.
             */
            sf::Vector2f perpendicular_direction{
                -normalized_direction.y,
                 normalized_direction.x
            };

            const float swirl_force = 18.0f;

            particle.velocity.x +=
                perpendicular_direction.x *
                swirl_force *
                delta_time;

            particle.velocity.y +=
                perpendicular_direction.y *
                swirl_force *
                delta_time;

            /*
             * Slight drag keeps particle speeds under control.
             */
            particle.velocity.x *= 0.999f;
            particle.velocity.y *= 0.999f;

            particle.position.x +=
                particle.velocity.x * delta_time;

            particle.position.y +=
                particle.velocity.y * delta_time;

            /*
             * Wrap particles around the edges of the screen.
             */
            if(particle.position.x < 0.0f)
            {
                particle.position.x =
                    static_cast<float>(window_width);
            }
            else if(particle.position.x >
                    static_cast<float>(window_width))
            {
                particle.position.x = 0.0f;
            }

            if(particle.position.y < 0.0f)
            {
                particle.position.y =
                    static_cast<float>(window_height);
            }
            else if(particle.position.y >
                    static_cast<float>(window_height))
            {
                particle.position.y = 0.0f;
            }
        }

        window.clear(sf::Color{3, 5, 15});

        /*
         * A normal CircleShape object is reused for every particle.
         * We change its size, position, and color before each draw call.
         */
        for(const Particle& particle : particles)
        {
            particle_shape.setRadius(particle.radius);

            particle_shape.setOrigin({
                particle.radius,
                particle.radius
            });

            particle_shape.setPosition(particle.position);
            particle_shape.setFillColor(particle.color);

            window.draw(
                particle_shape,
                sf::RenderStates{sf::BlendAdd}
            );
        }

        gravity_marker.setPosition(gravity_position);

        window.draw(
            gravity_marker,
            sf::RenderStates{sf::BlendAdd}
        );

        window.display();
    }



/*
    moving_rectangle();

    draw_rectangle();

    explicit_window();
*/
/*
    number_systems();

    floating_point_types();

    numeric_limits(); 

    print_type_ranges();
*/
    
}

