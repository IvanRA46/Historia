#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Node.h"
using namespace std;
using namespace sf;

class Historia{
public:
	Historia(int width, int height, string title);
	void Mostrar();
	void Llenar_Ma();
	void Loop();
	Node* Examen = new Node("Examen");
	Node* Pasar = new Node("1.Pasar");
	Node* Reprobar = new Node("2.Reprobar");
	Node* Renunciar = new Node("4.Renunciar");
	Node* Extra = new Node("3.Extra");
	Node* Reprobarlo = new Node("6.Reprobarlo");
	Node* Dejarlo = new Node("5.Dejarlo");
	Node* Fin = new Node("0.Fin");
private:
	RenderWindow* ventana;
	int fps;
};

