#include <LiquidCrystal.h>
//LCD pin to Arduino
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);

const int RELAY_PIN = 2;  // the Arduino pin, which connects to the IN pin of relay
 

int pinBuzzer = 12;
int Estado = LOW;



int C__ =  261/4;
int Cs__=  277/4;
int D__ =  293/4 ;
int Ds__=  311/4;
int E__ =  329/4 ;
int F__ =  349/4 ;
int Fs__=  369/4;
int G__ =  391/4 ;
int Gs__=  415/4;
int A__ =  440/4 ;
int As__=  466/4;
int B__ =  493/4 ;

int C_ =  261/2;
int Cs_=  277/2;
int D_ =  293/2 ;
int Ds_=  311/2;
int E_ =  329/2 ;
int F_ =  349/2 ;
int Fs_=  369/2;
int G_ =  391/2 ;
int Gs_=  415/2;
int A_ =  440/2 ;
int As_=  466/2;
int B_ =  493/2 ;


int C =  261;
int Cs=  277;
int D =  293 ;
int Ds=  311;
int E =  329 ;
int F =  349 ;
int Fs=  369;
int G =  391 ;
int Gs=  415;
int A =  440 ;
int As=  466;
int B =  493 ;



int C2   =524;
int Cs2  =555;
int D2   =588;
int Ds2  =623;
int E2   =660;
int F2   =699;
int Fs2  =740;
int G2   =784;
int Gs2  =831;
int A_2   = 880;
int As2  =933;
int B2   =988;


int  C3   =524*2;
int Cs3   =555*2;
int  D3   =588*2;
int Ds3   =623*2;
int  E3   =660*2;
int  F3   =699*2;
int Fs3   =740*2;
int  G3   =784*2;
int Gs3   =831*2;
int A_3   =880*2;
int As3   =933*2;
int  B3   =988*2;

int  C4   =524*4;
int Cs4   =555*4;
int  D4   =588*4;
int Ds4   =623*4;
int  E4   =660*4;
int  F4   =699*4;
int Fs4   =740*4;
int  G4   =784*4;
int Gs4   =831*4;
int A_4   =880*4;
int As4   =933*4;
int  B4   =988*4;


int tempo = 96;
int semi = 60000/( tempo * 4 *2);

int corch = 2*semi;
int negra = corch*2;
int np = corch*3;

int blanca = negra*2;
int redonda = blanca*2;
int rep = 3*negra;
int bnp = 3*negra+3*corch;

int b =blanca;
int r =2*b;
int n = negra;
int c = corch;
int s = semi;
int f = s/2;
int sf = f/2;

int cp = c+s;
int Sil = 10;

int retardo = 115;

void nota(int nota, int duracion){
	tone(pinBuzzer,nota, duracion);
	delay(duracion);
	noTone(pinBuzzer);
	delay(duracion);
}

void notaP(int nota, int duracion){
	tone(pinBuzzer,nota, duracion);
	delay(2*duracion);
	noTone(pinBuzzer);
}


void setup() {


 lcd.begin(16, 2);
  lcd.setCursor(0,0);

 lcd.print("Mi Buen Amor    ");
 lcd.setCursor(0,1);
 lcd.print("Mon Laferte     ");


delay(1000);

  pinMode(RELAY_PIN, Estado);
}

void loop() {

DespuesDeTodo();
Interludio();
MiBuenAmor1();
MiBuenAmor2();
delay(2500);
}

