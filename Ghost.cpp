#include "Ghost.hpp"

Ghost::Ghost(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed): animation(texture,imageCount,switchTime){
    this->speed  = speed;
    row = 0;
    faceRight= 0;
    
    body.setSize(sf::Vector2f(100.0f,100.0f));//creates a box named box
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(-300.0f,-75.0f);
    body.setTexture(texture);
    
}
Ghost::~Ghost(){
    
}
void Ghost::draw(sf::RenderWindow& window){
    window.draw(body);
    
}


void Ghost::updateMovement(float deltaTime){
    sf::Vector2f movement(0.0f, 0.0f);
        if(direction == 1 || direction == 9 || direction ==15 || direction ==6){ //MOVES GHOST UP IF RANDOM GENRATOR PICKS ANY OF THESE NUMBERS.
            body.move(0.0f,-movementSpeed);
            row = 2;
        }

        if(direction == 2 || direction == 5 || direction == 16 || direction == 12){//MOVES GHOST DOWN IF RANDOM GENRATOR PICKS ANY OF THESE NUMBERS.
            body.move(0.0f, movementSpeed);
            row =3;
        }
    
        if(direction == 3 || direction ==7 || direction == 13 || direction == 10){//MOVES GHOST LEFT IF RANDOM GENRATOR PICKS ANY OF THESE NUMBERS.
            body.move(-movementSpeed, 0.0f);
            row=1;
        }
        if(direction == 4 || direction == 8 || direction == 14 || direction == 11){//MOVES GHOST RIGHT IF RANDOM GENRATOR PICKS ANY OF THESE NUMBERS.
            body.move(movementSpeed,0.0f);
            row = 0;
        }
        if(direction == 4 || direction == 8 || direction == 14 || direction == 11){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){//MOVES SPRITE UP IF BUTTON IS CLICKED
                body.move(0.0f,-movementSpeed);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){//MOVES SPRITE DOWN IF BUTTON IS CLICKED
                body.move(0.0f, movementSpeed);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){//MOVES SPRITE LEFT IF BUTTON IS CLICKED
                body.move(-movementSpeed, 0.0f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){//MOVES SPRITE RIGHTS IF BUTTON IS CLICKED
                body.move(movementSpeed,0.0f);
            }
        }


    
    counter++;
    if(counter >= movementLength){ //CALLS NUNMBERS FROM RANDOM GENERATOR.
        counter =0;
        direction = generateRandom(16);
    }
    
    if(row == 0){ //MOVES THE GHOST FACE TO EITHIER DIRECTION THAT IS CALLED.
        faceRight = 1;
    }
    else if(row ==2){
        faceRight = 2;
    }
    else if(row ==1){
        faceRight = 3;
    }
    else if(row ==3){
        faceRight = 4;
    }
    
    animation.update(row,deltaTime,faceRight);
    body.setTextureRect(animation.uvrect);
    body.move(movement);
}
