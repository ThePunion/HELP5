#pragma once
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Vertexbufferlayout.h"
#include "Textures.h"
#include "LoadShader2.h"
#include "VAO.h"
#include "Error.h"
#include "Camera.h"
#include "Gui.h"
GLint Query::any_samples_passed;
GLuint Query::Test[2];
static int ScreenWidth = 720;
static int ScreenHeight = 720;
int objectcount = 0;

struct vec3F
{
	float x, y, z;
	vec3F(float a, float b, float c)
	{

		x = a;
		y = b;
		z = c;

	}
	
};


std::vector<GLfloat> OBJImport(std::string objfilepath)
{
	vec3F Temp(0, 0, 0);
	int i = 0;
	//reading from the OBJ file
	std::string line = "";
	std::string prefix = "";
	std::string OBJ;
	std::ifstream OBJStream(objfilepath);
	std::vector<GLfloat> Verticies;
	
	if (OBJStream.is_open())
	{
		std::cout << objfilepath << " Opened" << std::endl;
	
		std::stringstream sstr;
	//sstr << OBJStream.rdbuf();
		//OBJ = sstr.str();
		
		while (std::getline(OBJStream, line))
		{
			
			sstr.clear();
			sstr.str(line);
			sstr >> prefix;

			if (prefix == "#")
			{

			}
			else if (prefix == "o")
			{

			}
			else if (prefix == "s")
			{

			}
			else if (prefix == "vn")
			{
				sstr >> Temp.x >> Temp.y >> Temp.z;
				Verticies.push_back(Temp.x);
				Verticies.push_back(Temp.y);
				Verticies.push_back(Temp.z);
				//std::cout << Verticies[0+ i] << std::endl;
				//std::cout << Verticies[1+ i] << std::endl;
				//std::cout << Verticies[2+ i] << std::endl;
				//std::cout << line << std::endl;
				i += 3;
			}
			else
			{

			}
			
		}

		OBJStream.close();
	}
	else
	{
		std::cout << "could not open obj at " << objfilepath << std::endl;
	}

	//converting the Verticies of the OBJ into a usable vector


	


	return Verticies;
}

void DrawAll()
{
	for (size_t i = 0; i < Object::ObjectDrawList.size(); i++)
	{
		Object::ObjectDrawList[i]->DrawList();

	}

}


int main()
{

	if (!glfwInit())
	{
		std::cout <<  "Failed to initialize GLFW\n";

	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for mac
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // dont use old OpenGL 

	// Open a window and create its OpenGL context
	GLFWwindow* window; 
	window = glfwCreateWindow(ScreenWidth, ScreenHeight, "OpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout <<  "Failed to open GLFW window.\n";
		glfwTerminate();

	}
	glfwMakeContextCurrent(window); // Initialize GLEW
	glfwSwapInterval(0);
	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		std::cout <<  "Failed to initialize GLEW" << std::endl;

	}
	
	
	//Escape key to exit the program

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	float screenspace = 0;


		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);

		//std::cout << GL_MAX_DRAW_BUFFERS << std::endl; std::cout << GL_DRAW_BUFFER << std::endl;
		
		
		glEnable(GL_DEPTH_TEST);
		double prevTime = glfwGetTime();
		Camera Camera(prevTime, glm::vec3(0.0f, 0.0f, 2.0f), (unsigned int&)ScreenWidth,(unsigned int&)ScreenHeight);





	//	Sphere.ShaderRef->SetUniforms2f("Res", 1080.0f, 1080.0f);
	//Cube2.SetColour(0.6f, 0.3f, 0.4f, 1.0f);
	//Cube2.SetCoord(0.0f, 0.0f, -1.0f);
	//Cube.SetCoord(0.0f, 0.0f, 3.0f);
	//Cube3.SetColour(1.0f, 1.0f, 0.0f, 0.5f);
		const wchar_t* path = L"res/rat.wav";
		//PlaySound(path,NULL,SND_ASYNC);

	
		MyGui gui(window, (unsigned int&)ScreenWidth, (unsigned int&)ScreenHeight);
	
		
		
		int x = 1;
		int y = 1;


		Object Grass("Grass", Object::grass, "res/Atlas.png", "Shaders/fragment.glsl", "Shaders/vertex.glsl", Camera);
		Object Sand("Sand", Object::sand, "res/Atlas.png", "Shaders/fragment.glsl", "Shaders/vertex.glsl", Camera);
		Object CraftingBench("CraftingBench", Object::craftingbench, "res/Atlas.png", "Shaders/fragment.glsl", "Shaders/vertex.glsl", Camera);

		Object Furnace("Furnace", Object::furnace, "res/Atlas.png", "Shaders/fragment.glsl", "Shaders/vertex.glsl", Camera);
		Object Lava("Lava", Object::lava, "res/Atlas.png", "Shaders/fragment.glsl", "Shaders/vertex.glsl", Camera);
		//Object LightingTest("LightingTest", "Shaders/LightingFragment.glsl", "Shaders/LightingVertex.glsl", Camera);
		//Object Sphere("Sphere", "Shaders/SphereFrag.glsl", "Shaders/SphereVertex.glsl", Camera);



		for (int z = -1; z < 0; z++)
		{
			for (int y = -50; y < 50; y++)
			{
				for (int x = -50; x < 50; x++)
				{


					//Cube2.AddToList(x, y, z,1,1,1);
					Lava.AddToList(x, y, z, 1, 1, 1);
					//LightingTest.AddToList(x, y, z, 1, 1, 1);
				}
			}
		}

		//CraftingBench.AddToList(0, 0, 0, 1, 1, 1);
	//	LightingTest.AddToList(0, 0, 0, 1, 1, 1);


	

		do {
			Object::time = glfwGetTime();
			// Clear the screen.
			glClearColor(0.25f, 0.4f, 0.7f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//Poll Camera Inputs
			Camera.inputs(window);
			// ImGui Windows
			gui.Init();
			gui.MakeWindow();
			//gui.MakeViewport();
			
	
			//Draw all objects 
			std::launch::async, DrawAll();
			
		
			//ImGui Window Terminator
			gui.render();
			gui.RenderEnder();

		// Swap buffers
	     glfwPollEvents();
		// glfwGetFramebufferSize(window, &ScreenWidth, &ScreenHeight);
		 glfwGetWindowSize(window,&ScreenWidth,&ScreenHeight);
		 glViewport(0, 0, ScreenWidth, ScreenHeight);
		 glfwSwapBuffers(window);
		
		} 
	// Check if ESC was pressed or if the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

}