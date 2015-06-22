#include <GraphicsWorld.hpp>
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace gameEngine
{

void GraphicsWorld::init()
{
    
}

Window::SmartPtr GraphicsWorld::createWindow(const int& w, const int& h, const std::string& title)
{
    Window::SmartPtr window(new Window(w, h, title));
    _windows.push_back(window);
    return window;
}



}
