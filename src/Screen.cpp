#include "Screen.h"


void Screen::setFps(const unsigned int& fps)
{
	_window.setFramerateLimit(fps);
        }

bool Screen::isOpen()
{
	return _window.isOpen();
}

void Screen::processEvents()
{
    while (_window.pollEvent(_event))
    {
        auto it = _eventCallbacks.find(_event.type);
        if (it != _eventCallbacks.end())
        {
            for (const auto& callback : it->second)
            {
                callback(_event); 
            }
        }
    }
}


void Screen::regCallBack(const sf::Event::EventType& et, const std::function<void(const sf::Event&)>& func)
{
    _eventCallbacks[et].push_back(func);
}
