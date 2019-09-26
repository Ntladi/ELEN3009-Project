#ifndef POSITION_H_
#define POSITION_H_
#include <tuple>
#include "ObjectType.h"
#include "Orientation.h"
#include "Constants.h"
using two_floats = std::tuple<float,float>;
/** \class Position
 * \brief This class is a data layer class that encapsulates
 * the current position of all objects inherited from the IEntity class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Position
{
public:
	/** \brief Parameterized Position constructor. Initializes member variables
	 * to those that are passed in. The constutor's parameters have default values
	 * to avoid the need for a default constructor.
	 * \param initialPos of type std::tuple<float,float>
	 */
	Position(two_floats initialPos = {0,0});

	/** \brief This method receives a constant float and assigns the member
	 * x position to that of the received parameter.
	 * \param x of type float
	 */
	void setXPosition(const float &x);

	/** \brief This method receives a constant float and assigns the member
	 * y position to that of the received parameter.
	 * \param y of type float
	 */
	void setYPosition(const float &y);

	/** \brief This method returns a constant float which describes the x position
	 * of the object inherited from the IEntity class
	 * \return float
	 */
	const float getXPosition() const;

	/** \brief This method returns a constant float which describes the y position
	 * of the object inherited from the IEntity class
	 * \return float
	 */
	const float getYPosition() const;
private:
	float x_position_;
	float y_position_;

};

#endif
