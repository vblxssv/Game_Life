#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <map>
#include <functional>
#include "Consts.h"
#include <iostream>
#include <random>
#include "Screen.h"


class Map
{
private:
    std::vector<std::vector<std::shared_ptr<sf::RectangleShape>>> _map;
	int _w, _h;
public:
	Map(int width, int height);

	void updateMap();

	std::vector<std::shared_ptr<sf::Drawable>> getMap();
	
	void setGlider();

	void randomMap();

	void draw(Screen& screen);

	
};





