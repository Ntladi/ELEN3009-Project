#ifndef WINDOWHANDLER_H_
#define WINDOWHANDLER_H_
#include "Backgrounds.h"
#include "ScreenStates.h"
using window_ptr = std::shared_ptr<sf::RenderWindow>;

class WindowHandler {
public:
	void clearWindow(ScreenStates & state, window_ptr & window);
	void createWindow(window_ptr & window);
	bool events(window_ptr & window);
private:
	Backgrounds backgrounds_;
};

#endif
