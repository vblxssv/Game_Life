#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <map>
#include <functional>
#include "Consts.h"

class Screen
{
private:
    int _width, _height;
    sf::RenderWindow _window;
	sf::Event _event;
	std::map<sf::Event::EventType, std::vector<std::function<void(const sf::Event&)>>> _eventCallbacks;

public:
	Screen(int w, int h) : _width(w), _height(h), _window(sf::VideoMode(_width, _height), "Игра жизнь"), _event() {};

	

	void setFps(const unsigned int& fps);

    bool isOpen();

    void processEvents();

	void regCallBack(const sf::Event::EventType& et, const std::function<void(const sf::Event&)>& func);

    sf::RenderWindow& window() { return _window; }
};

