#ifndef CAMERA_HPP
#define CAMERA_HPP

#define CAMERA_SHAKE_ANGLE 10.0f
#define CAMERA_SHAKE_OFFSET 20.0f

#include <SFML/Graphics.hpp>


/**
 * Define the parameter of animation
 */
struct CameraAnimation {
  /**
   * Current time (updated during animation)
   */
  sf::Time current;

  /**
   * Animation duration
   */
  sf::Time max;

  /**
   * Shaking power (between 0 and 1)
   */
  float trauma;
};


class Camera {
public:
  /**
   * Constructor
   * @param associated SFML window
   */
  Camera(sf::RenderWindow* window);

  /**
   * Shake the camera
   * @param shake power
   * @param shake duration in milliseconds
   */
  void shake(float trauma, float duration_ms);

  /**
   * Update camera state. Shall be called in update stage of game loop.
   * @param ellapsed time since last update
   */
  void update(float dt);

private:
  // Animation parameter
  CameraAnimation _animation;

  // SFML window for this camera
  sf::RenderWindow* _window;

  // View associated to window
  sf::View _view;

  // View center
  sf::Vector2f _center;
};

#endif
