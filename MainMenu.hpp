#ifndef MainMenu_hpp
#define MainMenu_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <stdio.h>
#pragma once

#define MAX_NUMBER_OF_ITEMS 2
class MainMenu
{
    public:
    MainMenu(float width, float height);
    ~MainMenu();
    
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem(){return selectedItemIndex;}
    
    private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
};
#endif /* MainMenu_hpp */
