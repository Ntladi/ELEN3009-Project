#ifndef IMOVINGENTITY_H_
#define IMOVINGENTITY_H_
#include "IEntity.h"

/** \class IMovingEntity
 * \brief This class is the main class by which all moving game objects inherit from.
 * It inherits from the IEntity class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class IMovingEntity : public IEntity
{
public:
	/** \brief This method returns a constant MoveDirection enumeration, which details
	 * the current move direction of the object inherited from this class. It queries
	 * the Movement class to do so.
	 * No modifications are made to member variables.
	 * \return const MoveDirection
	 */
	const MoveDirection getMoveDirection() const;

	/** \brief This pure virtual method serves an interface in order for objects inherited from
	 * this class to increment their position.
	 */
	virtual void move() = 0;
protected:
	Movement movement_;
	/** \brief This method returns a constant boolean, which is set to true if the inherited
	 * object is at either the left or right of the screen.
	 * \return const bool
	 */
	const bool isAtEdgeOfScreen();

	/** \brief This method returns a constant boolean, which is set to true if the inherited
	 * object is at either the top or bottom of the screen.
	 * \return const bool
	 */
	const virtual bool isAtEndOfScreen();

};

#endif
