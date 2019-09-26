#ifndef BULLET_H_
#define BULLET_H_
#include "Orientation.h"
#include "ObjectType.h"
#include "MoveDirection.h"
#include "HitBox.h"
#include "Parameters.h"
#include "IMovingEntity.h"
using two_floats = std::tuple<float, float>;
using four_floats = std::tuple<float,float,float, float>;

/** \class Bullet
 * \brief This class is a game object class that inherits from the IMovingEntity class.
 * This class models the behavior of a bullet that moves across the screen. All unique
 * bullet variations (power-ups) inherit from this class
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Bullet : public IMovingEntity
{
public:
	/** \brief Parameterized Bullet constructor. Initializes the member
	 * variables defined in the IEntity and IMovingEntity classes. The
	 * constutor's parameters have default values to avoid the need for
	 * a default constructor.
	 * \param position of type std::tuple<float,float>
	 * \param bullet_type of type ObjectType
	 * \param orientation of type Orientation
	 */
	Bullet(two_floats position = {0,0}, ObjectType bullet_type = ObjectType::NONE, Orientation orientation = Orientation::FACE_UP);

	/** \brief This method implements the move() method defined in the
	 * IMovingEntity class. It moves the bullet either up or down depending on its
	 * MoveDirection parameter.
	 */
	void move() override;
protected:

	/** \brief This virtual method handles the movement pattern of the bullet
	 *  across the screen. Objects that inherit from this class can use this function
	 *  to implement their own unique movement patterns. By default it moves the bullet
	 *   vertically
	 */
	virtual void moveBullet();

	/** \brief This method is called by the constructor to set up the bullet object's
	 * initial parameters.
	 * \param params of type std::tuple<float, float, float, float>
	 * \param bullet_type of type ObjectType
	 * \param orientation of type Orientation
	 * \param position of type std::tuple<float, float>
	 */
	void setup(four_floats params, ObjectType bullet_type,Orientation orientation, two_floats position);

	/** \brief This method implements the initializePosition()
	 * method defined in the IEnity class. It sets position to 0 on
	 * both axes.
	 * \return std::tuple<float,float>
	 */
	two_floats initializePosition();
};

#endif
