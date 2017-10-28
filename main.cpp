#include <iostream>
#include <memory>
#include <algorithm>
#include <fstream>

#include <SFML/Graphics.hpp>

int main()
{
    std::unique_ptr<std::string> message;
    message = std::make_unique<std::string>("Titties");

    sf::RenderWindow window(sf::VideoMode(200, 200), message->c_str());
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

