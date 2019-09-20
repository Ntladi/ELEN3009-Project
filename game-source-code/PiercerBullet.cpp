#include <PiercerBullet.h>
#include <iostream>

PiercerBullet::PiercerBullet(two_floats position,
		Orientation orientation)
{
	four_floats params =
	{ Constants::PIERCER_BULLET_X_LENGTH, Constants::PIERCER_BULLET_Y_LENGTH,
			Constants::PIERCER_BULLET_HIT_POINTS, Constants::BULLET_WORTH };

	setup(params,ObjectType::PIERCER_BULLET,orientation,position);
}
