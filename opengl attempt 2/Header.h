#pragma once
#define GLEW_STATIC 
#include <GL/glew.h> 
#include <GLFW/glfw3.h> 
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "res/3rd party/glm/glm.hpp"
#include "res/3rd party/glm/gtc/matrix_transform.hpp"
#include "res/3rd party/glm/gtc/type_ptr.hpp"
#include "res/3rd party/glm/gtx/rotate_vector.hpp"
#include "res/3rd party/glm/gtx/vector_angle.hpp"
#include <windows.h>
#include <chrono>
#include <future>
#include <thread>
#include <string>
#include "Error.h"
#include "res/3rd party/imgui.h"
#include "res/3rd party/imgui_impl_glfw.h"
#include "res/3rd party/imgui_impl_opengl3.h"
