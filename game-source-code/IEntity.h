#ifndef IENTITY_H_
#define IENTITY_H_
#include "Orientation.h"
#include "MoveDirection.h"
#include "Parameters.h"
#include "ObjectType.h"
#include "HitBox.h"
#include "Position.h"
#include "Movement.h"
using two_floats = std::tuple<float, float>;

/** \class IEntity
 * \brief This class is the main class by which all game objects inherit from.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class IEntity
{
public:
	/** \brief Mandatory virtual destructor.
	 */
	virtual ~IEntity();

	/** \brief This method returns a constant Orientation enumeration, which details
	 * the current orientation of the object inherited from this class. It queries
	 * the Parameters class to do so.
	 * No modifications are made to member variables.
	 * \return const Orientation
	 */
	const Orientation getOrientation() const;

	/** \brief This method returns a constant ObjectType enumeration, which details
	 * the type of the object inherited from this class. It queries the Parameters
	 * class to do so.
	 * No modifications are made to member variables.
	 * \return const ObjectType
	 */
	const ObjectType getObjectType() const;

	/** \brief This method returns a constant tuple of which each element is of type
	 * float. The tuple that is returned details the position of the object inherited
	 * from this class. The method queries the Parameters class to do so.
	 * No modifications are made to member variables.
	 * \return const std::tuple<float,float>
	 */
	const two_floats getPosition() const;

	/** \brief This method returns a constant tuple of which each element is of type
	 * float. The tuple details the size of the object inherited from this class.
	 * queries the Parameters class to do so.
	 * No modifications are made to member variables.
	 * \return const std::tuple<float,float>
	 */
	const two_floats getSize() const;

	/** \brief This method returns a constant HitBox object, which details the boundary
	 * box of the object inherited from this class.
	 * No modifications are made to member variables.
	 * \return const HitBox
	 */
	const HitBox getHitBox() const;

	/** \brief This method returns a constant boolean, which details whether the object
	 * inherited from this class is alive or not. It queries the Parameters class to do so.
	 * No modifications are made to member variables.
	 * \return const bool
	 */
	const bool getStatus() const;

	/** \brief This method returns a constant float, which details the worth of the object
	 * inherited from this class. It queries the Parameters class to do so.
	 * No modifications are made to member variables.
	 * \return const float
	 */
	const float getScore() const;

	/** \brief This method returns a constant integer, which details how many hit-points
	 * the object inherited from this class has left. It queries the Parameters class to do so.
	 * No modifications are made to member variables.
	 * \return const int
	 */
	const int getLives() const;

	/** \brief This method changes the status of the object inherited from this class from
	 * alive to dead. It does this through the Parameters class.
	 */
	void killEntity();

	/** \brief This method decrements the total hit-points of the object inherited from
	 * this class. It does this through the Parameters class.
	 */
	void hitEntity();

protected:
	Parameters parameters_;
	HitBox hitbox_;
	Position position_;

	/** \brief This pure virtual method returns a tuple of which each element is of type float.
	 * It serves as an interface in order for objects which are inherited from this class to set
	 * their initial position.
	 * \return std::tuple<float, float>
	 */
	virtual two_floats initializePosition() = 0;

	/** \brief This method updates the HitBox object to ensure that its position relative to
	 * the position of the object inherited from this class is correct.
	 */
	void updateHitBox();

};

#endif
