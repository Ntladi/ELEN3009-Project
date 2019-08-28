#include "Player.h"
#include "HitBox.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

TEST_CASE("The player's HitBox moves left with the player")
{
	SUBCASE("The player is facing up")
	{
		auto player = Player
		{ Orientation::FACE_UP };
		player.setMoveDirection(MoveDirection::LEFT);
		player.move();

		auto[x_position, y_position] = player.getPosition();
		auto hitbox = player.getHitBox();

		auto x_left_ref = x_position - player.getParameters().getXLength() / 2;
		auto x_right_ref = x_position + player.getParameters().getXLength() / 2;
		auto y_top_ref = y_position - player.getParameters().getYHeight() / 2;
		auto y_bottom_ref = y_position
				+ player.getParameters().getYHeight() / 2;

		SUBCASE("Check top left corner")
		{
			auto[x_top_left,y_top_left] = hitbox.getTopLeft();
			CHECK(x_top_left == x_left_ref)
			;
			CHECK(y_top_left == y_top_ref)
			;
		}

		SUBCASE("Check bottom left corner")
		{
			auto[x_bottom_left,y_bottom_left] = hitbox.getBottomLeft();
			CHECK(x_bottom_left == x_left_ref)
			;
			CHECK(y_bottom_left == y_bottom_ref)
			;
		}

		SUBCASE("Check top right corner")
		{
			auto[x_top_right,y_top_right] = hitbox.getTopRight();
			CHECK(x_top_right == x_right_ref)
			;
			CHECK(y_top_right == y_top_ref)
			;
		}

		SUBCASE("Check bottom right corner")
		{
			auto[x_bottom_right,y_bottom_right] = hitbox.getBottomRight();
			CHECK(x_bottom_right == x_right_ref)
			;
			CHECK(y_bottom_right == y_bottom_ref)
			;
		}

	}

	SUBCASE("The player is facing down")
	{
		auto player = Player
		{ Orientation::FACE_DOWN };
		player.setMoveDirection(MoveDirection::LEFT);
		player.move();

		auto[x_position, y_position] = player.getPosition();
		auto hitbox = player.getHitBox();

		auto x_left_ref = x_position - player.getParameters().getXLength() / 2;
		auto x_right_ref = x_position + player.getParameters().getXLength() / 2;
		auto y_top_ref = y_position - player.getParameters().getYHeight() / 2;
		auto y_bottom_ref = y_position
				+ player.getParameters().getYHeight() / 2;

		SUBCASE("Check top left corner")
		{
			auto[x_top_left,y_top_left] = hitbox.getTopLeft();
			CHECK(x_top_left == x_left_ref)
			;
			CHECK(y_top_left == y_top_ref)
			;
		}

		SUBCASE("Check bottom left corner")
		{
			auto[x_bottom_left,y_bottom_left] = hitbox.getBottomLeft();
			CHECK(x_bottom_left == x_left_ref)
			;
			CHECK(y_bottom_left == y_bottom_ref)
			;
		}

		SUBCASE("Check top right corner")
		{
			auto[x_top_right,y_top_right] = hitbox.getTopRight();
			CHECK(x_top_right == x_right_ref)
			;
			CHECK(y_top_right == y_top_ref)
			;
		}

		SUBCASE("Check bottom right corner")
		{
			auto[x_bottom_right,y_bottom_right] = hitbox.getBottomRight();
			CHECK(x_bottom_right == x_right_ref)
			;
			CHECK(y_bottom_right == y_bottom_ref)
			;
		}
	}
}

TEST_CASE("The player's HitBox moves right with the player")
{
	SUBCASE("The player is facing up")
	{
		auto player = Player
		{ Orientation::FACE_UP };
		player.setMoveDirection(MoveDirection::RIGHT);
		player.move();

		auto[x_position, y_position] = player.getPosition();
		auto hitbox = player.getHitBox();

		auto x_left_ref = x_position - player.getParameters().getXLength() / 2;
		auto x_right_ref = x_position + player.getParameters().getXLength() / 2;
		auto y_top_ref = y_position - player.getParameters().getYHeight() / 2;
		auto y_bottom_ref = y_position
				+ player.getParameters().getYHeight() / 2;

		SUBCASE("Check top left corner")
		{
			auto[x_top_left,y_top_left] = hitbox.getTopLeft();
			CHECK(x_top_left == x_left_ref)
			;
			CHECK(y_top_left == y_top_ref)
			;
		}

		SUBCASE("Check bottom left corner")
		{
			auto[x_bottom_left,y_bottom_left] = hitbox.getBottomLeft();
			CHECK(x_bottom_left == x_left_ref)
			;
			CHECK(y_bottom_left == y_bottom_ref)
			;
		}

		SUBCASE("Check top right corner")
		{
			auto[x_top_right,y_top_right] = hitbox.getTopRight();
			CHECK(x_top_right == x_right_ref)
			;
			CHECK(y_top_right == y_top_ref)
			;
		}

		SUBCASE("Check bottom right corner")
		{
			auto[x_bottom_right,y_bottom_right] = hitbox.getBottomRight();
			CHECK(x_bottom_right == x_right_ref)
			;
			CHECK(y_bottom_right == y_bottom_ref)
			;
		}

	}

	SUBCASE("The player is facing down")
	{
		auto player = Player
		{ Orientation::FACE_DOWN };
		player.setMoveDirection(MoveDirection::RIGHT);
		player.move();

		auto[x_position, y_position] = player.getPosition();
		auto hitbox = player.getHitBox();

		auto x_left_ref = x_position - player.getParameters().getXLength() / 2;
		auto x_right_ref = x_position + player.getParameters().getXLength() / 2;
		auto y_top_ref = y_position - player.getParameters().getYHeight() / 2;
		auto y_bottom_ref = y_position
				+ player.getParameters().getYHeight() / 2;

		SUBCASE("Check top left corner")
		{
			auto[x_top_left,y_top_left] = hitbox.getTopLeft();
			CHECK(x_top_left == x_left_ref)
			;
			CHECK(y_top_left == y_top_ref)
			;
		}

		SUBCASE("Check bottom left corner")
		{
			auto[x_bottom_left,y_bottom_left] = hitbox.getBottomLeft();
			CHECK(x_bottom_left == x_left_ref)
			;
			CHECK(y_bottom_left == y_bottom_ref)
			;
		}

		SUBCASE("Check top right corner")
		{
			auto[x_top_right,y_top_right] = hitbox.getTopRight();
			CHECK(x_top_right == x_right_ref)
			;
			CHECK(y_top_right == y_top_ref)
			;
		}

		SUBCASE("Check bottom right corner")
		{
			auto[x_bottom_right,y_bottom_right] = hitbox.getBottomRight();
			CHECK(x_bottom_right == x_right_ref)
			;
			CHECK(y_bottom_right == y_bottom_ref)
			;
		}
	}
}

