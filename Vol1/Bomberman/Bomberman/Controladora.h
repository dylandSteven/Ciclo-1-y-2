#pragma once
#include"MatrizBidimencional.h"
#include"JUgador.h"
#include"ArregloBomba.h"
#include"arrMejoras.h"
#include"ArrEnemigos.h"
class CControladora {
private:

	ArregloBomba* objarreglobom;
	CJugador* objJugador;
	CEscenario* objEscenario;
	arrMejoras* objArrMejoras;
	CArrEnemigos* objArregloEnemigo;
	bool habilidad;

	int nivel;
public:
	CControladora() 
	{
		objEscenario = new CEscenario();
		objJugador = new CJugador(50,50);
		objarreglobom = new ArregloBomba();
		objArrMejoras = new arrMejoras();
		objArregloEnemigo = new CArrEnemigos();
		nivel = 1;
		habilidad = false;
	
	}
	~CControladora() {}

	void CambiarNivel() 
	{
		objEscenario->generarMatriz();
	
	}
	
	void agregarBomba()
	{
		objarreglobom->crearBomba(objJugador->getX(), objJugador->getY());
	}

	void disminuirVidasPoeEnemigo(){
		for(int i =0;i<objArregloEnemigo->getenemigo().size();i++){
			if (objJugador->retornarRectangle().IntersectsWith(objArregloEnemigo->getenemigo().at(i)->retornarRectangle()))
			{
				objJugador->disminuirVidas();
			}
		}
	
	}

	void disminuirVidaporBomba()
	{
		int puntaIzquierda, puntaDerecha, centroInicioY, centrolFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentrofinalX;

		for (int i = 0; i < objarreglobom->getArregloBombas().size(); i++)
		{
			puntaIzquierda = objarreglobom->getArregloBombas().at(i)->getx() - 100;
			puntaDerecha = objarreglobom->getArregloBombas().at(i)->getx() + 150;
			PuntaSuperior = objarreglobom->getArregloBombas().at(i)->gety() - 100;
			PuntaInferior = objarreglobom->getArregloBombas().at(i)->gety() + 150;
			centroInicioY = objarreglobom->getArregloBombas().at(i)->gety();
			CentroInicioX = objarreglobom->getArregloBombas().at(i)->getx();
			CentrofinalX = objarreglobom->getArregloBombas().at(i)->getx() + 50;
			CentrofinalX = objarreglobom->getArregloBombas().at(i)->gety() + 50;

			if (objarreglobom->getArregloBombas().at(i)->getEstado() == Estado::explosion)
			{
				objJugador->disminuirVidas(puntaIzquierda, puntaDerecha,
					centroInicioY, centrolFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentrofinalX);
			
			
			}
		
		}
	}


	void crearEnemigosYMejoras() 	
	{
		objArregloEnemigo->crearEnemigo();
		objArrMejoras->agregarMejora();
	
	
	}
	CJugador* GetJugador()
	{
		return objJugador;
	}
	arrMejoras* getArregloMejoras()
	{
		return objArrMejoras;
	}
	CArrEnemigos* getArrEnemigos() {

		return objArregloEnemigo;
	}

	void agarrarMejoras()
	{

		for (int i = 0; i < objArrMejoras->getVectorMejoras().size(); i++)
		{
			if (objJugador->retornarRectangle().IntersectsWith(objArrMejoras->getVectorMejoras().at(i)->devolverRectangulo()))
			{
				switch (objArrMejoras->getVectorMejoras().at(i)->getTipoMejora())
				{
				case 1:
					objarreglobom->setBombas(objarreglobom->getBombas()+1);
					//objarreglobom->getArregloBombas().erase(objArrMejoras->getVectorMejoras().begin+ i);
					break;

				case 2:
					habilidad = true;
					//objarreglobom->getArregloBombas().erase(objArrMejoras->getVectorMejoras().begin + i);
					//patear();

					break;	
				case 3:
					objJugador->setVidas(objJugador->getVidas() - 1);
					//objarreglobom->getArregloBombas().erase(objArrMejoras->getVectorMejoras().begin + i);
					break;
				case 4:
					objJugador->setAcelerar(objJugador->getAcelerar()+3);
					//objarreglobom->getArregloBombas().erase(objArrMejoras->getVectorMejoras().begin + i);
					break;
				case 5:
					objJugador->setVidas(objJugador->getVidas() + 1);
					break;

				default:
					break;
				}
				objArrMejoras->eliminarenpos(i);
				//objarreglobom->getArregloBombas().erase(objArrMejoras->getVectorMejoras().begin + i);
			}
		
		}
	}


