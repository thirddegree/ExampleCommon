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


#pragma once

#include <platform.h>
#include <string>

class Application
{
public:
    Application(std::string title);

    virtual ~Application() = default;

    int Run();

protected:
    virtual bool Initialize();
    virtual void Update(float dt) = 0;
    virtual void Render(float dt) = 0;
    virtual void ShutDown() = 0;

protected:
    std::string m_title;
    SDL_Window* m_window;
    void*       m_handle;
    void*       m_display;
    bool        m_running;

private:
    void PollEvents();
};
