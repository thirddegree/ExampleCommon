/*
*    The MIT License (MIT)
*
*    Copyright (c) 2016 ThirdDegree 
*
*    Permission is hereby granted, free of charge, to any person obtaining a copy
*    of this software and associated documentation files (the "Software"), to deal
*    in the Software without restriction, including without limitation the rights
*    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*    copies of the Software, and to permit persons to whom the Software is
*    furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in all
*    copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*    SOFTWARE.
*/


#include <application.h>
#include <iostream>

Application::Application(std::string title)
    : m_title(std::move(title)),
      m_handle(nullptr),
      m_display(nullptr),
      m_running(true)
{

}

bool Application::Initialize()
{
    if(SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) != 0) {
        std::cerr << "SDL Failed to Initialize. Exiting..." << std::endl;
        return false;
    }

    m_window = SDL_CreateWindow(m_title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280, 720, SDL_WINDOW_RESIZABLE);
    if(!m_window)
    {
        std::cerr << "SDL Failed to create window. Exiting..." << std::endl;
        SDL_Quit();
        return false;
    }

#ifdef _WIN32

#else
    SDL_SysWMinfo info;
    SDL_VERSION(&info.version);
    if(SDL_GetWindowWMInfo(m_window, &info))
    {
        m_handle = (void*)info.info.x11.window;
        m_display = info.info.x11.display;
    }
#endif

    return true;
}

void Application::PollEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
        case SDL_QUIT:
            m_running = false;
            break;

        default:
            break;
        }
    }
}

int Application::Run()
{
    if(!Initialize())
        return -1;
    
    while(m_running)
    {
        PollEvents();

        Update(0.0f);

        Render(0.0f);
    }  

    ShutDown();

    return 0;
}
