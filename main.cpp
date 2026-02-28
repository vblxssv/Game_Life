#include "Screen.h"
#include "Map.h"

int main() {
    Map map(consts::BW, consts::BW);
    Screen screen(consts::WIDTH, consts::HEIGHT);
    screen.setFps(consts::FPS);

    screen.regCallBack(sf::Event::KeyPressed, [&](sf::Event e) {
        if (e.key.code == sf::Keyboard::Key::R) {
            map.randomMap();
        }
    });

    screen.regCallBack(sf::Event::Closed, [&](sf::Event e) {
        screen.window().close();
    });


    while (screen.isOpen()) {
        screen.processEvents();
        map.updateMap();




        screen.window().clear();
        map.draw(screen);
        screen.window().display();

    }




    return 0;
}

//int main()
//{
//    Screen screen(consts::WIDTH, consts::HEIGHT);
//
//    screen.regCallBack(sf::Event::Closed, [&](sf::Event e) {
//        screen.window().close();
//    });
//
//    while (screen.isOpen())
//    {
//        screen.processEvents();
//        screen.window().clear();
//        screen.window().display();
//    }
//    return 0;
//}