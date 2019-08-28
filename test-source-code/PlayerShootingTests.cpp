#include "Player.h"
#include "Bullet.h"
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
				- bullets.at(0)->getParameters().getMovementStep();

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
				+ bullets.at(0)->getParameters().getMovementStep();

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
			auto endLoop = bullet->getParameters().getScreenYHeight()
			/ bullet->getParameters().getMovementStep();

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
