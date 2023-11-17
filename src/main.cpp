#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

int getCount(std::string startLabel, std::string end);
void setupIcons();

bool activated = false;

class $modify(MenuLayer) {

    bool init() {
        if(!MenuLayer::init()) return false;

		if(!activated){
			setupIcons();
			activated = true;
		}

		return true;
    } 
};


int getCount(std::string startLabel, std::string end){

	int count = 1;
	while(true){

		std::stringstream number;
		number << std::setw(2) << std::setfill('0') << count;

		if (CCSprite::createWithSpriteFrameName((startLabel + "_" + number.str() + "_" + end + ".png").c_str())){
            count++;
        }
		else{
			break;
		}
	}
	return count-1;
}

std::vector<unsigned char> intToBytes(int value)
{
    std::vector<unsigned char> result;
    result.push_back(value & 0x000000ff);
    result.push_back((value & 0x0000ff00) >> 8);
    result.push_back((value & 0x00ff0000) >> 16);
    result.push_back((value & 0xff000000) >> 24);
    return result;
}

void setupIcons() {

	int cubeCount = getCount("player", "001");

	int shipCount = getCount("ship", "001");

	int ballCount = getCount("player_ball", "001");

	int ufoCount = getCount("bird", "001");

	int waveCount = getCount("dart", "001");

	int robotCount = getCount("robot", "01_001");

	int spiderCount = getCount("spider", "01_001");

	//all patches from user95401 on GitHub: https://github.com/user95401/IconsCountEditor/blob/main/src/main.cpp

	log::info("Cube count: " + std::to_string(cubeCount));

	std::vector<unsigned char> cubeBytes = intToBytes(cubeCount);

	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x1F7E48), { 0xB9, cubeBytes[0], cubeBytes[1], cubeBytes[2], cubeBytes[3]});
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12B095), { 0xC7, 0x44, 0x24, 0x1C, cubeBytes[0], cubeBytes[1], cubeBytes[2], cubeBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12C766), { 0xC7, 0x44, 0x24, 0x14, cubeBytes[0], cubeBytes[1], cubeBytes[2], cubeBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12807A), { 0xB8, cubeBytes[0], cubeBytes[1], cubeBytes[2], cubeBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12BE64), { 0xB9, cubeBytes[0], cubeBytes[1], cubeBytes[2], cubeBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x1E6DD9), { 0xBA, cubeBytes[0], cubeBytes[1], cubeBytes[2], cubeBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12C26C), { 0xBA, cubeBytes[0], cubeBytes[1], cubeBytes[2], cubeBytes[3] });
	
	log::info("Ship count: " + std::to_string(shipCount));

	std::vector<unsigned char> shipBytes = intToBytes(shipCount);

	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x1E6DEF), { 0xB8, shipBytes[0], shipBytes[1], shipBytes[2], shipBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x1F7FF6), { 0xBa, shipBytes[0], shipBytes[1], shipBytes[2], shipBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12C6D1), { 0xc7, 0x44, 0x24, 0x14, shipBytes[0], shipBytes[1], shipBytes[2], shipBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12B0CA), { 0xc7, 0x44, 0x24, 0x1c, shipBytes[0], shipBytes[1], shipBytes[2], shipBytes[3] });

	log::info("Ball count: " + std::to_string(ballCount));

	std::vector<unsigned char> ballBytes = intToBytes(ballCount);

	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12C6EC), { 0xc7, 0x44, 0x24, 0x14, ballBytes[0], ballBytes[1], ballBytes[2], ballBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12B0FF), { 0xc7, 0x44, 0x24, 0x1c, ballBytes[0], ballBytes[1], ballBytes[2], ballBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x1F83A6), { 0xba, ballBytes[0], ballBytes[1], ballBytes[2], ballBytes[3] });

	log::info("UFO count: " + std::to_string(ufoCount));

	std::vector<unsigned char> ufoBytes = intToBytes(ufoCount);

	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x22DA45), { 0xB9, ufoBytes[0], ufoBytes[1], ufoBytes[2], ufoBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x24A18F), { 0xB8, ufoBytes[0], ufoBytes[1], ufoBytes[2], ufoBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x24B210), { 0xB8, ufoBytes[0], ufoBytes[1], ufoBytes[2], ufoBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x1F81A6), { 0xBA, ufoBytes[0], ufoBytes[1], ufoBytes[2], ufoBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12B134), { 0xc7, 0x44, 0x24, 0x1c, ufoBytes[0], ufoBytes[1], ufoBytes[2], ufoBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12C704), { 0xc7, 0x44, 0x24, 0x14, ufoBytes[0], ufoBytes[1], ufoBytes[2], ufoBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x25612A), { 0xc7, 0x84, 0x24, 0x28, 0x0a, 0x00, 0x00, ufoBytes[0], ufoBytes[1], ufoBytes[2], ufoBytes[3] });

	log::info("Wave count: " + std::to_string(waveCount));

	std::vector<unsigned char> waveBytes = intToBytes(waveCount);

	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x128568), { 0xB8, waveBytes[0], waveBytes[1], waveBytes[2], waveBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x142762), { 0xBB, waveBytes[0], waveBytes[1], waveBytes[2], waveBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x1F8586), { 0xBA, waveBytes[0], waveBytes[1], waveBytes[2], waveBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12B169), { 0xC7, 0x44, 0x24, 0x1C, waveBytes[0], waveBytes[1], waveBytes[2], waveBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12C71C), { 0xC7, 0x44, 0x24, 0x14, waveBytes[0], waveBytes[1], waveBytes[2], waveBytes[3] });

	log::info("Robot count: " + std::to_string(robotCount));

	std::vector<unsigned char> robotBytes = intToBytes(robotCount);

	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12B19E), { 0xC7, 0x44, 0x24, 0x1C, robotBytes[0], robotBytes[1], robotBytes[2], robotBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12C734), { 0xC7, 0x44, 0x24, 0x14, robotBytes[0], robotBytes[1], robotBytes[2], robotBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x255ADC), { 0xc7, 0x84, 0x24, 0x28, 0x0a, 0x00, 0x00, robotBytes[0], robotBytes[1], robotBytes[2], robotBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x1F855A), { 0xba, robotBytes[0], robotBytes[1], robotBytes[2], robotBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x20CCD5), { 0xb9, robotBytes[0], robotBytes[1], robotBytes[2], robotBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x14673D), { 0xb8, robotBytes[0], robotBytes[1], robotBytes[2], robotBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x1F6ACD), { 0xb8, robotBytes[0], robotBytes[1], robotBytes[2], robotBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x20900F), { 0xb9, robotBytes[0], robotBytes[1], robotBytes[2], robotBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x20CCC3), { 0x6a, robotBytes[0], robotBytes[1], robotBytes[2], robotBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x125F61), { 0xb9, robotBytes[0], robotBytes[1], robotBytes[2], robotBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12880E), { 0xb9, robotBytes[0], robotBytes[1], robotBytes[2], robotBytes[3] });

	log::info("Spider count: " + std::to_string(spiderCount));

	std::vector<unsigned char> spiderBytes = intToBytes(spiderCount);

	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12B1D3), { 0xC7, 0x44, 0x24, 0x1C, spiderBytes[0], spiderBytes[1], spiderBytes[2], spiderBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12C74C), { 0xC7, 0x44, 0x24, 0x14, spiderBytes[0], spiderBytes[1], spiderBytes[2], spiderBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x146745), { 0xba, spiderBytes[0], spiderBytes[1], spiderBytes[2], spiderBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x1553A2), { 0xC7, 0x84, 0x24, 0xC0, spiderBytes[0], spiderBytes[1], spiderBytes[2], spiderBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x1289CE), { 0xb9, spiderBytes[0], spiderBytes[1], spiderBytes[2], spiderBytes[3] });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x126021), { 0xb9, spiderBytes[0], spiderBytes[1], spiderBytes[2], spiderBytes[3] });
}


