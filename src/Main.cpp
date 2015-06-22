#include <iostream>
#include <WindowManager.hpp>
#include <boost/thread.hpp>

int main()
{
    std::cout << " Starting.... " << std::endl;

    //gameEngine::GraphicsWorld gw;
    /* Initialize the library */
    
    if(!glfwInit()){
        return -1;
    }
    
    std::cout << " GLFW version: " << glfwGetVersionString() << std::endl;

    gameEngine::WindowManager m;
    gameEngine::Window::SmartPtr w(m.getWindow(800,600,"TEST"));
    
    //GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    //glfwMakeContextCurrent(window);

    {
        w->makeVisible(); // Make it as current context of GL
    }


    if(glewInit() != GLEW_OK){
        std::cout << " Some error while initializing GLEW.  " << std::endl;
    }
    
    while (!w->isClosed())
    {
        w->clear();
        if(w->isKeyPressed(0)){
               std::cout << " A Pressed. " << std::endl;
        }
        
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        
        w->update();
        
#ifdef HH
        // Keep running
        float ratio;
        int width, height;
        std::pair<int, int> whPair = w->getFrameBufferSize();
        width = whPair.first;
        height = whPair.second;
        //std::cout << "Size : " << width << " , " << height << std::endl;
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        glfwSwapBuffers(w->getGlfwWindowPtr());
        glfwPollEvents();
        //boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
#endif
    }

    std::cout << " Stopping... " << std::endl;

    
    glfwTerminate();
}
