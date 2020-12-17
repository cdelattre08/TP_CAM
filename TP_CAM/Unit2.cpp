//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <stdio.h>
#include <stdlib>
#include <windows.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::buttonConnexionClick(TObject *Sender)
{
   portserie.OuvrirPort();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonGaucheClick(TObject *Sender) // Bouton qui décale la CAM vers la gauche
{ // Trames qui permettent de décaler la CAM vers le haut
	char trameG[9];

	trameG[0] = 0x81;
	trameG[1] = 0x01;
	trameG[2] = 0x06;
	trameG[3] = 0x01;
	trameG[4] = 0x18;
	trameG[5] = 0x14;
	trameG[6] = 0x01;
	trameG[7] = 0x03;
	trameG[8] = 0xFF;

	portserie.sendMsg(trameG);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonHautClick(TObject *Sender) // Bouton qui décale la CAM vers le haut
{ // Trames qui permettent de décaler la CAM vers le haut
	char trameH[9];

	trameH[0] = 0x81;
	trameH[1] = 0x01;
	trameH[2] = 0x06;
	trameH[3] = 0x01;
	trameH[4] = 0x18;
	trameH[5] = 0x14;
	trameH[6] = 0x03;
	trameH[7] = 0x01;
	trameH[8] = 0xFF;

	portserie.sendMsg(trameH);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonDroitClick(TObject *Sender) // Bouton qui décale la CAM vers la droite
{ // Trames qui faut décaler la CAM vers la droite
	char trameD[9];

	trameD[0] = 0x81;
	trameD[1] = 0x01;
	trameD[2] = 0x06;
	trameD[3] = 0x01;
	trameD[4] = 0x18;
	trameD[5] = 0x14;
	trameD[6] = 0x02;
	trameD[7] = 0x03;
	trameD[8] = 0xFF;

	portserie.sendMsg(trameD);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonBasClick(TObject *Sender) // Bouton qui décale la CAM vers le bas
{ // Trames qui fait décaler la caméra ves le bas
	char trameB[9];

	trameB[0] = 0x81;
	trameB[1] = 0x01;
	trameB[2] = 0x06;
	trameB[3] = 0x01;
	trameB[4] = 0x18;
	trameB[5] = 0x14;
	trameB[6] = 0x03;
	trameB[7] = 0x02;
	trameB[8] = 0xFF;

	portserie.sendMsg(trameB);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonCentreClick(TObject *Sender) // Bouton qui décale la CAM vers le Centre
{
	char trameC[5];

	trameC[0] = 0x81;
	trameC[1] = 0x01;
	trameC[2] = 0x06;
	trameC[3] = 0x04;
	trameC[4] = 0xFF;

	portserie.sendMsg(trameC);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ZoomEtDezoomChange(TObject *Sender)
{ // Trames qui permettent de zoomer et dézoomer
	char trameZD[6];

	trameZD[0]= 0x81;
	trameZD[1]= 0x01;
	trameZD[2]= 0x04;
	trameZD[3]= 0x07;
	trameZD[4]= 0x03;
	trameZD[5]= 0xFF;

	char zoomordezoom;
	zoomordezoom = ZoomEtDezoom->Position;
	trameZD[4] = zoomordezoom;

	portserie.sendMsg(trameZD);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonBalayageClick(TObject *Sender)
{
	// TO DO...
}
//---------------------------------------------------------------------------

