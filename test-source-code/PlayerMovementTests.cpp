#include "Player.h"
#include <algorithm>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

TEST_CASE("A player can be created in the correct orientation")
{
	SUBCASE("The player is facing up")
	{
		auto player = Player
		{ Orientation::FACE_UP };
		auto orientation = player.getOrientation();
		CHECK(orientation == Orientation::FACE_UP)
		;
	}

	SUBCASE("Player is facing down")
	{
		auto player = Player
		{ Orientation::FACE_DOWN };
		auto orientation = player.getOrientation();
		CHECK(orientation == Orientation::FACE_DOWN)
		;
	}

}

TEST_CASE("A player can be created with the correct size")
{
	SUBCASE("The player is facing up")
	{
		auto player = Player
		{ Orientation::FACE_UP };
		auto[x_size,y_size] = player.getSize();

		auto x_size_ref = player.getParameters().getXLength();
		auto y_size_ref = player.getParameters().getYHeight();
		CHECK(x_size == x_size_ref)
		;
		CHECK(y_size == y_size_ref)
		;
	}
	SUBCASE("The player is facing down")
	{
		auto player = Player
		{ Orientation::FACE_DOWN };
		auto[x_size,y_size] = player.getSize();

		auto x_size_ref = player.getParameters().getXLength();
		auto y_size_ref = player.getParameters().getYHeight();
		CHECK(x_size == x_size_ref)
		;
		CHECK(y_size == y_size_ref)
		;
	}

}

TEST_CASE("A player can be created with the correct position")
{
	auto x_position_ref = Constants::PLAYER_INITAL_X_POSITION;

	SUBCASE("The player is facing up")
	{
		auto player = Player
		{ Orientation::FACE_UP };
		auto [x_position,y_position] = player.getPosition();
		auto y_position_ref = player.getParameters().getScreenYHeight()
				- player.getParameters().getYHeight() / 2;

		CHECK(x_position == x_position_ref)
		;
		CHECK(y_position == y_position_ref)
		;
	}

	SUBCASE("The player is facing down")
	{
		auto player = Player
		{ Orientation::FACE_DOWN };
		auto [x_position,y_position] = player.getPosition();
		auto y_position_ref = player.getParameters().getYHeight() / 2;

		CHECK(x_position == x_position_ref)
		;
		CHECK(y_position == y_position_ref)
		;
	}
}

TEST_CASE("A player on the screen can move left")
{
	SUBCASE("The player is facing down")
	{
		auto player = Player
		{ Orientation::FACE_DOWN };
		auto[x_initial_position, y_initial_position] = player.getPosition();
		player.setMoveDirection(MoveDirection::LEFT);
		player.move();
		auto[x_final_position, y_final_position] = player.getPosition();

		SUBCASE("The player is not in the same position")
		{
			CHECK_FALSE(x_initial_position == x_final_position)
			;
		}

		SUBCASE("The player has not moved vertically")
		{
			CHECK(y_initial_position == y_final_position)
			;
		}

		SUBCASE("The player has moved by the correct increment")
		{
			auto increment = x_initial_position
					- player.getParameters().getMovementStep();
			CHECK(x_final_position == increment)
			;
		}

	}
	SUBCASE("The player is facing up")
	{
		auto player = Player
		{ Orientation::FACE_UP };
		auto[x_initial_position, y_initial_position] = player.getPosition();
		player.setMoveDirection(MoveDirection::LEFT);
		player.move();
		auto[x_final_position, y_final_position] = player.getPosition();
		auto increment = x_initial_position
				- player.getParameters().getMovementStep();

		CHECK_FALSE(x_initial_position == x_final_position)
		;
		CHECK(y_initial_position == y_final_position)
		;
		CHECK(x_final_position == increment)
		;
	}
}

