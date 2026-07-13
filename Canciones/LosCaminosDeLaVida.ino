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





int pinBuzzer = 12;

int  C__ =  261/4;
int Cs__=  277/4;
int  D__ =  293/4 ;
int Ds__=  311/4;
int  E__ =  329/4 ;
int  F__ =  349/4 ;
int Fs__=  369/4;
int  G__ =  391/4 ;
int Gs__=  415/4;
int  A__ =  440/4 ;
int As__=  466/4;
int  B__ =  493/4 ;

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


int Sil = 5;
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

int C3  =1047;
int Cs3  =555*2;
int D3   =588*2;
int Ds3  =623*2;
int E3   =660*2;
int F3   =699*2;
int Fs3  =740*2;
int G3   =784*2;
int Gs3  =831*2;
int A_3   = 880*2;
int As3  =933*2;
int B3   =988*2;



int tempo =158*2;

int negra=60000/tempo;
int semi = negra/4;

int fusa =semi/2;
int corch = 2*semi;
int np = corch*3;

int blanca = negra*2;
int redonda = blanca*2;
int rep = 3*negra;
int bnp = 3*negra+3*corch;


int b = blanca;
int r = 2*blanca;
int n = negra;
int c = corch;

int s = semi;
int cp = c+s;
int f = fusa;
int sf = f/2;



int retardo = 100;

void nota(int nota, int duracion){
    nota = nota*2;
  tone(pinBuzzer,nota, duracion);
  delay(duracion);
  noTone(pinBuzzer);
  delay(duracion);
}


byte laDuda[8] = {
  B00000,
  B00100,
  B00000,
  B00100,
  B01000,
  B10000,
  B10001,
  B01110
};


void setup() {
 // initialize digital pin as an output.


 lcd.begin(16, 2);
 
 lcd.setCursor(0,0);
 lcd.print("                ");
 lcd.setCursor(0,1);
 lcd.print("                ");

//lcd.createChar(7, corchea);

 lcd.createChar(7, laDuda);

textopan("                ","                ");


  delay(1900);


}

void loop() {


LosCaminos_1();
LosCaminos_2();

Yo_pensaba_que_la_vida_era_distinta();
Que_mi_madre_preocupada_se_esmeraba();

delay(9000);
}
 

void LosCaminos_1(){

  nota(Sil,c);
textopan("Los caminos     ","                "); 
  nota(E ,n);
  nota(E ,c);
  nota(A ,c);
  nota(A ,c);
  nota(C2,c);
textopan("Los caminos     ","de la vida      "); 
  nota(C2,c);
  nota_sf(E2,n);
  nota(E2,b+c);
textopan("no son los que  ","                "); 
  nota(C2,c);
  nota(E2,c);
  nota(E2,n);
  nota(C2,c);
  nota(E2,n);
textopan("no son los que  ","yo pensaba    :S"); 
  nota_sf(E2,c);
  nota(D2,n);
  nota(D2,b+n);
textopan("no son los que  ","                "); 
  nota(B,c);
  nota_sf(D2,c);
  nota(D2,n);
  nota(B,c);

textopan("      /         ","yo creIa      :("); 
  nota(D2,n);
  nota(D2,c);
  nota_sf(C2,n);
  nota(C2,b+n);
textopan("no son los que  ","                "); 
  nota(A ,c);
  nota_sf(C2,c);
  nota(C2,n);


textopan("no son los que  ","imaginaba     -("); 
  
  nota(A ,c);
  nota(C2,n);

  nota(F2,c);
  nota_sf(E2,n);
  nota(E2,r-c);

}

