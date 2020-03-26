#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GL/wglew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>

#include "Debug.h"
#include "Cube.h"
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

	void initialise();

	void setupShader(GLenum t_type, GLuint& t_shaderID, std::string t_filePath);

	std::string loadShader(std::string t_filePath);

	GLuint compileShader(GLenum t_type, std::string& t_src);

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

	// *** OpenGL Variables ***

	GLuint	vsid,		// Vertex Shader ID
		fsid,		// Fragment Shader ID
		progID,		// Program ID
		vao = 0,	// Vertex Array ID
		vbo,		// Vertex Buffer ID
		vib,		// Vertex Index Buffer
		to[1];		// Texture ID
	GLint	positionID,	// Position ID
		colorID,	// Color ID
		textureID,	// Texture ID
		uvID,		// UV ID
		mvpID,		// Model View Projection ID
		x_offsetID, // X offset ID
		y_offsetID,	// Y offset ID
		z_offsetID;	// Z offset ID

	GLenum	error;		// OpenGL Error Code


	//Please see .//Assets//Textures// for more textures
	const std::string filename = ".//ASSETS//TEXTURES//grid_wip.tga";

	int width;						// Width of texture
	int height;						// Height of texture
	int comp_count;					// Component of texture

	unsigned char* img_data;		// image data

	glm::mat4 mvp, projection,
		view, model;			// Model View Projection


	float x_offset, y_offset, z_offset; // offset on screen (Vertex Shader)

};
#endif