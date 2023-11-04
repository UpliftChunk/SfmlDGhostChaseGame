#include  "SFML/Graphics.hpp" // replace quotes with less than and greater than symbols
#include  <iostream>
#include  "Player.h"
#include  "StopBlock.h"
#include  "Collider.h"
#include  "EnemyGhost.h"

static const float VIEW_HEIGHT = 1080.0f;
char seconds[2] = { '0','0' };
void conFtoStr(float s) {
    int b = int(s);
    seconds[1] = 48 + b % 10;
    b = b / 10;
    seconds[0] = 48 + (b % 10);
}
void ResizeView(const sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = float(window.getSize().x / float(window.getSize().y));
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(1080.0f, 1080.0f), "SFML practice", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    sf::RectangleShape WholeMap(sf::Vector2f(1080.0f, 1080.0f));

    sf::Texture playerTexture, objectTexture, enemyTexture;
    playerTexture.loadFromFile("CharacterAllMovements.png");
    enemyTexture.loadFromFile("enemyAllMovement.png");
    objectTexture.loadFromFile("objectBasicBoundary.png");
    sf::Texture MapTexture;
    MapTexture.loadFromFile("Map1Final.png");
    WholeMap.setTexture(&MapTexture);
    WholeMap.setOrigin(WholeMap.getSize() / 2.0f);

    Player player(&playerTexture, sf::Vector2u(4, 5), 0.3f, 200.0f);
    EnemyGhost Ghost1(&enemyTexture, sf::Vector2u(4, 3), 0.3f, 155.0f);

    StopBlock object1(nullptr, sf::Vector2f(130.0f, 130.0f), sf::Vector2f(-180.0f, 230.0f));
    StopBlock object2(nullptr, sf::Vector2f(130.0f, 130.0f), sf::Vector2f(-320.0f, -300.0f));
    StopBlock object3(nullptr, sf::Vector2f(130.0f, 130.0f), sf::Vector2f(182.0f, 110.5f));
    StopBlock object4(nullptr, sf::Vector2f(130.0f, 130.0f), sf::Vector2f(265.0f, -220.0f));
    Collider ofPlayer = player.GetCollider();


    sf::Font font;
    if (!font.loadFromFile("./MontserratFont/Montserrat-Regular.otf")) {
        std::cout << "Error loading file" << std::endl;
        system("pause");
    };
    sf::Text scoreCounter, Score;
    scoreCounter.setFont(font);
    scoreCounter.setString(seconds);
    scoreCounter.setCharacterSize(50);
    scoreCounter.setPosition(330.0f, -500.0f);
    scoreCounter.setFillColor(sf::Color::White);
    Score.setFont(font);
    Score.setString("Score: ");
    Score.setCharacterSize(50);
    Score.setFillColor(sf::Color::White);
    Score.setPosition(180.0f, -500.0f);

    float deltaTime = 0.0f;
    sf::Clock clock, clockBegin;
    sf::Time elapsed1 = clockBegin.getElapsedTime();

    while (window.isOpen()) {

        deltaTime = clock.restart().asSeconds();
        sf::Event event1;
        while (window.pollEvent(event1)) {
            switch (event1.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    printf("New window width: %i \tNew window height: %i\n", event1.size.width, event1.size.height);
                    ResizeView(window, view);
                    break;
                case sf::Event::TextEntered:
                    if(event1.text.unicode<128)
                    {
                        printf("%c", event1.text.unicode);
                    }
                    break;
                
            }
        }

        elapsed1 = clockBegin.getElapsedTime();
        float timeinSeconds = elapsed1.asSeconds();
        conFtoStr(timeinSeconds);
        scoreCounter.setString(seconds);
        /* 0-down 1-left 2-right 3-up 4-still */

        player.Update(deltaTime);
        Ghost1.Update(deltaTime, player.GetPosition());
        object1.GetCollider().CheckCollision(ofPlayer, 1.0f);
        object2.GetCollider().CheckCollision(ofPlayer, 1.0f);
        object3.GetCollider().CheckCollision(ofPlayer, 1.0f);
        object4.GetCollider().CheckCollision(ofPlayer, 1.0f);
        // view.setCenter(player.GetPosition());
        window.clear();
        // window.clear(sf::Color(200, 200, 130, 2));
        // window.clear(sf::Color(30,30,30,1));
        window.setView(view);
        window.draw(WholeMap);
        object1.Draw(window);
        object2.Draw(window);
        object3.Draw(window);
        object4.Draw(window);
        player.Draw(window);
        Ghost1.Draw(window);
        window.draw(Score);
        window.draw(scoreCounter);
        window.display();
    }

    return 0;
}