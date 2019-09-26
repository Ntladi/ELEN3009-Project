#ifndef BARRIER_H_
#define BARRIER_H_
#include "IEntity.h"
#include "Constants.h"
#include <tuple>
using two_floats = std::tuple<float, float>;

/** \class Barrier
 * \brief This class is a game object class that inherits from the IEntity class.
 * This class models a piece of the shield that is meant to protect
 * the player.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Barrier : public IEntity
{
public:
	/** \brief Parameterized Barrier constructor. Initializes the member
	 * variables defined in the IEntity class. The constutor's parameters
	 * have default values to avoid the need for a default constructor.
	 */
	Barrier(Orientation orientation = Orientation::FACE_UP);

private:
	/** \brief This method implements the initializePosition()
	 * method defined in the IEnity class. It sets the barriers at either
	 * edge of the screen to their appropriate position.
	 * \return std::tuple<float,float>
	 */
	virtual two_floats initializePosition() override;
};

#endif
