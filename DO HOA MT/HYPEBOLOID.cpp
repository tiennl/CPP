#include <iostream>
#include <conio.h>
#include <graphics.h>
#include "DOHOA3D.h"

using namespace std;

float v,vMin,vMax,dv,u,uMin,uMax,du;

float fx(float u, float v){
	return u;
}

float fy(float u, float v){
	return v;
}

float fz(float u, float v){
	return u*u-v*v;
}

void DuongCongV(){
	ToaDo3D P;
	v=vMin;
	while (v<=vMax){
		u=uMin;
		P.x=fx(u,v);
		P.y=fy(u,v);
		P.z=fz(u,v);
		DiDen(P);
		while (u<=uMax){
			P.x=fx(u,v);
			P.y=fy(u,v);
			P.z=fz(u,v);
			VeDen(P);
			u+=du;
		}
		v+=dv;
	}
}

void DuongCongU(){
	ToaDo3D P;
	u=uMin;
	while (u<=uMax){
		v=vMin;
		P.x=fx(u,v);
		P.y=fy(u,v);
		P.z=fz(u,v);
		DiDen(P);
		while (v<=vMax){
			P.x=fx(u,v);
			P.y=fy(u,v);
			P.z=fz(u,v);
			VeDen(P);
			v+=dv;
		}
		u+=du;
	}
}

int main(){
	theta=60;
	phi=20;
	R=2;
	D=200;
	uMin=-1; uMax=1; du=0.1;
	vMin=-1; vMax=1; dv=0.1;
	ThietLapDoHoa();
	do{
		KhoiTaoPhepChieu();
		DuongCongU();
		DuongCongV();
		DieuKhienQuay();
	}
	while (ch!=27);
	closegraph();
}
