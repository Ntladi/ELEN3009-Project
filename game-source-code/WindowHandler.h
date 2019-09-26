#ifndef WINDOWHANDLER_H_
#define WINDOWHANDLER_H_
#include <ScreenState.h>
#include "Backgrounds.h"
using window_ptr = std::shared_ptr<sf::RenderWindow>;
using text_ptr = std::shared_ptr<sf::Text>;

/** \class WindowHandler
 * \brief This class is composed within the Presentation class
 * and handles basic window events. The RenderWindow is handled
 * by the SFML library.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class WindowHandler {
public:
	/** \brief This method receives a constant enumeration of type ScreenState, which describes which screen the window must
	 * display. In addition, it also receives a constant pointer to a RenderWindow object which will display the screen state.
	 * Moreover, two constant pointers to Text objects are also received, which are the scores that are drawn on the RenderWindow
	 * object.
	 * \param state of type ScreenState
	 * \param window of type std::shared_ptr<sf::RenderWindow>;
	 * \param score of type std::shared_ptr<sf::Text>;
	 * \param high_score of type std::shared_ptr<sf::Text>;
	 */
	void clearWindow(const ScreenState & state, const window_ptr & window,const text_ptr & score,const text_ptr & high_score);

	/** \brief This method receives a constant pointer to a RenderWindow object, which is initialized in this method.
	 * \param window of type std::shared_ptr<sf::RenderWindow>;
	 */
	void createWindow(const window_ptr & window);

	/** \brief This method receives a constant pointer to a RenderWindow object, whose poll events are handled within this method.
	 * Moreover, the method also return true if a poll event returns true for a key being pressed.
	 * \param window of type std::shared_ptr<sf::RenderWindow>;
	 * \return bool
	 */
	bool events(const window_ptr & window);
private:
	Backgrounds backgrounds_;
};

#endif