void DespuesDeTodo(){
// 67
textopan("Despues de todo  ","                ");
	nota(D,np);
	nota(G,b);
	nota_sf(Fs,n);
	nota(D,c);
	nota(E,c);
		nota(D__,c);
		nota(G__,c);
	
textopan("lo que tuve que  ","pasar           ");
	nota(G,c);
	nota(Fs,c);
	nota(D,c);
	nota(E,c);
		nota(D__,c);
		nota(G__,c);
	nota(E,c);
	nota(B_,c);
	nota(E,s);
	nota(B_,s);
	nota(D,n);
	nota(Sil,c);
textopan("Las terapias...  ","                ");
	nota(G,cp);
	nota(Fs,s);
	nota(D,c);
	nota(E,c);
		nota(D__,c);
		nota(G__,c);
textopan("Los amores de    ","mentira...      ");
	nota(G,cp);
	nota(Fs,s);
	nota(D,c);
	nota(E,c);
		nota(E__,c);
		nota(A__,c);
	nota(G,c);
	nota(Fs,c);
	nota(D,c);
	nota(E,c);
		nota(E__,c);
		nota(A__,c);


textopan("Mas mentiras...  ","                ");
	nota(G,cp);
	nota(Fs,s);
	nota(D,c);
	nota(Ds,c);

	nota(Fs__,c);	
	nota(B__,c);	

textopan("Ahora quieres   ","que sea tu amiga");
nota(Fs2,c);
nota( G2,c);
nota(A_2,c);
nota( G2,c);
nota(Fs2,n);

nota(Fs2,c);
nota( G2,c);
nota( G2,c);
nota(Fs2,c);
nota( E2,c);

	nota(B__,c);
	nota(G__,c);
	nota(E__,c);
	nota(B__,c);
	nota(E__,c);
	nota(G__,c);
	nota(B__,c);

textopan("Pues, amigo,    ","dime            ");
  nota_sf(G2,c);
  nota(G2,c);
  nota(A_2,c);
  nota(B2,n);
  nota(Sil,c);

  nota(A_2,c);
  nota( B2,c);
textopan("como borro esto  ","que siento...   ");
  nota(A_2,c);
  nota(A_2,c);
  nota(A_2,c);
  nota(A_2,c);
  nota( B2,c);
  nota( C3,c);
	nota(B2,c);
	nota(A_2,n);
}
void Interludio(){

		nota( A_,c);
		nota(Fs_,c);
		nota(D_,c);

		nota(A__,c);
		nota(D_,c);
		nota(Fs_,c);
		nota(A_,c);
		nota(Fs_,c);
		nota(D_,c);


}

