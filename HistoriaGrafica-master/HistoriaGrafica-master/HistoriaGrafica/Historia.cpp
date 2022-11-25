#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Node.h"
#include "Historia.h"

using namespace std;
using namespace sf;


Historia::Historia(int width, int height, string title){
	Llenar_Ma();
	fps = 60;
	ventana = new RenderWindow(VideoMode(width, height), title);
	ventana->setFramerateLimit(fps);
	Loop();
}

void Historia::Loop(){
	Texture texture;
	Sprite sprite;
	Music musica;
	texture.loadFromFile("imagenes/init.jpg");
	sprite.setTexture(texture);
	musica.openFromFile("canciones/intro.ogg");
	musica.setLoop(true);
	while (ventana->isOpen()) {
		musica.play();
		Event event;
		while (ventana->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				ventana->close();
		}
		ventana->clear();
		ventana->draw(sprite);
		ventana->display();
		system("cls");
		cout << "ARBOL BINARIO\n\n" << endl;
		system("pause");
		system("cls");
		Mostrar();
	}
}

void Historia::Mostrar(){
	unsigned int opc;
	int camino;
	string nombre;
	Texture texture;
	Sprite sprite;
	texture.loadFromFile("imagenes/end.jpg");
	sprite.setTexture(texture);
	Node* actual = new Node("aux");
	Node* inicial = new Node("aux");
	actual = Examen;
	inicial = Examen;
	while (!actual->matrix.empty()){
		ventana->clear();
		ventana->draw(actual->GetScreen());
		ventana->display();
		system("cls");
		cout << "�Que quieres hacer?\n";
		for (auto x : actual->matrix) {
			if (x->GetName() == "Fin") {
				system("cls");
				cout << "Ingresa la unica opcion\n";
			}else cout << x->GetName() << endl;
		}cout << endl;
		cout << "Elige una opcion: ";
		cin >> camino;
		if (camino == 0) {
			nombre = "0.Fin";
		}
		if (camino == 1) {
			nombre = "1.Pasar";
		}
		if (camino == 2) {
			nombre = "2.Reprobar";
		}
		if (camino == 3) {
			nombre = "3.Extra";
		}
		if (camino == 4) {
			nombre = "4.Renunciar";
		}
		if (camino == 5) {
			nombre = "5.Dejarlo";
		}
		if (camino == 6) {
			nombre = "6.Reprobarlo";
		}
		for_each(actual->matrix.begin(), actual->matrix.end(), [&actual, nombre](Node* siguiente) {
			if (siguiente->GetName() == nombre) actual = siguiente;
			});	
		
		ventana->clear();
	}
	system("cls");
	cout << "Quieres volver a jugar?\n";
	cout << "0.No\n";
	cout << "1.Si\n";
	cout << "\nElige una opcion: ";
	cin >> opc;
	if (opc == 1) actual = inicial;
	else {
		ventana->clear();
		ventana->draw(sprite);
		ventana->display();
		system("cls");
		system("pause");
		ventana->close();
	}
}

void Historia::Llenar_Ma() {
	Examen->SetScreen("examen");
	Reprobar->SetScreen("repro");
	Pasar->SetScreen("pas");
	Renunciar->SetScreen("ren");
	Extra->SetScreen("ex");
	Reprobarlo->SetScreen("rep");
	Dejarlo->SetScreen("dejar");
	Fin->SetScreen("end");

	Examen->matrix = { Pasar,Reprobar };
	Pasar->matrix = { Fin };
	Reprobar->matrix = { Extra,Renunciar };
	Renunciar->matrix = { Fin };
	Extra->matrix = { Dejarlo,Reprobarlo };
	Reprobarlo->matrix = { Fin };
	Dejarlo->matrix = { Fin };
	Fin->matrix = {};
}