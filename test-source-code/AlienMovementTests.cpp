#include "Alien.h"

#include <doctest.h>

TEST_CASE("An alien can be created in the correct orientation")
{
	SUBCASE("The alien is facing up")
	{
		auto alien = Alien
		{ Orientation::FACE_UP };
		auto orientation = alien.getOrientation();
		CHECK(orientation == Orientation::FACE_UP)
		;
	}

	SUBCASE("The alien is facing down")
	{
		auto alien = Alien
		{ Orientation::FACE_DOWN };
		auto orientation = alien.getOrientation();
		CHECK(orientation == Orientation::FACE_DOWN)
		;
	}

}

TEST_CASE("An alien can be created with the correct size")
{
	SUBCASE("The alien is facing up")
	{
		auto alien = Alien
		{ Orientation::FACE_UP };
		auto x_size_ref = alien.getParameters().getXLength();
		auto y_size_ref = alien.getParameters().getYHeight();
		auto [x_size,y_size] = alien.getSize();

		CHECK(x_size == x_size_ref)
		;
		CHECK(y_size == y_size_ref)
		;
	}

	SUBCASE("The alien is facing down")
	{
		auto alien = Alien
		{ Orientation::FACE_DOWN };
		auto x_size_ref = alien.getParameters().getXLength();
		auto y_size_ref = alien.getParameters().getYHeight();
		auto [x_size,y_size] = alien.getSize();

		CHECK(x_size == x_size_ref)
		;
		CHECK(y_size == y_size_ref)
		;
	}

}

TEST_CASE("An alien can be created with the correct Position")
{
	SUBCASE("The alien is facing up")
	{
		auto alien = Alien
		{ Orientation::FACE_UP };
		auto [x_position, y_position] = alien.getPosition();
		auto x_position_ref = alien.getParameters().getXLength() / 2;
		auto y_position_ref = alien.getParameters().getScreenYHeight() / 2
				- alien.getParameters().getYHeight() / 2 - 5;

		CHECK(x_position == x_position_ref)
		;
		CHECK(y_position == y_position_ref)
		;
	}

	SUBCASE("The alien is facing down")
	{
		auto alien = Alien
		{ Orientation::FACE_DOWN };
		auto [x_position, y_position] = alien.getPosition();
		auto x_position_ref = alien.getParameters().getXLength() / 2;
		auto y_position_ref = alien.getParameters().getScreenYHeight() / 2
				+ alien.getParameters().getYHeight() / 2 + 5;

		CHECK(x_position == x_position_ref)
		;
		CHECK(y_position == y_position_ref)
		;

	}
}

TEST_CASE("An alien can move across the screen")
{
	SUBCASE("The alien is facing up")
	{
		auto alien = Alien
		{ Orientation::FACE_UP };

		SUBCASE("Alien moves one position to the right")
		{
			auto [x_initial, y_initial] = alien.getPosition();
			alien.move();
			auto [x_final, y_final] = alien.getPosition();

			CHECK(y_initial == y_final)
			;
			CHECK_FALSE(x_initial == x_final)
			;

			auto x_increment = x_initial
					+ alien.getParameters().getMovementStep();

			CHECK(x_final == x_increment)
			;

		}
	}
	SUBCASE("The alien is facing down")
	{
		auto alien = Alien
		{ Orientation::FACE_DOWN };

		SUBCASE("Alien moves one position to the right")
		{
			auto [x_initial, y_initial] = alien.getPosition();
			alien.move();
			auto [x_final, y_final] = alien.getPosition();

			CHECK(y_initial == y_final)
			;
			CHECK_FALSE(x_initial == x_final)
			;

			auto x_increment = x_initial
					+ alien.getParameters().getMovementStep();

			CHECK(x_final == x_increment)
			;

		}

	}
}

TEST_CASE("The alien moves vertically if it is at the end of the screen")
{

	SUBCASE("The alien is facing up")
	{
		auto alien = Alien{Orientation::FACE_UP};

		auto loopStop = (alien.getParameters().getScreenXLength() / alien.getParameters().getMovementStep());
		auto y_initial = std::get<1>(alien.getPosition());
		for(auto i=0; i<loopStop; i++)
		{
			alien.move();
		}

		auto y_final = std::get<1>(alien.getPosition());
		CHECK_FALSE(y_initial == y_final);

		auto increment = y_initial - alien.getParameters().getYHeight();

		CHECK(y_final == increment);

	}

	SUBCASE("The alien is facing down")
	{
		auto alien = Alien{Orientation::FACE_DOWN};

		auto loopStop = (alien.getParameters().getScreenXLength() / alien.getParameters().getMovementStep());
		auto y_initial = std::get<1>(alien.getPosition());
		for(auto i=0; i<loopStop; i++)
		{
			alien.move();
		}

		auto y_final = std::get<1>(alien.getPosition());
		CHECK_FALSE(y_initial == y_final);

		auto increment = y_initial + alien.getParameters().getYHeight();

		CHECK(y_final == increment);

	}
}
