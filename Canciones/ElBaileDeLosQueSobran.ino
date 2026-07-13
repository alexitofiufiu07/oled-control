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



int C__=  261/4;
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


int 

 tempo = 117;  
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

void setup() {
 // initialize digital pin as an output.

 lcd.begin(16, 2);
 
 lcd.setCursor(0,0);
 lcd.print("El baile de los ");
 lcd.setCursor(0,1);
 lcd.print("que sobran      ");

//lcd.createChar(7, corchea);
 

  pinMode(RELAY_PIN, Estado);


  
 



  delay(1900);


}

void loop() {

Unanse();                      
Nadie();
  LaraLa();
  LaraLa_fin();
 delay(1900);

}


void Unanse(){

  textopan("/               ","U               ");
  nota(C2,c );
  textopan("/               ","Unan            ");
  nota( G,c );
  textopan("/               ","Unanse al       ");
  nota(E2,n );
  textopan("/               ","Unanse al bai   ");
  nota(E2,np);
  textopan("/               ","Unanse al baile ");
  nota(C2,c);

  textopan("                ","Oh              ");
     nota(C ,b/3);
     textopan("                ","Oh Oh           ");
     nota(B_,b/3);
     textopan("                ","Oh Oh Oh        ");
     nota(G_,b/3+b);

  //nota(Sil,b);

  textopan("de              ","                ");
  nota(C2,c );
  textopan("de los          ","                ");
  nota( G,c );
  textopan("de los          ","que             ");
  nota(E2,n );
  textopan("de los          ","que so          ");
  nota(E2,np);
  textopan("de los          ","que sobran      ");
  nota(C2,c);


    textopan("Oh              ","                ");
     nota(C ,b/3);
     textopan("Oh Oh           ","                ");
     nota(B_,b/3);
     textopan("Oh Oh Oh        ","                ");
     nota(F_,b/3+b);
   
  } 

void Nadie(){
                              
  textopan("                ","Na              ");  
  nota(C2,c );
  textopan("                ","Nadie           ");
  nota( G,c );
  textopan("                ","Nadie nos       ");
  nota(E2,n );
  textopan("va              ","a e             ");
  nota(E2,c);
  textopan("va              ","a echar         ");
  nota(F2,c);
  textopan("va              ","a echar de      ");
  nota(G2,c);
  textopan("va          /   ","a echar de mas  ");
  nota(C2,c);


      textopan("Oh              ","                ");
     nota(C ,b/3);
         textopan("Oh Oh           ","                ");
     nota(B_,b/3);
         textopan("Oh Oh Oh        ","                ");
     nota(G_,b/3+b);

  //nota(Sil,b);

  textopan("Na              ","                ");
  nota(C2,c );
  textopan("Nadie           ","                ");
  nota( G,c );
  textopan("Nadie nos       ","                ");
  nota(E2,n );
  textopan("Nadie nos qui   ","                ");
  nota(E2,c);
  textopan("Nadie nos quiso ","                ");
  nota(F2,c);
  textopan("Nadie nos quiso ","ayu             ");
  nota(G2,c);
  textopan("Nadie nos quiso ","ayudar          ");
  nota(C2,n);


  textopan("Nadie nos quiso ","ayudar de       ");
  nota(C2,c);
  textopan("Nadie nos quiso ","ayudar de ver   ");
  nota(D2,c);
  textopan("Nadie nos quiso ","ayudar de verdad");
  nota( A,b+c);

  } 



void LaraLa(){

  textopan("                ","La              ");
  nota(C2,c );
  textopan("                ","La ra           ");
  nota( G,c );
  textopan("                ","La ra la        ");
  nota(E2,n );
  textopan("                ","La ra la la     ");
  nota(C2,b);
  
  

  textopan("                ","Oh              ");
     nota(C ,b/3);
     textopan("                ","Oh Oh           ");
     nota(B_,b/3);
     textopan("                ","Oh Oh Oh        ");
     nota(G_,b/3+b);

  //nota(Sil,b);

  textopan("                ","La              ");
  nota(C2,c );
  textopan("                ","La ra           ");
  nota( G,c );
  textopan("                ","La ra la        ");
  nota(E2,n );
  //textopan("                ","La ra la la     ");
  nota(E2,c);
  textopan("                ","La ra la la ah  ");
  nota(C2,np);


    textopan("Oh              ","                ");
     nota(C ,b/3);
     textopan("Oh Oh           ","                ");
     nota(B_,b/3);
     textopan("Oh Oh Oh        ","                ");
     nota(F_,b/3+b);
   
  } 

  
void LaraLa_fin(){

  textopan("                ","La              ");
  nota(C2,c );
  textopan("                ","La ra           ");
  nota( G,c );
  textopan("                ","La ra la        ");
  nota(E2,n );
  textopan("                ","La ra la la     ");
  nota(C2,b);
  
  

  textopan("                ","Oh              ");
     nota(C ,b/3);
     textopan("                ","Oh Oh           ");
     nota(B_,b/3);
     textopan("                ","Oh Oh Oh        ");
     nota(G_,b/3+b);

  //nota(Sil,b);

  textopan("                ","La              ");
  nota(C2,c );
  textopan("                ","La ra           ");
  nota( G,c );
  textopan("                ","La ra la        ");
  nota(E2,n );
  textopan("                ","La ra la la     ");
  nota(E2,c);
  textopan("                ","La ra la la ah  ");
  nota(C2,np);


    textopan("Oh              ","                ");
     nota(C ,b/3);
     textopan("Oh Oh           ","                ");
     nota(B_,b/3);
     textopan("Oh Oh Oh        ","                ");
     nota(F_,b/3 );


   nota(D2,np);
  nota(C2,b+c);

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
  void ImprimeCorcheaAbajo(int i){

  lcd.setCursor( i, 1); //put it on line 3, column 19.
  lcd.write(byte(7)); //print our custom char backslash

  
  }

void nota_sf(int N ,int d ){

    int  ttt = sf/2;
    
    nota( N*0.84089641525 , ttt);
    nota( N*0.89089871814 , ttt);
    nota( N*0.94387431268 , ttt);
    
    nota( N              , d - 3*ttt);


}
  
