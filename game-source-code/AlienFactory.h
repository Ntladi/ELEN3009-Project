#ifndef ALIENFACTORY_H_
#define ALIENFACTORY_H_
#include "Constants.h"
#include "Alien.h"
#include "Orientation.h"
#include "ObjectType.h"
#include <vector>
#include <memory>
#include <algorithm>
using vec_of_aliens = std::vector<std::shared_ptr<Alien>>;
using aliens_2d = std::vector<vec_of_aliens>;
using two_floats = std::tuple<float,float>;

/** \class AlienFactory
 *	\brief This class generates an armada of aliens for the Armada class.
 */
class AlienFactory
{
public:
	void initializeArmada(aliens_2d &armada, Orientation orientation);
	/** \brief This method returns the number of aliens in the armada
	 * \return int
	 */
	unsigned int getCounter() const;

	/** \brief This method directly changes the counter detailing the of aliens in the armada
	 * as dictated by the Armada class.
	 * \param i of type int
	 */
	void setCounter(const unsigned int i);

	/** \brief This method increments the counter detailing the number of aliens in the armada.
	 */
	void incrementCounter();
private:
	two_floats size_;
	Position position_;
	int counter_;

	/** This method generates a row of aliens in the armada.
	 * \param orientation of type Orientation
	 * \param armada of type std::vector<std::vector<std::shared_ptr<Alien>>>
	 */
	void generateRows(Orientation &orientation, aliens_2d &armada);

	/** This method generates a column of aliens in the armada.
	 * \param x_position
	 * \param index of type unsigned int
	 * \param orientation of type Orientation
	 * \param armada of type std::vector<std::vector<std::shared_ptr<Alien>>>
	 */
	void generateColumn(const double &x_position, const unsigned int &index,
			Orientation &orientation, aliens_2d &armada);

};

#endif
