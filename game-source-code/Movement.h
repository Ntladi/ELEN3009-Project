#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include "MoveDirection.h"
#include "Constants.h"

/** \class Movement
 * \brief This class is a data layer class that encapsulates
 * all movement information for all objects inherited from the IMovingEntity class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Movement
{
public:
	/** \brief Parameterized Movement constructor. Initializes member variables
	 * to those that are passed in. The constutor's parameters have default values
	 * to avoid the need for a default constructor.
	 * \param move_direction of type MoveDirection
	 * \param movement_step of type float
	 */
	Movement(MoveDirection move_direction = MoveDirection::NONE, const float movement_step = 0);

	/** \brief This method receives a constant enumeration of type MoveDirection. It
	 * then assigns the member moveDirection variable to that of the received one.
	 * \param moveDirection of type MoveDirection
	 */
	void setMoveDirection(const MoveDirection& moveDirection);

	/** \brief This method returns a constant MoveDirection enumeration, which details
	 * the current moveDirection of the inherited object.
	 * No modifications are made to member variables.
	 * \return MoveDirection
	 */
	const MoveDirection getMoveDirection() const;

	/** \brief This method returns a constant float, which details
	 * the current movement step of the inherited object.
	 * No modifications are made to member variables.
	 * \return MoveDirection
	 */
	const float getMovementStep() const;

	/** \brief This method returns a constant float, which details
	 * the maximum pre-increment step of the inherited object.
	 * No modifications are made to member variables.
	 * \return MoveDirection
	 */
	const float getEdgeStep() const;

	/** \brief This method inverts the horizontal direction of the
	 * inherited object.
	 */
	void changeHorizontalDirection();

	/** \brief This method returns a constant boolean, which is set to true if
	 * the inherited object is moving upwards.
	 * No modifications are made to member variables.
	 * \return bool
	 */
	const bool isMovingUp() const;

	/** \brief This method returns a constant boolean, which is set to true if
	 * the inherited object is moving downwards.
	 * No modifications are made to member variables.
	 * \return bool
	 */
	const bool isMovingDown() const;

	/** \brief This method returns a constant boolean, which is set to true if
	 * the inherited object is moving left.
	 * No modifications are made to member variables.
	 * \return bool
	 */
	const bool isMovingLeft() const;

	/** \brief This method returns a constant boolean, which is set to true if
	 * the inherited object is moving right.
	 * No modifications are made to member variables.
	 * \return bool
	 */
	const bool isMovingRight() const;

	/** \brief This method returns a constant boolean, which is set to true if
	 * the inherited object is not moving.
	 * No modifications are made to member variables.
	 * \return bool
	 */
	const bool isNotMoving() const;

private:
	MoveDirection move_direction_;
	float movement_step_;
	float edge_step_;
};

#endif
