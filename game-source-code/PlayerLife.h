#ifndef PLAYERLIFE_H_
#define PLAYERLIFE_H_
#include "IEntity.h"
#include "Constants.h"
#include <tuple>
using two_floats = std::tuple<float, float>;

/** \class PlayerLife
 * \brief This class is a game object class that inherits from the IEntity class.
 * This class models the icons that display a player's life at the top
 * of screen.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class PlayerLife : public IEntity
{
public:
	/** \brief Parameterized Barrier constructor. Initializes the member
	 * variables defined in the IEntity class. The constutor's parameters
	 * have default values to avoid the need for a default constructor.
	 */
	PlayerLife(Orientation orientation = Orientation::FACE_UP);

private:
	/** \brief This method implements the initializePosition()
	 *  method defined in the IEnity class. It sets the life icons at the top
	 *  corners of the screen to their appropriate positions.
	 *  \return std::tuple<float,float>
	 */
	virtual two_floats initializePosition() override;

};

#endif
