#ifndef LEFTDIAGONALBULLET_H_
#define LEFTDIAGONALBULLET_H_
#include "Bullet.h"

/** \class LeftDiagonalBullet
 * \brief This class is a game object class that inherits from the Bullet class.
 * This class models the behavior of a bullet that moves diagonally towards
 * the left edge of the screen.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class LeftDiagonalBullet : public Bullet
{
public:
	/** \brief Parameterized LeftDiagonalBullet constructor. Initializes the member
	 * variables defined in the IEntity and IMovingEntity classes. The
	 * constutor's parameters have default values to avoid the need for
	 * a default constructor. It overrides the inherited constructor from Bullet
	 * \param position of type std::tuple<float,float>
	 * \param orientation of type Orientation
	 */
	LeftDiagonalBullet(two_floats position = {0,0}, Orientation orientation = Orientation::FACE_UP);
private:
	/** \brief This method overrides the moveBullet() method in the Bullet class. In addition
	 * to incrementing the vertical position bullet, the method also decrements the horizontal
	 * position
	 */
	void moveBullet() override;
};

#endif