void MiBuenAmor1(){
		nota(D__,c);
		nota(D__,c);
		nota(D__,c);
textopan("Mi buen amor    ","                ");
	nota_sf6(G2,np);
	nota(A_2,np);
	nota(D3,np);
	nota(B2,np);

textopan("    :'(         ", "                ");
		nota_sf(B,np);
		nota_sf(A,np);
		nota_sf(G,np);

		nota_sf(G,c );
		nota_sf(B__,c );
		nota_sf(D_,c );
		nota_sf(G_,c );
		

textopan("si no quieres   ","regresar        ");
    nota(A_2,c);
    nota( B2,c);
    nota( C3,n);
    nota( B2,n);

    nota(A_2,c);
    nota( G2,c);
    nota(A_2,c);
    nota( B2,c);
    nota(A_2,b);

textopan("           :'(  ", "                ");
	nota(C2,s);
	nota( B,s);
	nota(C2,s);
	nota( B,s);
	nota(C2,s);
	nota( B,s);

	nota(C2,n);
	nota( B,c);
	nota( A,c);
		nota(Ds_,c);
		nota(Fs_,c);
		nota( B_,c);
	
textopan("Por que vuelves ","a buscarme      ");
nota(A_2,c);
nota( B2,c);
nota( C3,n);
nota( B2,n);
nota(A_2,c);
nota( B2,c);
nota(A_2,n);
nota( G2,n);
textopan("una vez mas?    ","                ");
nota(Fs2,c);
nota( G2,c);
nota( G2,n);
	nota(G_,c);
	nota(B_,c);
textopan("No me pidas     ","                ");

    nota( Fs2,c);
    nota( G2,c);
    nota(A_2,c);
    nota( B2,np);


textopan("que te de una   ","ultima noche    ");

    nota(A_2,c);
    nota( B2,c);
    nota(A_2,n);
    nota(A_2,n);
    nota( B2,c);
    nota(A_2,c);
//===========================
    nota( B2,c);
    nota_sf(A_2,n);

textopan("           :'(  ", "                ");
	nota(A_,c);
	nota(Fs_,c);
	nota(D_,c);

	nota(A__,c);
	nota(D_,c);
	nota(Fs_,c);
	nota(A_,c);
	nota(Fs_,c);
	nota(D_,c);
}
void MiBuenAmor2(){
	nota(D__,c);
	nota(D__,c);
	nota(D__,c);
textopan("Mi buen amor    ","                ");
	nota_sf6(G2,np);
	nota(A_2,np);
	nota(D3,np);
	nota(B2,np);

textopan("           :'(  ", "                ");
		nota_sf(B,np);
		nota_sf(A,np);
		nota_sf(G,np);

		nota_sf(G,c );
		nota_sf(B__,c );
		nota_sf(D_,c );
		nota_sf(G_,c );
textopan("Parece facil    ","para ti         ");
    nota(A_2,c);
    nota( B2,c);
    nota( C3,n);
    nota( B2,n);

    nota(A_2,c);
    nota( G2,c);
    nota(A_2,c);
    nota( B2,c);
    nota(A_2,b);

	nota(C2,s);
	nota( B,s);
	nota(C2,s);
	nota( B,s);
	nota(C2,s);
	nota( B,s);

	nota(C2,n);
	nota( B,c);
	nota( A,c);
		nota(Ds_,c);
		nota(Fs_,c);
		nota( B_,c);
	
textopan("Alejarte para   ","luego exigir    ");
nota(A_2,c);
nota( B2,c);
nota( C3,n);
nota( B2,n);
nota(A_2,c);
nota( B2,c);
nota(A_2,n);
nota( G2,n);
nota(Fs2,c);
nota( G2,c);
nota( G2,n);
	nota(G_,c);
	nota(B_,c);

textopan("Que te quiera   ","como si nada    ");
nota(Fs2,c);
nota( G2,c);

    nota(A_2,c);
    nota( B2,np);

    nota(A_2,c);
    nota( B2,c);
    nota(A_2,n);
    nota(A_2,n);
    nota( B2,c);
    nota(A_2,c);
//===========================

textopan("Nada, nada      ","                ");
    nota(B2,c)	;
    nota(A_2,n)	;
    nota(B2,c)	;
    nota(A_2,n)	;
    nota(B2,c)	;
    nota(A_2,c)	;
textopan("                ","yo sintiera     ");
    nota(G2,np)	;
    nota(Fs2,c)	;
    nota(A_2,n)	;
    nota( G2,n)	;

	nota(D_,c);
	nota(B__,c);
textopan("Mi buen amor    ","                ");
	nota(G__,c);
	nota(B__,c);
	nota(D_,c);

	nota(G_,c);
	nota(D_,c);
	nota(B_,c);

	nota(G__,c);
	nota(B__,c);
	nota(D_,c);

	nota(D2,np);
	nota(C2,b );
	nota(Sil,c );

	nota(B,c);
	nota(D2,b+n);
}


void nota_sf6(int N ,int d ){

    int  ttt = sf/2;
    nota( N*0.70710678118 , ttt);
    nota( N*0.74915353843 , ttt);
    nota( N*0.79370052598 , ttt);
    nota( N*0.84089641525 , ttt);
    nota( N*0.89089871814 , ttt);
    nota( N*0.94387431268 , ttt);
    
    nota( N              , d - 6*ttt);


}

void nota_sf(int N ,int d ){

    int  ttt = sf/2;
    
    nota( N*0.84089641525 , ttt);
    nota( N*0.89089871814 , ttt);
    nota( N*0.94387431268 , ttt);
    
    nota( N              , d - 3*ttt);


}

void textopan(String S1,String S2){
  
 lcd.setCursor(0,0);
 lcd.print(S1);
 lcd.setCursor(0,1);
 lcd.print(S2);

  
  }

  void textoAbajo(String S2){
 
 lcd.setCursor(0,1);
 lcd.print(S2);

  
  }

void  suenaRele(){
  
  
  if ( Estado == LOW ){  
    Estado = HIGH;
    
  }  
  else {
    Estado = LOW;
  }
  pinMode(RELAY_PIN, Estado);

  
  }
