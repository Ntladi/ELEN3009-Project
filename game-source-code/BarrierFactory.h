#ifndef BARRIERFACTORY_H_
#define BARRIERFACTORY_H_
#include "Barrier.h"
#include <memory>
#include <vector>
#include <tuple>
#include <algorithm>
using vec_of_barriers = std::vector<std::shared_ptr<Barrier>>;
using two_floats = std::tuple<float, float>;

/** \class BarrierFactory
 * \brief This class manages the behavior of all barriers that appear
 * in the game. All Barrier objects are encapsulated within this class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class BarrierFactory
{
public:

	/** \brief Parameterized BarrierFactory constructor. it initializes all barriers
	 * that appear on the screen.
	 * \param orientation of type Orientation
	 */
	BarrierFactory(Orientation orientation = Orientation::FACE_UP);

	/** \brief This method returns the member vector of Barrier shared pointers that have
	 * not been destroyed.
	 * \return std::vector<std::shared_ptr<Barrier>>
	 */
	vec_of_barriers getBarriers();
private:
	vec_of_barriers barriers_;

	/** \brief This method removes destroyed bullet objects from the member vector of Bullet shared
	 * pointers.
	 */
	void removeWaste();

	/** \brief This method generates all barriers that appear on the screen
	 * \param orientation of type Orientation
	 */
	void generateBarriers(Orientation orientation);

	/** \brief This method generates a row of barriers along the x axis of the screen.
	 * \param orientation of type Orientation
	 * \param position of type std::tuple<float, float>;
	 * \param size of type std::tuple<float, float>;
	 */
	void generateRows(Orientation orientation, two_floats position, two_floats size);

	/** \brief This method generates a column of barriers along the y axis of the screen.
	 * \param orientation of type Orientation
	 * \param position of type std::tuple<float, float>;
	 * \param size of type std::tuple<float, float>;
	 */
	void generateColumns(Orientation orientation, two_floats position, two_floats size);
};

#endif
