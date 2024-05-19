#include "Window.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

Window::Window()
{
    setup("Window", sf::Vector2u(1600, 900));
}

Window::Window(const std::string& l_title, const sf::Vector2u& l_size)
{
    setup(l_title, l_size);
}

Window::~Window()
{
    destroy();
}

void Window::setup(const std::string& l_title, const sf::Vector2u& l_size)
{
    m_done = false;
    m_fullscreen = false;
    m_focused = true;
    m_paused = false;
    m_window_title = l_title;
    m_window_size = l_size;
    m_vsync = true;
    create();
}

void Window::create()
{
    auto style = (m_fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({m_window_size.x, m_window_size.y, 32}, m_window_title, style);
    m_window.setVerticalSyncEnabled(m_vsync);
}

void Window::destroy()
{
    m_window.close();
}

void Window::update()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_done = true;
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            m_done = true;
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
            toggleFullscreen();
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
            togglePaused();
        else if (event.type == sf::Event::LostFocus)
            m_focused = false;
        else if (event.type == sf::Event::GainedFocus)
            m_focused = true;
    }
}

void Window::toggleFullscreen()
{
    m_fullscreen = ! m_fullscreen;
    destroy();
    create();
}

void Window::togglePaused()
{
    m_paused = ! m_paused;
}

void Window::beginDraw()
{
    m_window.clear(sf::Color::Black);
}

void Window::endDraw()
{
    m_window.display();
}

void Window::draw(sf::Drawable& l_drawable)
{
    m_window.draw(l_drawable);
}
