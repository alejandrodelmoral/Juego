#include "Personaje.h"


Personaje::Personaje()
{
	sprite = new Sprite("imagenes/personaje.png", posicion.x,posicion.y, 10, 10);
	sprite->setPos(2, 4);
	sprite->setVel(0, 0);
	aceleracion.y = 0;
	
}

void Personaje::setPos(float x, float y)
{
	sprite->setPos(x, y);
}

void Personaje::dibuja()
{
	sprite->draw();

	//glPushMatrix();
	//glColor3ub(0, 255, 0);
	//glTranslatef(posicion.x, posicion.y, 0);
	//glutSolidSphere(radio, 20, 2);
	//glPopMatrix();

	disparos.dibuja();
}

void Personaje::mueve(float t)
{
	posicion=sprite->getPos();
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;

	

	if (posicion.x < 0)
	{
		posicion.x = 0;
	}
	if (posicion.y < 0)
	{
		posicion.y = 0;
	}
	if (posicion.y > 46)
	{
		posicion.y = 46;
	}
	sprite->setPos(posicion.x, posicion.y);
	sprite->setVel(velocidad.x, velocidad.y);

	disparos.mueve(t);
}

void Personaje::dispara(float vx, float vy)
{
	Disparo* d = new Disparo();

	d->setPos(posicion.x, posicion.y);
	d->setVel(vx, vy);
	disparos.agregar(d);
}