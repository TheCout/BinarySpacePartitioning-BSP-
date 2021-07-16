#pragma once
#include <Windows.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>


#include "Player.hpp"


namespace Engine {


	class Configurations
	{
	protected:
		static constexpr uint32_t WIDTH = 840;
		static constexpr uint32_t HEIGHT = 680;
		const char* TITLE = "Binary Space Partitioning (BSP)";

		static constexpr uint32_t FPS = 60;
	};


	class Renderer
	{
	protected:
		virtual void tick() = 0; // All the game logics goes right there
		virtual void render() = 0;
	};


	class App : Configurations, public Renderer
	{
	public:
		void run() 
		{
			init();
			mainLoop();
			cleanup();
		}
		void tick() override;
		void render() override;
	private:
		void init();
		void mainLoop();
		void cleanup();
	private:
		GLFWwindow* window = nullptr;
	};
}