	int getNivael() { return nivel; }
	/*void patear() {
		if (habilidad == true) {
			for (int i = 0; i < objarreglobom->getArregloBombas().size(); i++)
			{
				if (objarreglobom->getArregloBombas().at(i)->getEstado() == Estado::normal && objJugador->retornarRectangle().IntersectsWith(objarreglobom->getArregloBombas.at(i)->getRentangulo()))
				{
					if (objJugador->getDireccion() == Direcciones::Abajo && objEscenario->getMatriz((objarreglobom->getArregloBombas().at(i)->gety() + 50) / 50, (objarreglobom->getArregloBombas().at(i)->getx()) / 50) == 2) {
						objarreglobom->getArregloBombas().at(i)->sety(objarreglobom->getArregloBombas().at(i)->gety() + 50);
						objarreglobom->getArregloBombas().at(i)->settiempo(0);
					}
					if (objJugador->getDireccion() == Direcciones::Arriba && objEscenario->getMatriz((objarreglobom->getArregloBombas().at(i)->gety() - 50) / 50, (objarreglobom->getArregloBombas().at(i)->getx()) / 50) == 2) {
						objarreglobom->getArregloBombas().at(i)->sety(objarreglobom->getArregloBombas().at(i)->gety() - 50);
						objarreglobom->getArregloBombas().at(i)->settiempo(0);
					}
					if (objJugador->getDireccion() == Direcciones::Derecha && objEscenario->getMatriz((objarreglobom->getArregloBombas().at(i)->gety()) / 50, (objarreglobom->getArregloBombas().at(i)->getx() + 50) / 50) == 2) {
						objarreglobom->getArregloBombas().at(i)->setx(objarreglobom->getArregloBombas().at(i)->getx() + 50);
						objarreglobom->getArregloBombas().at(i)->settiempo(0);
					}
					if (objJugador->getDireccion() == Direcciones::Izquierda && objEscenario->getMatriz((objarreglobom->getArregloBombas().at(i)->gety()) / 50, (objarreglobom->getArregloBombas().at(i)->getx() - 50) / 50) == 2) {
						objarreglobom->getArregloBombas().at(i)->setx(objarreglobom->getArregloBombas().at(i)->getx() - 50);
						objarreglobom->getArregloBombas().at(i)->settiempo(0);
					}
				}
			}
		}
	*/
	void dibujar(Graphics^ g, Bitmap^ bmpBase,Bitmap ^bmpSolido, Bitmap^ bmpBomba, 
		Bitmap^ bmpExplosion, Bitmap^ bmpDestruible,Bitmap ^bmpJugador,Bitmap^ bmpMejoras
		, Bitmap^ bmpEnemigo)
	{
	
		objEscenario->pintarBase(g, bmpBase);
		objEscenario->pintarMatriz(g, bmpSolido, bmpDestruible);
		objArrMejoras->dibujar(g, bmpMejoras, objEscenario->getMatriz());
		objJugador->moverJugador(g, bmpJugador,objEscenario->getMatriz());
		objarreglobom->dibujarBomba(g, bmpBomba, bmpExplosion, objJugador->getX(), objJugador->getY(), objEscenario->getMatriz());
		objArregloEnemigo->dibujar(g, bmpEnemigo, objEscenario->getMatriz());
		agarrarMejoras();
		//patear();

		disminuirVidaporBomba();
		disminuirVidasPoeEnemigo();
	}

};