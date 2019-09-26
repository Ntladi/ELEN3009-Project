#ifndef ALIEN_H_
#define ALIEN_H_
#include "Orientation.h"
#include "MoveDirection.h"
#include "IEntity.h"
#include "IMovingEntity.h"
#include "Bullet.h"
#include <tuple>
using two_floats = std::tuple<float, float>;

/** \class Alien
 * \brief This class is a game object class that inherits from the IMovingEntity class.
 * This class models the behavior of an alien that is meant to attack the player.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Alien : public IMovingEntity
{
public:
	/** \brief Parameterized Alien constructor. Initializes the member
	 * variables defined in the IEntity and IMovingEntity classes. The
	 * constutor's parameters have default values to avoid the need for
	 * a default constructor.
	 * \param orientation of type Orientation
	 */
	Alien(Orientation orientation = Orientation::FACE_UP);

	/** \brief This method receives a constant enumeration of type MoveDirection. It
	 * then assigns the member move_direction variable to that of the received one.
	 * \param direction of type MoveDirection
	 */
	void setMoveDirection(const MoveDirection &direction);

	/** \brief This method moves an alien object either up or down depending on its
	 * orientation. It is called only when the alien is at either the left or right
	 * edge of the screen.
	 */
	void moveAlienVertically();

	/** \brief This method returns a constant boolean which is set to true if the alien is
	 * at either the left or right edge of the screen. It does this by calling the
	 * isAtEdgeOfScreen() method defined in the IEntity class.
	 * \return bool
	 */
	const bool checkEdge();

	/** \brief This method returns a constant boolean which is set to true if the alien is
	 * at either the top or bottom edge of the screen. It does this by calling the
	 * isAtEndOfScreen() method defined in the IEntity class
	 * \return bool
	 */
	const bool checkEnd();

	/** \brief This method implements the move() method defined in the
	 * IMovingEntity class. It moves the alien either left or right depending on its
	 * MoveDirection parameter.
	 */
	void move() override;

	/** \brief This method generates and returns a bullet object.
	 * \return Bullet
	 */
	Bullet shoot();

private:

	/** \brief This method overrides the isAtEndOfScreen() defined in IMovingEntity.
	 * It checks if the alien is at the end of the screen depending on its orientation
	 * rather than  its move direction.
	 * \return bool
	 */
	const bool isAtEndOfScreen() override;

	/** \brief This method increments or decrements the alien's x position if its movement
	 * direction is left or right respectively
	 */
	void moveAlienHorizontally();

	/** \brief This method implements the initializePosition()
	 * method defined in the IEnity class. It sets the objects along
	 * the left edge of the screen. An object's y-position depends
	 * on its orientation.
	 * \return std::tuple<float,float>
	 */
	two_floats initializePosition() override;
};

#endif
