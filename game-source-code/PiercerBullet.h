#ifndef PIERCERBULLET_H_
#define PIERCERBULLET_H_
#include "Bullet.h"
using two_floats = std::tuple<float, float>;
using four_floats = std::tuple<float,float,float, float>;
/** \class PiercerBullet
 * \brief This class is a game object class that inherits from the Bullet class.
 * This class models the behavior of a bullet that kills multiple game objects
 * before being destroyed.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class PiercerBullet : public Bullet
{
public:
	/** \brief Parameterized PiercerBullet constructor. Initializes the member
	 * variables defined in the IEntity and IMovingEntity classes. The
	 * constutor's parameters have default values to avoid the need for
	 * a default constructor. It overrides the inherited constructor from Bullet
	 * \param position of type std::tuple<float,float>
	 * \param orientation of type Orientation
	 */
	PiercerBullet(two_floats position = {0,0}, Orientation orientation = Orientation::FACE_UP);
};

#endif
