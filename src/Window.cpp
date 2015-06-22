#include <Window.hpp>
#include <GLFW/glfw3.h>


namespace gameEngine
{

bool Window::_keys[MAX_KEYS];
bool Window::_mouseButtons[MAX_BUTTONS];

Window::Window(const int& w, const int& h, const std::string& title) :
_width(w),
_height(h),
_title(title),
_windowPtr(glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL))
{
    if(!_windowPtr){
        throw std::runtime_error(" Can not create Window");
    }
    
    //glfwSetWindowCloseCallback(_windowPtr, my_window_close_callback);
    //glfwSwapInterval(10);
    for (int i = 0; i < MAX_KEYS; ++i)
    {
        _keys[i] = false;
    }
    for (int i = 0; i < MAX_BUTTONS; ++i)
    {
        _mouseButtons[i] = false;
    }
    // Later this object can be taken and used
    glfwSetWindowUserPointer(_windowPtr, this);
    glfwSetWindowCloseCallback(_windowPtr, myCloseCallback);
    glfwSetKeyCallback(_windowPtr, myKeyCallback);
    glfwSetWindowSizeCallback(_windowPtr, myWindowResizeCallback);
    glfwSetCursorPosCallback(_windowPtr, myCursorCallback );
    
}

void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update()
{
    glfwPollEvents();
    glfwSwapBuffers(_windowPtr);
    
}


void Window::addCallback()
{
    
    //glfwSetCursorPosCallback(_windowPtr, );
}



bool Window::isKeyPressed(unsigned int keyCode)
{
    if(keyCode >= MAX_KEYS){
        return false;
    }
    //std::cout << " Key Code Pressed: " << keyCode << std::endl;
    return _keys[keyCode];
}

void myCloseCallback(GLFWwindow* w)
{
    glfwSetWindowShouldClose(w, GL_TRUE);
}
void myKeyCallback(GLFWwindow* w, int key, int keyCode, int action, int mods)
{
    //std::cout << " Key Pressed:  " << keyCode << std::endl;
    Window * win = (Window *)glfwGetWindowUserPointer(w);
    win->_keys[keyCode] = (action != GLFW_RELEASE) ;
}

void myWindowResizeCallback(GLFWwindow* w, int wd, int hg){
    glViewport(0,0,wd, hg);
}

void myCursorCallback(GLFWwindow* w, double mx, double my){
    std::cout << " Mouse pos: " << mx << " , " << my << std::endl;
}

}
