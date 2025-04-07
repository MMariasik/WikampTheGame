#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.hpp"

int main()
{
    sf::RenderWindow window{ sf::VideoMode({ 900, 600 }), "Sig&Segv" };

    Player sig{ "images/sig.png" };

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                sig.setMovementDirection(keyPressed->scancode, true);
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>())
            {
                sig.setMovementDirection(keyPressed->scancode, false);
            }
        }

        sig.update();

        window.clear();
        window.draw(sig);
        window.display();
    }
}