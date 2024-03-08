#include "AnimationWindow.h"
#include "Emoji.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1200;
constexpr int ymax = 240;
constexpr int emojiRadius = 100;

int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	// koordinater til HappyFace:
	int xHappyFace = 120;
	int yFace = 120;
	Point pointHappyFace = {xHappyFace, yFace};
	Point eyeHappy1 = {xHappyFace - emojiRadius/3, yFace - emojiRadius/3};
	Point eyeHappy2 = {xHappyFace + emojiRadius/3, yFace - emojiRadius/3};
	Point mouthHappy = {xHappyFace, yFace - emojiRadius/3};

	HappyFace happyFace(pointHappyFace, emojiRadius, eyeHappy1, eyeHappy2, mouthHappy);
	happyFace.draw(win);

	// SadFace
	int xSadFace = xHappyFace + 2*emojiRadius + 40;
	Point sadFacePoint = {xSadFace, yFace};
	Point mouthSadFacePoint = {xSadFace, yFace + emojiRadius};
	Point eyeSad1 = {xSadFace - emojiRadius/3, yFace - emojiRadius/3};
	Point eyeSad2 = {xSadFace + emojiRadius/3, yFace - emojiRadius/3};

	SadFace sadFace(sadFacePoint, emojiRadius, eyeSad1, eyeSad2, mouthSadFacePoint);
	sadFace.draw(win);

	// NaturalFace
	int xNaturalFace = xSadFace + 2*emojiRadius + 40;
	Point naturalFacePoint = {xNaturalFace, yFace};
	Point startNaturalMouthPoint = {xNaturalFace - emojiRadius/2, yFace + emojiRadius/3};
	Point endNaturalMouthPoint = {xNaturalFace + emojiRadius/2, yFace + emojiRadius/3};
	Point eyeNatural1 = {xNaturalFace - emojiRadius/3, yFace - emojiRadius/3};
	Point eyeNatural2 = {xNaturalFace + emojiRadius/3, yFace - emojiRadius/3};

	NaturalFace naturalFace(naturalFacePoint, emojiRadius, eyeNatural1, eyeNatural2, tl, startNaturalMouthPoint, endNaturalMouthPoint);
	naturalFace.draw(win);

	// WowFace
	int xWowFace = xNaturalFace + 2*emojiRadius + 40;
	Point wowFacePoint = {xWowFace, yFace};
	Point eyeWow1 = {xWowFace - emojiRadius/3, yFace - emojiRadius/3};
	Point eyeWow2 = {xWowFace + emojiRadius/3, yFace - emojiRadius/3};
	Point wowMouthPoint = {xWowFace, yFace + emojiRadius/2};

	WowFace wowFace(wowFacePoint, emojiRadius, eyeWow1, eyeWow2, wowMouthPoint);
	wowFace.draw(win);
	
	// SwearingFace
	int xSwearingFace = xWowFace + 2*emojiRadius + 40;
	Point swearingFacePoint = {xSwearingFace, yFace};
	Point eyeSwearing1 = {xSwearingFace - emojiRadius/3, yFace - emojiRadius/3};
	Point eyeSwearing2 = {xSwearingFace + emojiRadius/3, yFace - emojiRadius/3};
	Point swearingMouthPoint = {xSwearingFace - emojiRadius/2, yFace + emojiRadius/4};
	string swearingWord = "#%?@!";

	SwearingFace swearingFace(swearingFacePoint, emojiRadius, eyeSwearing1, eyeSwearing2, swearingMouthPoint, swearingWord);
	swearingFace.draw(win);


	win.wait_for_close();

	return 0;
}
