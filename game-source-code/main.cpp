#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Constants.h"
#include "Orientation.h"
#include "MoveDirection.h"
#include "Armada.h"
#include "ScreenStates.h"
#include "SeperatingAxisTheorem.h"
#include "HitBox.h"
#include <iostream>
using namespace sf;

int main() {
	auto screenState = ScreenStates::SPLASHSCREEN;
	auto x_bullet_size = Constants::PLAYER_BULLET_X_LENGTH;
	auto y_bullet_size = Constants::PLAYER_BULLET_Y_LENGTH;

	Player player1 = Player { Orientation::FACE_UP };
	Player player2 = Player { Orientation::FACE_DOWN };

	Armada upArmada = Armada { Orientation::FACE_UP };
	Armada downArmada = Armada { Orientation::FACE_DOWN };

	SeperatingAxisTheorem axisTheorem = SeperatingAxisTheorem{};

	auto [player1x,player1y] = player1.getSize();
	auto [player1xp,player1yp] = player1.getPosition();

	auto [player2x,player2y] = player2.getSize();
	auto [player2xp,player2yp] = player2.getPosition();

	auto [upAlienx,upAlieny] = upArmada.getAlienSize();
	auto [downAlienx,downAlieny] = downArmada.getAlienSize();

	RenderWindow window(
			VideoMode(Constants::SCREEN_X_LENGTH, Constants::SCREEN_Y_LENGTH),
			"Dual Invaders", Style::Close);

	Texture upPlayer_texture;
	upPlayer_texture.loadFromFile("Assets/Player1.png");

	Texture downPlayer_Texture;
	downPlayer_Texture.loadFromFile("Assets/Player2.png");

	Texture upAlien_texture;
	upAlien_texture.loadFromFile("Assets/Alien1.png");

	Texture downAlien_texture;
	downAlien_texture.loadFromFile("Assets/Alien2.png");

	Texture upbullet_texture;
	upbullet_texture.loadFromFile("Assets/Player1Bullet.png");

	Texture downbullet_texture;
	downbullet_texture.loadFromFile("Assets/Player2Bullet.png");

	Texture splashScreen_texture;
	splashScreen_texture.loadFromFile("Assets/SplashScreen.jpg");

	Texture backgroundScreen_texture;
	backgroundScreen_texture.loadFromFile("Assets/BackgroundScreen.jpg");

	Texture gameOverScreen_texture;
	gameOverScreen_texture.loadFromFile("Assets/GameOverScreen.jpg");

	RectangleShape upPlayer(Vector2f(player1x, player1y));
	upPlayer.setPosition(Vector2f(player1xp, player1yp));
	upPlayer.setOrigin(Vector2f(player1x / 2, player1y / 2));
	upPlayer.setTexture(&upPlayer_texture);

	RectangleShape downPlayer(Vector2f(player2x, player2y));
	downPlayer.setPosition(Vector2f(player2xp, player2yp));
	downPlayer.setOrigin(Vector2f(player2x / 2, player2y / 2));
	downPlayer.setTexture(&downPlayer_Texture);
	downPlayer.setRotation(180.0f);

	RectangleShape upAlien(Vector2f(upAlienx, upAlieny));
	upAlien.setOrigin(Vector2f(upAlienx / 2, upAlieny / 2));
	upAlien.setTexture(&upAlien_texture);

	RectangleShape downAlien(Vector2f(downAlienx, downAlieny));
	downAlien.setOrigin(Vector2f(downAlienx / 2, downAlieny / 2));
	downAlien.setTexture(&downAlien_texture);
	downAlien.setRotation(180.0f);

	RectangleShape upBullet(Vector2f(x_bullet_size, y_bullet_size));
	upBullet.setOrigin(Vector2f(x_bullet_size / 2, y_bullet_size / 2));
	upBullet.setTexture(&upbullet_texture);

	RectangleShape downBullet(Vector2f(x_bullet_size, y_bullet_size));
	downBullet.setOrigin(Vector2f(x_bullet_size / 2, y_bullet_size / 2));
	downBullet.setTexture(&downbullet_texture);
	downBullet.setRotation(180.0f);


	RectangleShape splashScreen(Vector2f(Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH));
	splashScreen.setTexture(&splashScreen_texture);

	RectangleShape backgroundScreen(Vector2f(Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH));
	backgroundScreen.setTexture(&backgroundScreen_texture);

	RectangleShape gameOverScreen(Vector2f(Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH));
	gameOverScreen.setTexture(&gameOverScreen_texture);

	auto fire1 = false;
	auto fire2 = false;
	auto stopwatch1 = StopWatch{};
	auto stopwatch2 = StopWatch{};
	stopwatch1.start();
	stopwatch2.start();
	while (window.isOpen()) {
		Event evnt1;
		while (window.pollEvent(evnt1)) {
			switch (evnt1.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (screenState == ScreenStates::SPLASHSCREEN
						&& Keyboard::isKeyPressed(Keyboard::Enter))
					screenState = ScreenStates::GAME_SCREEN;
				break;
			case Event::KeyReleased:
				if (fire1)
					player1.shoot();
				fire1 = false;
				if (fire2)
					player2.shoot();
				fire2 = false;
				break;

			default:
				break;
			}

		}

		if (screenState == ScreenStates::SPLASHSCREEN) {
			window.clear(Color::Black);
			window.draw(splashScreen);
		}

		else if (screenState == ScreenStates::GAME_SCREEN) {

			window.clear(Color::Black);
			window.draw(backgroundScreen);

			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				player1.setMoveDirection(MoveDirection::LEFT);
				player1.move();
				auto [newx, newy] = player1.getPosition();
				upPlayer.setPosition(Vector2f(newx, newy));
			} else if (Keyboard::isKeyPressed(Keyboard::Right)) {
				player1.setMoveDirection(MoveDirection::RIGHT);
				player1.move();
				auto [newx, newy] = player1.getPosition();
				upPlayer.setPosition(Vector2f(newx, newy));
			}

			if (Keyboard::isKeyPressed(Keyboard::Space) && stopwatch1.getTimeElapsed() > 0.3) {
				fire1 = true;
				stopwatch1.start();
			}
			if (Keyboard::isKeyPressed(Keyboard::A)) {
				player2.setMoveDirection(MoveDirection::LEFT);
				player2.move();
				auto [newx, newy] = player2.getPosition();
				downPlayer.setPosition(Vector2f(newx, newy));
			} else if (Keyboard::isKeyPressed(Keyboard::D)) {
				player2.setMoveDirection(MoveDirection::RIGHT);
				player2.move();
				auto [newx, newy] = player2.getPosition();
				downPlayer.setPosition(Vector2f(newx, newy));
			}
			if (Keyboard::isKeyPressed(Keyboard::Q) ) {
				fire2 = true;
				stopwatch2.start();
			}

			auto aliens_from_up = upArmada.getArmada();
			auto aliens_from_down = downArmada.getArmada();


			if(aliens_from_up.size() > 0)
			{
				for (auto &i : aliens_from_up) {
					//i->move();
					auto[x_alien_up_position,y_alien_up_position] = i->getPosition();
					upAlien.setPosition(
							Vector2f(x_alien_up_position, y_alien_up_position));
					window.draw(upAlien);
				}
			}

			if(aliens_from_down.size() > 0)
			{
				for (auto &i : aliens_from_down) {
					//i->move();
					auto[x_alien_down_position,y_alien_down_position] = i->getPosition();
					downAlien.setPosition(
							Vector2f(x_alien_down_position, y_alien_down_position));
					window.draw(downAlien);

				}

			}


			auto shots_from_1 = player1.getShotsFired();
			auto shots_from_2 = player2.getShotsFired();

			auto shots_from_up_armada = upArmada.getOnslaught();
			auto shots_from_down_armada = downArmada.getOnslaught();

			for (auto &i : shots_from_1) {
				i->move();
				auto [x_bullet_position, y_bullet_position] = i->getPosition();
				upBullet.setPosition(
						Vector2f(x_bullet_position, y_bullet_position));
				window.draw(upBullet);
			}

			for (auto &i : shots_from_up_armada) {
				i->move();
				auto [x_bullet_position, y_bullet_position] = i->getPosition();
				upBullet.setPosition(
						Vector2f(x_bullet_position, y_bullet_position));
				window.draw(upBullet);
			}

			for (auto &i : shots_from_2) {
				i->move();
				auto [x_bullet_position, y_bullet_position] = i->getPosition();
				downBullet.setPosition(
						Vector2f(x_bullet_position, y_bullet_position));
				window.draw(downBullet);

			}

			for (auto &i : shots_from_down_armada) {
				i->move();
				auto [x_bullet_position, y_bullet_position] = i->getPosition();
				downBullet.setPosition(
						Vector2f(x_bullet_position, y_bullet_position));
				window.draw(downBullet);

			}

			if(shots_from_1.size() > 0)
			{
				for(auto &j:shots_from_1)
				{

					auto BulletHitBox = j->getHitBox();
					for(auto &i:aliens_from_down)
					{
						auto AlienHitBox = i->getHitBox();
						if(axisTheorem.isOverlapping(BulletHitBox,AlienHitBox))
						{
							j->killEntity();
							std::cout << "Objects killed" << std::endl;
							i->killEntity();
						}

					}

					for(auto &i:aliens_from_up)
					{
						auto AlienHitBox = i->getHitBox();
						if(axisTheorem.isOverlapping(BulletHitBox,AlienHitBox))
						{
							j->killEntity();
							i->killEntity();
							std::cout << "Objects killed" << std::endl;
						}

					}
				}

			}

			if(shots_from_2.size() > 0)
			{

				for(auto &j:shots_from_2)
				{

					auto BulletHitBox = j->getHitBox();

					for(auto &i:aliens_from_down)
					{
						auto AlienHitBox = i->getHitBox();
						if(axisTheorem.isOverlapping(BulletHitBox,AlienHitBox))
						{
							j->killEntity();
							i->killEntity();
							std::cout << "Objects killed" << std::endl;
						}

					}

					for(auto &i:aliens_from_up)
					{
						auto AlienHitBox = i->getHitBox();
						if(axisTheorem.isOverlapping(BulletHitBox,AlienHitBox))
						{
							j->killEntity();
							i->killEntity();
							std::cout << "Objects killed" << std::endl;
						}

					}
				}
			}

			if (upArmada.isGameOver())
				screenState = ScreenStates::GAME_OVER;
			if (downArmada.isGameOver())
				screenState = ScreenStates::GAME_OVER;

			window.draw(upPlayer);
			window.draw(downPlayer);
		}

		else if(screenState == ScreenStates::GAME_OVER)
		{
			window.clear(Color::Black);
			window.draw(gameOverScreen);

		}

		window.display();
	}
}
