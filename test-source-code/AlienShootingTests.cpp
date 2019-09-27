#include "Alien.h"
#include "Bullet.h"
#include <doctest.h>

TEST_CASE("If an alien shoots, a bullet is returned")
{
	SUBCASE("The alien is facing up")
	{
		auto alien = Alien
		{ Orientation::FACE_UP };

		SUBCASE("If the alien shoots, a bullet is returned")
		{
			Bullet bullets = alien.shoot();
		}

	}

	SUBCASE("The alien is facing down")
	{
		auto alien = Alien
		{ Orientation::FACE_DOWN };

		SUBCASE("If the alien shoots once, one bullet is returned")
		{
			Bullet bullet = alien.shoot();
		}

	}
}

TEST_CASE("A bullet can move")
{
	SUBCASE("The alien is facing up")
	{
		auto alien = Alien
		{ Orientation::FACE_UP };

		auto [x_alien,y_alien] = alien.getPosition();

		Bullet bullet = alien.shoot();
		bullet.move();

		auto [x_bullet, y_bullet] = bullet.getPosition();

		CHECK(x_alien == x_bullet)
		;
		CHECK_FALSE(y_alien == y_bullet)
		;
		auto y_ref = y_alien
				- Constants::BULLET_MAXIMUM_MOVEMENT_STEP;

		CHECK(y_bullet == y_ref)
		;

	}

	SUBCASE("A alien is facing down")
	{
		auto alien = Alien
		{ Orientation::FACE_DOWN };

		auto [x_alien,y_alien] = alien.getPosition();

		Bullet bullet = alien.shoot();
		bullet.move();

		auto [x_bullet, y_bullet] = bullet.getPosition();

		CHECK(x_alien == x_bullet)
		;
		CHECK_FALSE(y_alien == y_bullet)
		;
		auto y_ref = y_alien
				+ Constants::BULLET_MAXIMUM_MOVEMENT_STEP;;

		CHECK(y_bullet == y_ref)
		;

	}
}

TEST_CASE("A bullet is deleted if it moves out of the screen")
{
	SUBCASE("The alien is facing up")
	{
		auto alien = Alien { Orientation::FACE_UP };

			Bullet bullet = alien.shoot();
		{

			auto &new_bullet = bullet;
			CHECK(bullet.getStatus())
			;
			auto endLoop = Constants::SCREEN_Y_LENGTH
					/ Constants::BULLET_MAXIMUM_MOVEMENT_STEP;

			for (auto i = 0u; i < endLoop; i++)
			{
				new_bullet.move();
			}

			CHECK_FALSE(new_bullet.getStatus())
			;

		}

	}

	SUBCASE("The alien is facing down")
	{
		auto alien = Alien { Orientation::FACE_DOWN };

			Bullet bullet = alien.shoot();
		{
			auto &new_bullet = bullet;
			CHECK(bullet.getStatus())
			;
			auto endLoop = Constants::SCREEN_Y_LENGTH
					/ Constants::BULLET_MAXIMUM_MOVEMENT_STEP;

			for (auto i = 0u; i < endLoop; i++)
			{
				new_bullet.move();
			}

			CHECK_FALSE(new_bullet.getStatus())
			;

		}

	}
}
