#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GL/wglew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <SFML/Graphics.hpp>
#include "Clouds.h"
#include "Lightning.h"

class Game
{
public:

	// *** Default Constructor/Destructor ***
	Game();
	~Game();

	// *** Methods ***

	/// <summary>
	/// @brief Main run method, handles calling of all other methods
	/// </summary>
	void run();

private:

	// *** Methods ***

	/// <summary>
	/// @brief Loads our background image in from a file
	/// </summary>
	void setupBackground();

	/// <summary>
	/// @brief Handles all incoming system/SFML events
	/// </summary>
	void processEvents();

	/// <summary>
	/// @brief Handles the update loop, called at 60FPS
	/// </summary>
	/// <param name="t_deltaTime">time in seconds since the last frame</param>
	void update(sf::Time t_deltaTime);

	/// <summary>
	/// @brief Handles the render loop; drawing and flipper framebuffer
	/// </summary>
	void render();

	// *** Objects ***
	sf::RenderWindow m_window;

	bool m_exitGame;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	Clouds* m_clouds;
	Lightning m_lightning;
};
#endif