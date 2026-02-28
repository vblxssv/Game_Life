#include "Map.h"

Map::Map(int width, int height) : _w(width), _h(height)
{
    for (int y = 0; y < _h; y += 1)
    {
        std::vector<std::shared_ptr<sf::RectangleShape>> row;
        for (int x = 0; x < _w; x += 1)
        {
            auto rect = std::make_shared<sf::RectangleShape>(sf::Vector2f(consts::BLOCK_SIZE - 1, consts::BLOCK_SIZE - 1));
            rect->setFillColor(sf::Color::White);
            rect->setPosition(static_cast<float>(x * consts::BLOCK_SIZE), static_cast<float>(y * consts::BLOCK_SIZE));
            row.push_back(rect);
        }
        _map.push_back(row);
    }
}

void Map::updateMap()
{
    std::vector<std::vector<std::shared_ptr<sf::RectangleShape>>> temp;
    for (int y = 0; y < _h; y += 1)
    {
        std::vector<std::shared_ptr<sf::RectangleShape>> row;
        for (int x = 0; x < _w; x += 1)
        {
            auto rect = std::make_shared<sf::RectangleShape>(sf::Vector2f(consts::BLOCK_SIZE - 1, consts::BLOCK_SIZE - 1));
            rect->setPosition(static_cast<float>(x * consts::BLOCK_SIZE), static_cast<float>(y * consts::BLOCK_SIZE));
            int aliveNeighbors = 0;
            for (int dy = -1; dy <= 1; ++dy)
            {
                for (int dx = -1; dx <= 1; ++dx)
                {
                    if (dx == 0 && dy == 0) continue;

                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < _w && ny >= 0 && ny < _h)
                        if (_map[ny][nx]->getFillColor() == sf::Color::Black)
                            ++aliveNeighbors;
                }
            }
            if (_map[y][x]->getFillColor() == sf::Color::Black)
            {
                if (aliveNeighbors < 2 || aliveNeighbors > 3)
                    rect->setFillColor(sf::Color::White);
                else
                    rect->setFillColor(sf::Color::Black);
            }
            else 
            {
                if (aliveNeighbors == 3)
                    rect->setFillColor(sf::Color::Black);
                else
                    rect->setFillColor(sf::Color::White);
            }
            row.push_back(rect);
        }
        temp.push_back(row);
    }
    _map = temp;
}

std::vector<std::shared_ptr<sf::Drawable>> Map::getMap()
{
    std::vector<std::shared_ptr<sf::Drawable>> res;
    for (const auto& row : _map)
        for (const auto& rectShape : row)
            res.push_back(rectShape);
    return res;
}

void Map::setGlider()
{
    _map[0][1]->setFillColor(sf::Color::Black);
    _map[2][0]->setFillColor(sf::Color::Black);
    _map[2][1]->setFillColor(sf::Color::Black);
    _map[2][2]->setFillColor(sf::Color::Black);
    _map[1][2]->setFillColor(sf::Color::Black);
}

void Map::randomMap()
{
    for (int y = 0; y < _h; y += 1)
        for (int x = 0; x < _w; x += 1)
        {
            if (rand() % 2)
                _map[x][y]->setFillColor(sf::Color::Black);
            else
                _map[x][y]->setFillColor(sf::Color::White);
        }
}

void Map::draw(Screen& screen)
{
    for (int i = 0; i < _h; i++)
        for (int j = 0; j < _w; j++)
            screen.window().draw(*_map[j][i]);  
}

