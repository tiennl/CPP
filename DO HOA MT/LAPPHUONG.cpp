#include <iostream>
#include <conio.h>
#include <graphics.h>
#include "DOHOA3D.h"

using namespace std;

ToaDo3D P1,P2,P3,P4,P5,P6,P7,P8;

void KhoiTaoBien(){
	D=100;
	R=100;
	theta=40;
	phi=20;
	P1.x=0;	P1.y=0;	P1.z=0;
	P2.x=0;	P2.y=1;	P2.z=0;
	P3.x=1;	P3.y=1;	P3.z=0;
	P4.x=1;	P4.y=0;	P4.z=0;
	P5.x=1;	P5.y=0;	P5.z=1;
	P6.x=0;	P6.y=0;	P6.z=1;
	P7.x=0;	P7.y=1;	P7.z=1;
	P8.x=1;	P8.y=1;	P8.z=1;
}

void VeLapPhuong(){
	DiDen(P1);	VeDen(P2);
	VeDen(P3);	VeDen(P4);
	VeDen(P1);	VeDen(P6);
	VeDen(P7);	VeDen(P8);
	VeDen(P5);	VeDen(P6);
	DiDen(P3);	VeDen(P8);
	DiDen(P2);	VeDen(P7);
	DiDen(P4);	VeDen(P5);
}

void MinhHoa(){
	KhoiTaoBien();
	KhoiTaoPhepChieu();
	VeLapPhuong();
	do{
		DieuKhienQuay();
		KhoiTaoPhepChieu();
		cleardevice();
		VeLapPhuong();
	}
	while (ch!=27);
}

int main(){
	pc=SongSong;
	ThietLapDoHoa();
	MinhHoa();
	closegraph();
}
