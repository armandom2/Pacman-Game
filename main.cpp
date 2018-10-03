/*
 AUTHORS: Armando Miguel
 CLASS: CSS-2A
 DATE: May 19, 2018
 Language: SFML/C++
 Description: This game is a remake of the game pacman. The goal of pacman is to eat all the Pacdots without having the ghost touch pacman.
              If the ghost happen to touch pacman, pacman loses a life. Pacman has a total of 3 lives. If the ghost touch you 3 times. You lose
              and the game is over. If you eat all the balls and still have more than 0 lives then you win the game. This game only has 1 level of pacman
              but for future work there will be more levels, scores, power dots and fruits to eat.
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"
#include "Platform.hpp"
#include "Ghost.hpp"
#include "MainMenu.hpp"
#include "ResourcePath.hpp"

using namespace std;

static const float VIEW_HEIGHT =  1800.0F; // Constant window screen.

void ResizeView(const sf::RenderWindow& window, sf::View& view)//Set window size
{
    float windowedit = float(window.getSize().x / float(window.getSize().y));
    view.setSize(VIEW_HEIGHT * windowedit, VIEW_HEIGHT);
}

int main(int, char const**)
{
    int pacLives = 3;
    int allBallsGone = 135;
    
    //MAIN MENU WINDOW
    MainMenu menu(800, 600);

    sf::RenderWindow window(sf::VideoMode(VIEW_HEIGHT,VIEW_HEIGHT),"Title of Window");// this creates the window
    sf::View view(sf::Vector2f(0.0f,0.0f), sf::Vector2f(1800.0f, 1800.0f));
    
    //CREATES PACMAN SPRITES
    sf::Texture pacman;
    pacman.loadFromFile(resourcePath()+ "pacsprite.png");
    
    //CREATES DOT SPRITES
    sf::Texture dots;
    dots.loadFromFile(resourcePath()+ "dot.png");
    
    //MAIN MENU SCREEN
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "mainmenu.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    sprite.setPosition(600.0f, 400.0f);
    
    //GAME OVER SCREEN
    sf::Texture gameover;
    if (!gameover.loadFromFile(resourcePath() + "gameover.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite lose(gameover);
    lose.setPosition(-600.0f, -500.0f);
    
    //WINNER SCREEN
    sf::Texture winner;
    if (!winner.loadFromFile(resourcePath() + "winner.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite win(winner);
    win.setPosition(-400.0f, -400.0f);
    
    //GHOST SPRITES
    sf::Texture redGhost;
    redGhost.loadFromFile(resourcePath() + "redsprite.png");
    sf::Texture orangeGhost;
    orangeGhost.loadFromFile(resourcePath() + "orangesprite.png");
    sf::Texture pinkGhost;
    pinkGhost.loadFromFile(resourcePath() + "pinksprite.png");
    sf::Texture aquaGhost;
    aquaGhost.loadFromFile(resourcePath() + "aquasprite.png");
    
    //PACMAN ANNIMATION
    Player player(&pacman, sf::Vector2u(5,4), 0.10f, 300.0f);
    
    //ARRAY OF ALL 4 GHOST
    Ghost ghosts[4] ={
    Ghost(&redGhost, sf::Vector2u(1,4), 0.10f, 500.0f),
    Ghost (&orangeGhost, sf::Vector2u(1,4), 0.10f, 500.0f),
    Ghost (&pinkGhost, sf::Vector2u(1,4), 0.10f, 500.0f),
    Ghost (&aquaGhost, sf::Vector2u(1,4), 0.10f, 500.0f)
    };

    //******************************** BUILDS BOARD ********************************
    //CREATE BOARD PLATFORM
    Platform gameBoard[22] = {Platform (nullptr, sf::Vector2f(5.0f,1800.0f), sf::Vector2f(-902.0f, 0.0f)),
                                Platform (nullptr, sf::Vector2f(1800.0f,5.0f), sf::Vector2f(0.0f,-905.0f)),
                                Platform (nullptr, sf::Vector2f(5.0f,1800.0f), sf::Vector2f(903.0f, 0.0f)),
                                Platform (nullptr, sf::Vector2f(1800.0f,5.0f), sf::Vector2f(0.0f,830.0f)),
                                Platform (nullptr, sf::Vector2f(635.0f,100.0f), sf::Vector2f(-474.5f,-390.0f)),
                                Platform (nullptr, sf::Vector2f(100.0f,550.0f), sf::Vector2f(-745.0f,-525.0f)),
                                Platform (nullptr, sf::Vector2f(100.0f,350.0f), sf::Vector2f(0.0f,-725.0f)),
                                Platform (nullptr, sf::Vector2f(430.0f,250.0f), sf::Vector2f(-372.0f,-675.0f)),
                                Platform (nullptr, sf::Vector2f(635.0f,100.0f), sf::Vector2f(474.5f,-390.0f)),
                                Platform (nullptr, sf::Vector2f(100.0f,550.0f), sf::Vector2f(745.0f,-525.0f)),
                                Platform (nullptr, sf::Vector2f(430.0f,250.0f), sf::Vector2f(372.0f,-675.0f)),
                                Platform (nullptr, sf::Vector2f(1180.0f,100.0f), sf::Vector2f(0.0f,-182.0f)),
                                Platform (nullptr, sf::Vector2f(100.0f,250.0f), sf::Vector2f(-540.0f,-80.0f)),
                                Platform (nullptr, sf::Vector2f(100.0f,250.0f), sf::Vector2f(540.0f,-80.0f)),
                                Platform (nullptr, sf::Vector2f(400.0f,100.0f), sf::Vector2f(-390.0f,90.0f)),
                                Platform (nullptr, sf::Vector2f(400.0f,100.0f), sf::Vector2f(390.0f,90.0f)),
                                Platform (nullptr, sf::Vector2f(100.0f,850.0f), sf::Vector2f(-745.0f,285.0f)),
                                Platform (nullptr, sf::Vector2f(430.0f,250.0f), sf::Vector2f(-375.0f,585.0f)),
                                Platform (nullptr, sf::Vector2f(1180.0f,100.0f), sf::Vector2f(0.0f,300.0f)),
                                Platform (nullptr, sf::Vector2f(100.0f,370.0f), sf::Vector2f(0.0f,525.0f)),
                                Platform (nullptr, sf::Vector2f(100.0f,850.0f), sf::Vector2f(745.0f,285.0f)),
                                Platform (nullptr, sf::Vector2f(430.0f,250.0f), sf::Vector2f(375.0f,585.0f))
    };
    //******************************** CREATS BALLS ********************************
    //CREATES DOT PLATFORM
    Platform Dots[135] = {Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,-720.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,-620.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,-520.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,-420.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,-320.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,-200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,-80.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,40.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,140.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,240.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,340.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,440.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,540.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-850.0f,640.0f)),
                            //right side
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,-720.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,-620.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,-520.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,-420.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,-320.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,-200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,-80.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,40.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,140.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,240.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,340.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,440.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,540.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(850.0f,640.0f)),
                            //bottom side 28 BALLS
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-750.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-520.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-420.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-320.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-220.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-100.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-0.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(100.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(220.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(320.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(420.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(520.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,780.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(750.0f,780.0f)),
                            //Top side
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-750.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-520.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-420.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-320.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-220.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-100.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(100.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(220.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(320.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(420.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(520.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(750.0f,-850.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-750.0f,-200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(750.0f,-200.0f)),
                            //Top middle 32 BALLS
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,-720.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,-620.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-520.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-420.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-320.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-220.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-100.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-0.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(100.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(220.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(320.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(420.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(520.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,-500.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-100.0f,-720.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-100.0f,-620.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(100.0f,-720.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(100.0f,-620.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,-720.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,-620.0f)),
                            //Middle Center
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-520.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-420.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-320.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-220.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-100.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(100.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(220.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(0.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(320.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(420.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(520.0f,-285.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,-285.0f)),
                            //middle left 34 BALLS
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,-200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,-100.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,10.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,110.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,310.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,410.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,540.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-640.0f,640.0f)),
                            //middle middle
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-520.0f,200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-420.0f,200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-320.0f,200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-220.0f,200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-0.0f,200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(100.0f,200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(220.0f,200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(320.0f,200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(420.0f,200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(520.0f,200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,200.0f)),
                            //middle right
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,-200.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,-100.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,10.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,110.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,310.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,410.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,540.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(640.0f,640.0f)),
                            //middle bottom
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-520.0f,410.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-420.0f,410.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-320.0f,410.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-220.0f,410.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-100.0f,410.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(100.0f,410.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(220.0f,410.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(320.0f,410.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(420.0f,410.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(520.0f,410.0f)),
                            //middle middle left and right
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-100.0f,540.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(-100.0f,640.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(100.0f,540.0f)),
                            Platform (&dots,sf::Vector2f(25.0f, 25.0f), sf::Vector2f(100.0f,640.0f)),
                            //43 BALLS
    };
    
    float deltaTime = 0.0f;
    sf::Clock clock;
    
    //PACMAN INTRO MUSIC
    sf::SoundBuffer introsong;
    if (!introsong.loadFromFile(resourcePath() + "pacman_beginning.wav")) {
        return EXIT_FAILURE;
    }
    sf::Sound intro;
    intro.setBuffer(introsong);
    
    //PACMAN EATING SOUND
    sf::SoundBuffer eatingballs;
    if (!eatingballs.loadFromFile(resourcePath() + "pacman_chomp.wav")) {
        return EXIT_FAILURE;
    }
    sf::Sound eat;
    eat.setBuffer(eatingballs);
    
    //PACMAN DYING SOUND
    sf::SoundBuffer dyingpac;
    if (!dyingpac.loadFromFile(resourcePath() + "pacman_death.wav")) {
        return EXIT_FAILURE;
    }
    sf::Sound die;
    die.setBuffer(dyingpac);
    
    //GAME OVER SONG
    sf::SoundBuffer theend;
    if (!theend.loadFromFile(resourcePath() + "deadpac.wav")) {
        return EXIT_FAILURE;
    }
    sf::Sound end;
    end.setBuffer(theend);
    
    //WINNER SONG
    sf::SoundBuffer wingame;
    if (!wingame.loadFromFile(resourcePath() + "pacwin.wav")) {
        return EXIT_FAILURE;
    }
    sf::Sound winnergame;
    winnergame.setBuffer(wingame);
    

    
    while (window.isOpen()) //OPENS MAIN MENU WINDOW
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                window.draw(sprite);
                case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                    case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                    case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;
                    case sf::Keyboard::Return:
                    switch(menu.GetPressedItem()){
                        case 0:
                        intro.play();
                        while(window.isOpen()){ // IF "PLAY" IS SELECTED THE GAME WINDOW WILL APPEAR
                            deltaTime = clock.restart().asSeconds();
                            sf::Event evnt;
                            while(window.pollEvent(evnt)){
                                switch (evnt.type){
                                    case sf::Event::Closed:
                                        window.close();
                                        break;
                                    case sf::Event::Resized:
                                        ResizeView(window, view);
                                        break;
                                    }
                                }
                            player.update(deltaTime);
                            //UPDATES RANDOM GHOST MOVEMENTS
                            for(int i = 0; i<4; i++){
                                ghosts[i].updateMovement(deltaTime);
                            }
                            //******************************* CHECK BOARD COLLISION *******************************
                            for(int i =0; i<22; i++){
                                gameBoard[i].GetCollider().CheckCollision(player.GetCollider(),1.0f);
                                //MAKES SURE THE GHOSTS DONT GO THROUGH THE WALL
                                gameBoard[i].GetCollider().CheckCollision(ghosts[0].GetCollider(),1.0f);
                                gameBoard[i].GetCollider().CheckCollision(ghosts[1].GetCollider(),1.0f);
                                gameBoard[i].GetCollider().CheckCollision(ghosts[2].GetCollider(),1.0f);
                                gameBoard[i].GetCollider().CheckCollision(ghosts[3].GetCollider(),1.0f);
                            }
                            //******************************* CHECK DOTS COLLISION *******************************
                            for(int i =0; i<135; i++){
                                if(Dots[i].GetCollider().CheckCollisionBall(player.GetCollider(),1.0f)){ //REMOVES BALLS IF PACMAN TOUCHES THEM
                                    eat.play();
                                    allBallsGone -= 1;
                                    if(allBallsGone == 0){
                                        winnergame.play();
                                        while(window.isOpen()){ // OPENS WINNER SCREEN IF PACMAN EATS ALL THE BALLS
                                            sf::Event evnt;
                                            while(window.pollEvent(evnt)){
                                                switch (evnt.type){
                                                    case sf::Event::Closed:
                                                    window.close();
                                                    break;
                                                }
                                            }
                                            window.clear();
                                            window.draw(win);
                                            window.display();
                                        }
                                    }
                
                                }
                            }
                            //******************************* CHECK GHOST COLLISION *******************************
                            for(int i = 0; i<4; i++){
                                if(ghosts[i].GetCollider().CheckCollisionGhost(player.GetCollider(), 1.0f)){ //IF GHOST TOUCH PACMAN, PACMAN LIVES GO DOWN BY 1
                                    die.play();
                                    //IF PACMAN TOUCHES GHOST THE GHOST GO BACK INTO THE BOX
                                    ghosts[0].GetCollider().Moveghost(50.0f,-75.0f);
                                    ghosts[1].GetCollider().Moveghost(50.0f,-75.0f);
                                    ghosts[2].GetCollider().Moveghost(50.0f,-75.0f);
                                    ghosts[3].GetCollider().Moveghost(50.0f,-75.0f);
                                    pacLives -= 1;
                                    if(pacLives == 0){
                                        end.play();
                                        while(window.isOpen()){ //OPENS LOSER SCREEN IF PACMAN LOSES ALL HIS BALLS
                                            sf::Event evnt;
                                            while(window.pollEvent(evnt)){
                                                switch (evnt.type){
                                                    case sf::Event::Closed:
                                                    window.close();
                                                    break;
                                                }
                                            }
                                            window.clear();
                                            window.draw(lose);
                                            window.display();
                                        }
                                    }
                                }
                            }
                            window.clear();
                            window.setView(view);
                            player.draw(window);
        
                            //****************************** DRAW Ghosts ******************************
                            for(int i = 0; i<4; i++){
                                ghosts[i].draw(window);
                            }
                            //****************************** DRAW BOARD ******************************
                            for(int i =0; i<22; i++){
                                gameBoard[i].Draw(window);
                            }
                            //****************************** DRAW DOTS ******************************
                            for(int i =0; i<135; i++){
                                Dots[i].Draw(window);
                            }
                            window.display();
                        }
                    }
                    break;

                }
                break;
                case sf::Event::Closed:
                window.close();
                
                break;
            }
            
        }
        
        // Clear screen
        window.clear();
        
        // Draw the sprite
        window.draw(sprite);
        
        // Draws Window
        menu.draw(window);
        
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
                    
