#ifndef SMART_BALL_INCLUDE
#define SMART_BALL_INCLUDE
#include <SFML/Graphics.hpp>
# include "pongUtils.h"

namespace pongShapes {
    class SmartBall {
    private:
        float speedX;
        float speedY;
        bool matchOver;
        bool leftWon;
        utils::RoundResult result;
        sf::Vector2u windowSize;
        sf::CircleShape ball;
        sf::Shape& leftPlayer;
        sf::Shape& rightPlayer;
    public:
        SmartBall(sf::Vector2u windowSize, float radius, utils::RoundResult& resultW, sf::Shape& leftPlayerW, sf::Shape& rightPlayerW);
        void move();
        void bounce(bool outOfWindow);
        void reset(float posX, float posY, float speedX, float speedY);
        bool getMatchOver();
        bool getLeftWon();
        sf::Shape& getBall();
    };
}
#endif
