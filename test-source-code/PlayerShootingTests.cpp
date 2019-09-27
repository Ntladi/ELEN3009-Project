#include "Player.h"
#include "Bullet.h"
#include "StopWatch.h"
#include <doctest.h>

TEST_CASE("If a player shoots, a bullet is returned")
{
	SUBCASE("The player is facing up") {
		auto player = Player { Orientation::FACE_UP };

		SUBCASE("If a player does not shoot, no bullets are returned") {
			auto bullets = player.getShotsFired();
			CHECK(bullets.size() == 0)
			;
		}

		SUBCASE("If the player shoots once, one bullet is returned") {
			player.shoot();
			auto bullets = player.getShotsFired();
			CHECK(bullets.size() == 1)
			;
		}

		SUBCASE("If a player shoots multiple times, multiple bullets are returned") {
			player.shoot();
			player.shoot();
			player.shoot();
			auto bullets = player.getShotsFired();
			CHECK(bullets.size() == 3)
			;
		}

	}

	SUBCASE("The player is facing down") {
		auto player = Player { Orientation::FACE_DOWN };

		SUBCASE("If a player does not shoot, no bullets are returned") {
			auto bullets = player.getShotsFired();
			CHECK(bullets.size() == 0)
			;
		}

		SUBCASE("If the player shoots once, one bullet is returned") {
			player.shoot();
			auto bullets = player.getShotsFired();
			CHECK(bullets.size() == 1)
			;
		}

		SUBCASE("If a player shoots multiple times, multiple bullets are returned") {
			player.shoot();
			player.shoot();
			player.shoot();
			auto bullets = player.getShotsFired();
			CHECK(bullets.size() == 3)
			;
		}

	}
}

TEST_CASE("A bullet can move")
{
	SUBCASE("The player is facing up") {
		auto player = Player { Orientation::FACE_UP };
		auto [x_player,y_player] = player.getPosition();

		player.shoot();
		auto bullets = player.getShotsFired();
		bullets.at(0)->move();

		auto [x_bullet, y_bullet] = bullets.at(0)->getPosition();

		CHECK(x_player == x_bullet)
		;
		CHECK_FALSE(y_player == y_bullet)
		;
		auto y_ref = y_player
				- Constants::BULLET_MAXIMUM_MOVEMENT_STEP;

		CHECK(y_bullet == y_ref)
		;

	}

	SUBCASE("A player is facing down") {

		auto player = Player { Orientation::FACE_DOWN };
		auto [x_player,y_player] = player.getPosition();

		player.shoot();
		auto bullets = player.getShotsFired();
		bullets.at(0)->move();

		auto [x_bullet, y_bullet] = bullets.at(0)->getPosition();

		CHECK(x_player == x_bullet)
		;
		CHECK_FALSE(y_player == y_bullet)
		;
		auto y_ref = y_player
				+ Constants::BULLET_MAXIMUM_MOVEMENT_STEP;

		CHECK(y_bullet == y_ref)
		;

	}
}

TEST_CASE("A bullet is deleted if it moves out of the screen")
{
	SUBCASE("The player is facing up")
	{
		auto player = Player
		{	Orientation::FACE_UP};
		player.shoot();

		{
			auto bullets = player.getShotsFired();
			CHECK(bullets.size() == 1);

			auto &bullet = bullets.at(0);
			CHECK(bullet->getStatus())
			;
			auto endLoop = Constants::SCREEN_Y_LENGTH
			/ Constants::BULLET_MAXIMUM_MOVEMENT_STEP;

			for (auto i = 0u; i <endLoop; i++)
			{
				bullet->move();
			}


			CHECK_FALSE(bullet->getStatus());

		}

		auto bullets = player.getShotsFired();
		CHECK(bullets.size()==0);

	}

	SUBCASE("The player is facing down")
	{
		auto player = Player
		{	Orientation::FACE_DOWN};
		player.shoot();

		{
			auto bullets = player.getShotsFired();
			CHECK(bullets.size() == 1);

			auto &bullet = bullets.at(0);
			CHECK(bullet->getStatus())
			;
			auto endLoop = Constants::SCREEN_Y_LENGTH
			/ Constants::BULLET_MAXIMUM_MOVEMENT_STEP;

			for (auto i = 0u; i <endLoop; i++)
			{
				bullet->move();
			}


			CHECK_FALSE(bullet->getStatus());

		}

		auto bullets = player.getShotsFired();
		CHECK(bullets.size()==0);

	}

}

TEST_CASE("A power up is achieved")
{
	SUBCASE("Dual shot single bullet")
	{
		StopWatch watch;
		auto player = Player
		{	Orientation::FACE_UP};
		watch.start();
		std::cout << "\nPlease wait an additional " << Constants::TIME_BEFORE_1ST_POWER_UP
				+ Constants::TIME_BEFORE_2ND_POWER_UP << " seconds for shooting tests to complete" << std::endl;
		while(watch.getTimeElapsed() <= Constants::TIME_BEFORE_1ST_POWER_UP)
		{

		}
		player.shoot();
		CHECK(player.getShotsFired().size() == 2);

	}

	SUBCASE("Dual shot piercer bullet")
	{
		StopWatch watch;
		auto player = Player
		{	Orientation::FACE_UP};
		watch.start();

		while(watch.getTimeElapsed() <= Constants::TIME_BEFORE_2ND_POWER_UP)
		{

		}
		player.shoot();
		CHECK(player.getShotsFired().size() == 3);
		CHECK(player.getShotsFired().at(0)->getObjectType() == ObjectType::PIERCER_BULLET);
		CHECK(player.getShotsFired().at(1)->getObjectType() == ObjectType::PIERCER_BULLET);
		CHECK(player.getShotsFired().at(2)->getObjectType() == ObjectType::PIERCER_BULLET);

	}


}
