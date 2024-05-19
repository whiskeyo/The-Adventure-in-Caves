#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>

class Window
{
public:
    Window();
    Window(const std::string& l_title, const sf::Vector2u& l_size);
    ~Window();

    void beginDraw(); // clear the window
    void endDraw(); // display changes on the screen
    void update(); // update every frame

    bool isDone()
    {
        return m_done;
    }
    bool isPaused()
    {
        return m_paused;
    }
    bool isFocused()
    {
        return m_focused;
    }
    bool isFullscreen()
    {
        return m_fullscreen;
    }
    sf::Vector2u getWindowSize()
    {
        return m_window_size;
    }
    sf::RenderWindow* getRenderWindow()
    {
        return &m_window;
    }

    void toggleFullscreen();
    void togglePaused();
    void draw(sf::Drawable& l_drawable);

private:
    bool m_done; // is game finished?
    bool m_fullscreen;
    bool m_vsync;
    bool m_paused;
    bool m_focused;
    std::string m_window_title;
    sf::Vector2u m_window_size;
    sf::RenderWindow m_window;

    void setup(const std::string& l_title, const sf::Vector2u& l_size);
    void create();
    void destroy();
};

#endif
