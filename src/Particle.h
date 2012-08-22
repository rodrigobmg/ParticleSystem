/*
 * Particle.h
 *
 *  Created on: Aug 20, 2012
 *      Author: stashell
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <math.h>
#include <climits>
#include <SFML/Graphics.hpp>

#include "Point.h"
#include "Color.h"

#define PI 3.14159265

enum PARTICLE_TYPE
{
	SFML_SPRITE,
	SFML_PRIMITIVE
};

class Particle
{
public:
	Particle (float p_ax, float p_ay, float p_weight, Color p_color);
	virtual ~Particle();

    void setPosition(float p_ax, float p_ay) {ax=p_ax; ay=p_ay;};

    void setFriction   (float p_friction)    {friction = p_friction;};
    void setVectorX    (float p_vectorX)     {vectorX = p_vectorX;};
    void setVectorY    (float p_vectorY)     {vectorY = p_vectorY;};
    void setVectorXY   (float p_vectorX, float p_vectorY);

    void pushX(float p_vectorX) { vectorX+=p_vectorX; }
    void pushY(float p_vectorY) { vectorY+=p_vectorY; }
    void pushXY(float p_vectorX, float p_vectorY) { pushX(p_vectorX); pushY(p_vectorY); }

    void invertVectorX   ()    {setVectorX(-getVectorX());};
    void invertVectorY   ()    {setVectorY(-getVectorY());};
    void invertVectorXY  ()    {invertVectorX(); invertVectorY();};

    float getAx() const        {return ax;};
    float getAy() const        {return ay;};
    float getLastAx() const    {return lastAX;};
    float getLastAy() const    {return lastAY;};
    float getWeight() const    {return weight;};
    void  setWeight(float p_weight)    {weight = p_weight;};

    float getFriction() const  {return friction;};
    float getVectorX()  const  {return vectorX;};
    float getVectorY()  const  {return vectorY;};
    Point getPosition() 	   {return Point(ax, ay);};
    void  setPosition(const Point& position) {ax = position.x; ay = position.y; };
    void  stop() 			   {vectorX=0; vectorY=0;};

    void processData(float framerate);
    virtual void paint(sf::RenderWindow* window) = 0;

    static Particle* getParticleSfmlPrimitive(float p_ax, float p_ay, float p_weight, Color p_color = Color());
    static Particle* getParticleSfmlSprite(float p_ax, float p_ay, float p_weight, sf::Sprite p_sprite, Color p_color = Color());

    static void fixDirection ();

    Color color;

private:
    float ax;
    float ay;
    float lastAX;
    float lastAY;

    float vectorX;
    float vectorY;
    float friction;
    float weight;
};

#endif /* PARTICLE_H_ */
