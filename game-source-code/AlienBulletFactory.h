#ifndef ALIENBULLETFACTORY_H_
#define ALIENBULLETFACTORY_H_
#include "StopWatch.h"
#include "Bullet.h"
#include "Alien.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <memory>
#include <algorithm>
using vec_of_aliens = std::vector<std::shared_ptr<Alien>>;
using aliens_2d = std::vector<vec_of_aliens>;
using vec_of_bullets = std::vector<std::shared_ptr<Bullet>>;

/** \class AlienBulletFactory
 * \brief This class is a data layer class that manages the shots
 * fired by aliens in the Armada class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class AlienBulletFactory
{
public:
	/** \brief Default AlienBulletFactory constructor. It initializes
	 * the seed for the random number generator that determines which alien
	 * in the Armada class must shoot.
	 */
	AlienBulletFactory();

	/** \brief This method returns the member vector of Bullet shared pointers that have
	 * not been destroyed.
	 * \return std::vector<std::shared_ptr<Bullet>>
	 */
	const vec_of_bullets getOnslaught();

	/** \brief This method receives a constant two dimensional vector of Alien shared pointers,
	 * as well as the size of the equivalent one dimensional vector. The method then
	 * generates a Bullet object from a random alien at the edge of the armada.
	 * \param aliens of type std::vector<std::vector<std::shared_ptr<Alien>>>
	 * \param size of type int
	 */
	void generateBullets(const aliens_2d &aliens, const int &size);
private:
	vec_of_bullets bullets_;
	StopWatch stopwatch_;

	/** \brief This method receives a constant vector of unsigned integers that describe
	 * the row indices of the aliens at the end of the armada, as well as the column index of
	 * the alien that must generate a bullet object. It then generates a bullet object and stores it in the
	 * member vector of Bullet shared pointers.
	 * \param endOfCols of type std::vector<unsigned int>
	 * \param index of type int
	 * \param aliens of type std::vector<std::vector<std::shared_ptr<Alien>>>
	 */
	void addBullet(const std::vector<unsigned int> &endOfCols,
			const unsigned int &index, const aliens_2d &aliens);

	/** \brief This method removes destroyed bullet objects from the member vector of Bullet shared
	 * pointers.
	 */
	void removeWaste();
};

#endif
