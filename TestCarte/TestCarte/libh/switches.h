/*
*   La classe Switches est un widget qui affiche les 8 dipswitches de l'interface
*   graphique.
*   
*   $Author: bruc2001 $
*   $Date: 2014-12-18 11:43:08 -0500 (jeu., 18 déc. 2014) $
*   $Revision: 103 $
*   $Id: switches.h 103 2014-12-18 16:43:08Z bruc2001 $
*
*   Copyright 2013 Département de génie électrique et génie informatique
*                  Université de Sherbrooke  
*/
#ifndef SWITCHES_H
#define SWITCHES_H

#include<QWidget>
#include<QSlider>

class Switches : public QWidget
{
public:
   Switches(QWidget *parent, int numSwitches, int height, int width);
   ~Switches();

   void set(const int state);
   int get() const;
private:
   const int nbSwitches, height, width;
   QSlider **switches;
   int state;
};

#endif // SWITCHES_H