void LosCaminos_2(){

  nota(Sil,c);
textopan("Los caminos     ","                "); 
  nota(E ,n);
  nota(E ,c);
  nota(A ,c);
  nota(A ,c);
  nota(C2,c);
textopan("Los caminos     ","de la vida      "); 
  nota(C2,c);
  nota_sf(E2,n);
  nota(E2,b+n-c);
textopan("           /    ","son muy difIcil "); 
  nota(C2,c);
  nota_sf(E2,c);
  nota(E2,n);
  nota(C2,c);
  nota(E2,n);
textopan("                ","de andarlos     "); 
  nota(E2,c);
  nota_sf(D2,n);
  nota(D2,b+n);
textopan("   /            ","difIcil         "); 
  nota(B,c);
  nota_sf(D2,c);
  nota(D2,n);
  nota(B,c);
textopan("                ","de caminarlos   "); 
  nota_sf(D2,n);
  nota(D2,c);
  nota(C2,c+c);
  nota(C2,b+n-c);
textopan("Y no encuentro  ","                "); 
  nota(A ,c);
  nota_sf(C2,c);
  nota(C2,n);

  nota(A ,c);
  nota(C2,n);

textopan("Y no encuentro  ","la salida       "); 
  nota(F2,c);
  nota_sf(E2,n);
  nota(E2,r-c);

}

void Yo_pensaba_que_la_vida_era_distinta(){

  nota(Sil,c);
textopan("Yo pensaba      ","que la vida     "); 
  nota(E,n);
  nota(E,c);
  nota(A,c);
  nota(A,c);

  nota(C2,c);
  nota(C2,c);
  nota(E2,c);
  nota(E2,b);
textopan("era distinta    ","                "); 
  nota(C2,c);
  nota(E2,c);
  nota(E2,c);
  nota(D2,c);
  nota(D2,c);
  
textopan("Cuando era      ","chiquitito      "); 
  nota(D,c);
  nota(D,c);
  nota(G,c);
  nota(G,c);
  nota(B,c);
  nota(B,c);
  nota(D2,b+c);
textopan("      /         ","Yo creIa        "); 
  nota(B,c);
  nota(D2,c);
  nota(D2,c);
  nota(C2,c);
  nota(C2,c);
textopan("Que las cosas   ","                "); 
  
  nota(C ,c);
  nota(C ,c);
  nota(F ,c);
  nota(F ,c);
textopan("      /         ","eran facil      "); 
  nota(A ,c);
  nota(A ,c);
  nota(C2,b+c);
textopan("                ","como ayer       "); 

  nota(A ,c);
  nota(C2,c);
  nota(F2,c);
  nota(E2,r  );
}


void Que_mi_madre_preocupada_se_esmeraba(){
  nota(Sil,c);
textopan("Que mi madre    ","preocupada      "); 
  nota_sf(E2,n);
  nota(Ds2,c);
  nota(E2,c);
  nota(Ds2,c);
  nota(E2,c);
  nota(Ds2,c);
  nota_sf(E2,c);
  nota(E2,np);
  nota(Sil,c);

textopan("se esmeraba     ","                "); 
  nota_sf(C2,c);
  nota_sf(E2,c);
  nota(E2,c);
  nota(D2,c);
  nota(D2,c);
textopan("Por darme todo  ","                "); 
  nota(D ,c);
  nota(D ,c);
  nota(G ,c);
  nota(G ,c);
  nota(B ,c);
textopan("lo que          ","necesitaba      "); 
  nota(B ,c);
  nota_sf(D2,b+c);

  nota(B ,c);
  nota(D2,c);
  nota(D2,c);
  nota(C2,c);
  nota(C2,c);
textopan("Y hoy me doy    ","cuenta que tanto"); 
  nota(C ,c);
  nota(C ,c);
  nota(F ,c);
  nota(F ,c);
  nota(A ,c);
  nota(A ,c);
  nota_sf(C2,b+c);
  nota(A,c);
textopan("  /             ","asI no es       "); 
  nota(C2,c);
  nota(F2,c);
  nota(E2,b);
}
void textopan(String S1,String S2){
  
 lcd.setCursor(0,0);
 lcd.print(S1);
 lcd.setCursor(0,1);
 lcd.print(S2);

  
  }

  

void nota_sf(int N ,int d ){

    int  ttt = sf/2;
    
    nota( N*0.84089641525 , ttt);
    nota( N*0.89089871814 , ttt);
    nota( N*0.94387431268 , ttt);
    
    nota( N              , d - 3*ttt);


}
