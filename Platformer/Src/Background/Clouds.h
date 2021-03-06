#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include "../Window/Window_info.h"

struct Cloud
{
	sf::Sprite sprite;
	float velocity;
};

class Clouds : public sf::Drawable
{
public:
	Clouds();
	void Update(const sf::RenderWindow& window);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Sprite& GetSprite(int index);
	std::size_t GetTotalNumberOfClouds()const;
private:
	void LoadCloudResources(int cloudNum);
	double GetRandomVelocity()const;
	int GetRandomYPosition()const;

	// Used at init; delete if becomes unnecessary
	int GetRandomXPosition()const;
private:
	std::array<sf::Texture, 4>m_cloudTextures;
	std::array<sf::Sprite, 4>m_cloudSprites;
	std::vector<Cloud>m_clouds;
};
