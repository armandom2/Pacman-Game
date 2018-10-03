#include "MainMenu.hpp"
MainMenu::MainMenu(float width, float height)
{
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) //GETS THE FONT
    {
        
    }
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("PLAY");
    menu[0].setCharacterSize(75.0f);
    menu[0].setPosition(300.0f, 600.0f);
    
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("EXIT");
    menu[1].setCharacterSize(75.0f);
    menu[1].setPosition(300.0f, 700.0f);

    selectedItemIndex =0;
}


MainMenu::~MainMenu()
{
}

void MainMenu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void  MainMenu::MoveUp(){ // IF THE USER CLICKES THE UP ARROW, THE OPTION WILL TURN RED, IF THERE IS AN OPTION ON TOP
    if(selectedItemIndex - 1>=0){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
        
    }
}

void  MainMenu::MoveDown(){// IF THE USER CLICKES THE DOWN ARROW, THE OPTION WILL TURN RED, IF THERE IS AN OPTION ON TOP
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
        
    }
}

