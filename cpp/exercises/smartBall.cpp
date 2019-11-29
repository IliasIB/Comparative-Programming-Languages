# include "smartBall.h"


namespace pongShapes {
    SmartBall::SmartBall(sf::Vector2u windowSize, float radius, utils::RoundResult& resultW, sf::Shape& leftPlayerW, sf::Shape& rightPlayerW) : result(resultW), leftPlayer(leftPlayerW), rightPlayer(rightPlayerW) {
        this->ball = sf::CircleShape(radius);
        this->ball.setPosition(utils::middlePosition(this->ball));
        this->speedY = 0;
        this->speedX = 1;
        this->windowSize = windowSize;
    }

    void SmartBall::move() {
        sf::Vector2f currentPos = this->ball.getPosition();
        sf::Vector2f newPos = currentPos + sf::Vector2f(speedX, speedY);
        sf::CircleShape tempBall = sf::CircleShape(this->ball.getRadius());
        tempBall.setPosition(newPos);
        
        if (utils::isOutOfWindow(this->windowSize, tempBall)) {
            bounce(true);
            newPos = currentPos + sf::Vector2f(speedX, speedY);
        }
        else {
            this->ball.setPosition(newPos);
        }
    }
    void SmartBall::bounce(bool outOfWindow) {
        if (outOfWindow) {
            switch(utils::outOfWindow(this->windowSize, this->ball)) {
                case utils::WindowSide::TOP: case utils::WindowSide::BOTTOM:
                    this->speedY = -this->speedY;
                case utils::WindowSide::LEFT: case utils::WindowSide::RIGHT:
                    this->speedX = -this->speedX;
                case utils::WindowSide::INSIDE:
                    break;
            }
        }
        else {
            return;
        }
        
    }
    
    void SmartBall::reset(float posX, float posY, float speedX, float speedY) {
        this->ball.setPosition(posX, posY);
        this->speedY = speedY;
        this->speedX = speedX;
    }
    
    bool SmartBall::getMatchOver() {
        return this->matchOver;
    }
    
    bool SmartBall::getLeftWon() {
        return this->leftWon;
    }
    sf::Shape& SmartBall::getBall() {
        return this->ball;
    }
}
