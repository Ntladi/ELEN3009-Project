#ifndef WINDOWHANDLER_H_
#define WINDOWHANDLER_H_
#include <ScreenState.h>
#include "Backgrounds.h"
using window_ptr = std::shared_ptr<sf::RenderWindow>;
using text_ptr = std::shared_ptr<sf::Text>;

class WindowHandler {
public:
	void clearWindow(ScreenState & state, window_ptr & window, text_ptr & score, text_ptr & high_score);
	void createWindow(window_ptr & window);
	bool events(window_ptr & window);
private:
	Backgrounds backgrounds_;
};

#endif
