#ifndef PLAYER_H_
#define PLAYER_H_
#include <vector>
#include <memory>
#include <tuple>
#include "Bullet.h"
#include "IMovingEntity.h"
#include "PlayerBulletFactory.h"
using two_floats = std::tuple<float, float>;
using vec_of_bullets = std::vector<std::shared_ptr<Bullet>>;

/** \class Player
 * \brief This class is a game object class that inherits from the IMovingEntity class.
 * This class models the behavior of the laser cannon controlled by the player.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Player : public IMovingEntity
{
public:
	/** \brief Parameterized Player constructor. Initializes the member
	 * variables defined in the IEntity and IMovingEntity classes. The
	 * constutor's parameters have default values to avoid the need for
	 * a default constructor.
	 * \param orientation of type Orientation
	 */
	Player(Orientation orientation = Orientation::FACE_UP);

	/** \brief This method returns a vector containing shared pointers to
	 * all the bullets fired by the player. This is done through the PlayerBulletFactory
	 * class.
	 * \return std::vector<std::shared_ptr<Bullet> >
	 */
	vec_of_bullets getShotsFired();

	/** \brief This method receives a constant enumeration of type MoveDirection. It
	 * then assigns the member move_direction variable to that of the received one.
	 * \param direction of type MoveDirection
	 */
	void setMoveDirection(const MoveDirection &direction);

	/** \brief This method returns a constant boolean which is set to to true
	 * if the player is not moving vertically.
	 */
	const bool isNotMovingVertucally();

	/** \brief This method implements the move() method defined in the
	 * IMovingEntity class. It moves the player either left, right, up or down
	 * depending on its MoveDirection parameter and resets the moveDirection
	 * after the fact.
	 */
	virtual void move() override;

	/** \brief This method calls upon the PlayerBulletFactory class to generate a
	 * bullet.
	 */
	void shoot();

	/** \brief This method returns a constant boolean, which is set to true if the
	 * player's hit status is set to true.
	 */
	const bool getHit() const;

	/** \brief This method receives a constant enumeration of type Orientation and
	 * resets the player to its original position depending on which orientation it
	 * was initialized with.
	 * \param orientation of type orientation
	 */
	void resetPosition(Orientation orientation);

	/** \brief This method resets the player power up counter forcing them to return
	 * to using normal shots.
	 */
	void startClock();
private:
	PlayerBulletFactory bullet_factory_;

	/** \brief This method increments or decrements the player's
	 * horizontal position depending on whether its MovementDirection is
	 * down or up respectively.
	 */
	void movePlayerHorizontally();

	/** \brief This method increments or decrements the player's
	 * vertical position depending on whether its MovementDirection is
	 * down or up respectively.
	 */
	void movePlayerVertically();

	/** \brief This method changes the orientation of the player object
	 * depending on which edge it is on the screen.
	 */
	void changeOrientation();

	/** \brief This method implements the initializePosition()
	 * method defined in the IEnity class. It sets the objects along
	 * the top and bottom edges of the screen. An object's y-position depends
	 * on it's orientation.
	 * \return std::tuple<float,float>
	 */
	virtual two_floats initializePosition() override;
};

#endif
