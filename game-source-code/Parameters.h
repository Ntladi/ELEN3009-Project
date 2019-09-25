#ifndef PARAMETERS_H_
#define PARAMETERS_H_
#include <Constants.h>
#include <tuple>
#include "ObjectType.h"
#include "Orientation.h"
#include "MoveDirection.h"
using two_floats = std::tuple<float, float>;
using four_floats = std::tuple<float, float, float, float>;

/** \class Parameters
 * \brief This class is a data layer class that encapsulates
 * the data members of the IEntity class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Parameters
{

public:
	/** \brief Default parameterized Parameters constructor. Initializes member variables
	 * to those that are passed in.
	 */
	Parameters(ObjectType object = ObjectType::NONE, Orientation orientation =
			Orientation::FACE_UP, four_floats params = { 0, 0, 0, 0 });

	/** \brief This method returns a constant tuple of which each element is of type
	 * float. It returns the size of the inherited object back to the IEntity class.
	 * No modifications are made to member variables.
	 * \return const std::tuple<float,float>
	 */
	const two_floats getSize() const;

	/** \brief This method returns a constant float, which details the worth of the
	 * inherited object.
	 * No modifications are made to member variables.
	 * \return const float
	 */
	const float getWorth() const;

	/** \brief This method returns a constant float, which details position of the
	 * top edge inherited object.
	 * No modifications are made to member variables.
	 * \return const float
	 */
	const float getTopEdge() const;

	/** \brief This method returns a constant float, which details position of the
	 * bottom edge inherited object.
	 * No modifications are made to member variables.
	 * \return const float
	 */
	const float getBottomEdge() const;

	/** \brief This method returns a constant float, which details position of the
	 * left edge inherited object.
	 * No modifications are made to member variables.
	 * \return const float
	 */
	const float getLeftEdge() const;

	/** \brief This method returns a constant float, which details position of the
	 * right edge inherited object.
	 * No modifications are made to member variables.
	 * \return const float
	 */
	const float getRightEdge() const;

	/** \brief This method returns a constant integer, which details how many lives
	 * the inherited object has left.
	 * No modifications are made to member variables.
	 * \return const int
	 */
	const int getLives() const;

	/** \brief This method returns a constant ObjectType enumeration, which details
	 * the type of the inherited object.
	 * No modifications are made to member variables.
	 * \return const ObjectType
	 */
	const ObjectType getObjectType() const;

	/** \brief This method returns a constant Orientation enumeration, which details
	 * the current orientation of the inherited object.
	 * No modifications are made to member variables.
	 * \return const Orientation
	 */
	const Orientation getOrientation() const;

	/** \brief This method decrements the hit-points of the inherited object. It
	 * also sets the hit status of the inherited object to true.
	 */
	void damage();

	/** \brief This method sets the hit status of the object to false.
	 */
	void resetHit();

	/** \brief This method returns a constant boolean, which is set to true if
	 * the inherited object is alive.
	 * No modifications are made to member variables.
	 * \return const bool
	 */
	const bool getStatus() const;

	/** \brief This method receives a constant enumeration of type Orientation. It
	 * then sets the member orientation variable to that of the received one.
	 * \param orientation of type Orientation
	 */
	void setOrientation(const Orientation &orientation);

	/** \brief This method receives a constant boolean. It
	 * then sets the is_Alive member variable to that of the received one.
	 * \param status of type bool
	 */
	void setStatus(const bool &status);

	/** \brief This method returns a constant boolean, which is set to true if
	 * the inherited object is facing upwards.
	 * No modifications are made to member variables.
	 * \return const bool
	 */
	const bool isFacingUp() const;

	/** \brief This method returns a constant boolean, which is set to true if
	 * the inherited object is facing downwards.
	 * No modifications are made to member variables.
	 * \return const bool
	 */
	const bool isFacingDown() const;

	/** \brief This method returns a constant boolean, which is set to true if
	 * the inherited object is hit.
	 * No modifications are made to member variables.
	 * \return const bool
	 */
	const bool isHit() const;

private:
	ObjectType object_;
	Orientation orientation_;
	bool is_Alive_;
	float x_length_;
	float y_length_;
	float hit_points_;
	float worth_;
	bool is_Hit_;

};

#endif
