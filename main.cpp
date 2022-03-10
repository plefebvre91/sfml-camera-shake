
#include <iostream>

#include "Animation.hpp"
#include "AnimatedSprite.hpp"
#include "Camera.hpp"

int main() {
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(800, 460), "SFML window");
  window.setFramerateLimit(30);
  Camera camera(&window);
  sf::Clock clock;

  sf::Texture backgroundTexture;
  sf::Sprite background;
  backgroundTexture.loadFromFile("background.png");
  background.setTexture(backgroundTexture);

  sf::Texture explosionTexture;
  explosionTexture.loadFromFile("explosion.png");

  Animation explosionAnimation;
  explosionAnimation.setSpriteSheet(explosionTexture);

  for (int i=0; i<8; i++)
    explosionAnimation.addFrame(sf::IntRect(48*i, 0, 48, 48));

  AnimatedSprite explosion(sf::seconds(0.13), true, false);
  explosion.setPosition(sf::Vector2f(125, 245));

  // Start the game loop
  while (window.isOpen())
  {
    sf::Time dt = clock.restart();

    // Process events
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
          camera.shake(0.2, 1200.0);
          explosion.stop();
          explosion.play(explosionAnimation);
        }
      }
    }

    // Clear screen
    window.clear();

    camera.update(dt.asSeconds());
    explosion.update(dt);

    window.draw(background);
    window.draw(explosion);

    // Update the window
    window.display();
  }
  return EXIT_SUCCESS;
}