TEST_CASE("A player can move right")
{
	SUBCASE("The player is facing down")
	{
		auto player = Player
		{ Orientation::FACE_DOWN };
		auto[x_initial_position, y_initial_position] = player.getPosition();
		player.setMoveDirection(MoveDirection::RIGHT);
		player.move();
		auto[x_final_position, y_final_position] = player.getPosition();
		auto increment = x_initial_position
				+ player.getParameters().getMovementStep();

		CHECK_FALSE(x_initial_position == x_final_position)
		;
		CHECK(y_initial_position == y_final_position)
		;
		CHECK(x_final_position == increment)
		;

	}
	SUBCASE("The player is facing up")
	{
		auto player = Player
		{ Orientation::FACE_UP };
		auto[x_initial_position, y_initial_position] = player.getPosition();
		player.setMoveDirection(MoveDirection::RIGHT);
		player.move();
		auto[x_final_position, y_final_position] = player.getPosition();
		auto increment = x_initial_position
				+ player.getParameters().getMovementStep();

		CHECK_FALSE(x_initial_position == x_final_position)
		;
		CHECK(y_initial_position == y_final_position)
		;
		CHECK(x_final_position == increment)
		;
	}

}

TEST_CASE("A player does not exceed the left boundary")
{
	SUBCASE("The player is facing down")
	{
		auto player = Player
		{ Orientation::FACE_DOWN };

		auto x_reference1 = player.getParameters().getXLength() / 2;
		auto x_reference2 = player.getParameters().getXLength();

		auto end_loop = player.getParameters().getXposition()
				/ player.getParameters().getMovementStep();

		for (auto i = 0u; i < end_loop; i++)
		{
			player.setMoveDirection(MoveDirection::LEFT);
			player.move();
		}

		auto [x_position, y_position] = player.getPosition();
		CHECK_FALSE(x_position == y_position)
		;
		CHECK(x_position > x_reference1)
		;
		CHECK(x_position < x_reference2)
		;
	}

	SUBCASE("The player is facing up")
	{
		auto player = Player
		{ Orientation::FACE_UP };

		auto x_reference1 = player.getParameters().getXLength() / 2;
		auto x_reference2 = player.getParameters().getXLength();

		auto end_loop = player.getParameters().getXposition()
				/ player.getParameters().getMovementStep();

		for (auto i = 0u; i < end_loop; i++)
		{
			player.setMoveDirection(MoveDirection::LEFT);
			player.move();
		}

		auto [x_position, y_position] = player.getPosition();
		CHECK_FALSE(x_position == y_position)
		;
		CHECK(x_position > x_reference1)
		;
		CHECK(x_position < x_reference2)
		;
	}
}

TEST_CASE("A player does not exceed the right boundary")
{
	SUBCASE("The player is facing down")
	{

		auto player = Player
		{ Orientation::FACE_DOWN };

		auto end_loop = player.getParameters().getXposition()
				/ player.getParameters().getMovementStep();

		auto x_reference1 = player.getParameters().getScreenXLength()
				- player.getParameters().getXLength() / 2;
		auto x_reference2 = player.getParameters().getScreenXLength()
				- player.getParameters().getXLength();

		for (auto i = 0u; i < end_loop; i++)
		{
			player.setMoveDirection(MoveDirection::RIGHT);
			player.move();
		}

		auto [x_position, y_position] = player.getPosition();
		CHECK_FALSE(x_position == y_position)
		;
		CHECK(x_position < x_reference1)
		;
		CHECK(x_position > x_reference2)
		;
	}

	SUBCASE("The player is facing up")
	{
		auto player = Player
		{ Orientation::FACE_UP };

		auto end_loop = player.getParameters().getXposition()
				/ player.getParameters().getMovementStep();

		auto x_reference1 = player.getParameters().getScreenXLength()
				- player.getParameters().getXLength() / 2;
		auto x_reference2 = player.getParameters().getScreenXLength()
				- player.getParameters().getXLength();

		for (auto i = 0u; i < end_loop; i++)
		{
			player.setMoveDirection(MoveDirection::RIGHT);
			player.move();
		}

		auto [x_position, y_position] = player.getPosition();
		CHECK_FALSE(x_position == y_position)
		;
		CHECK(x_position < x_reference1)
		;
		CHECK(x_position > x_reference2)
		;
	}
}
