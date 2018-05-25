#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#define ROW 10
#define COL 10



int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::RectangleShape shape(sf::Vector2f(100 * ROW, 100 * COL));
	shape.setFillColor(sf::Color::Green);
	sf::RectangleShape arr[ROW][COL];
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			
			sf::RectangleShape cell(sf::Vector2f(98, 98));
			cell.setPosition(501 - ROW * 50 + i*100 , 501 - COL * 50 + j*100);
			cell.setFillColor(sf::Color::White);
			arr[i][j] = cell;
		}
	}
	sf::Texture texture;
	if (!texture.loadFromFile("player.png"))
	{
		cout << "Failed to load player spritesheet!" << endl;
		return 1;
	}
	shape.setPosition(500 - ROW * 50, 500 - COL * 50);
	


	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(200-16,200 - 16);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	/*
	if (!texture.loadFromFile("grass-texture.jpg", sf::IntRect(0,0,130,130)))
	{
		sprite.setTexture(texture);
	}*/
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)//sf::Keyboard::Escape
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left) {
					sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
					sprite.move(sf::Vector2f(-10, 0));
				}
				if (event.key.code == sf::Keyboard::Right) {
					sprite.move(sf::Vector2f(10, 0));
					sprite.setTextureRect(sf::IntRect(32, 64, 32, 32));

				}
				if (event.key.code == sf::Keyboard::Down) {
					sprite.move(sf::Vector2f(0, 10));
					sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
				}
				if (event.key.code == sf::Keyboard::Up) {
					sprite.move(sf::Vector2f(0, -10));
					
					sprite.setTextureRect(sf::IntRect(32, 96, 32, 32));
				}
			}
		}

		window.clear();
		window.draw(shape);
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {

				window.draw(arr[i][j]);
				
			}
		}
		
		window.draw(sprite);
		window.display();
	}

	return 0;
}