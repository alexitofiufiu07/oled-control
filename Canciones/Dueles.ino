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


int tempo = 142;  
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

int tttt= b+cp  - (c+s+c+c+f);

void nota(int nota, int duracion){
  tone(pinBuzzer,nota, duracion);
  delay(duracion);
  noTone(pinBuzzer);
  delay(duracion);
}

void setup() {


 lcd.begin(16, 2);
  lcd.setCursor(0,0);
 lcd.print("Ella Baila Sola ");
 lcd.setCursor(0,1);
 lcd.print("                ");

byte corchea[8] = {
  0b00100,
  
  0b00110,
  0b00101,
  0b00101,
  0b00100,
  0b01100,
  0b11100,
  0b01000

};

byte tilde_a[8] = {
  0b00001,
  0b00010,
  0b00000,
  0b01110,
  0b10010,
  0b10010,
  0b01111,
  0b00000
};

byte tilde_e[8] = {
  0b00001,
  0b00010,
  0b00000,
  0b01110,
  0b10001,
  0b11111,
  0b10000,
  0b01111
};

byte tilde_i[8] = {
  0b00001,
  0b00010,
  0b00000,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00000
};
byte tilde_o[8] = {
  0b00001,
  0b00010,
  0b00100,
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b01110
};

byte tilde_u[8] = {
  0b00001,
  0b00010,
  0b00100,
  0b00000,
  0b10001,
  0b10001,
  0b10001,
  0b01110
};




lcd.createChar(4, corchea);
lcd.createChar(5, tilde_a);
lcd.createChar(6, tilde_e);
lcd.createChar(7, tilde_i);
lcd.createChar(8, tilde_o);
lcd.createChar(9, tilde_u);


//
//lcd.setCursor(8, 0); lcd.write(byte(5)); 
//lcd.setCursor(8, 1); lcd.write(byte(7)); 
//lcd.setCursor(14, 1); lcd.write(byte(4)); 
}

void loop() {

HoySecumple();
TeFuiste();
QuisisteRenunciar();
YComoDuele();
Transicion();

MientrasPiensoEnti();
QuisieraEvitar();
HabermePermitido();
ParaPerderte();

Transicion();
YMeDueles();
ComoDueles();
delay(1500);
}

void HoySecumple(){
// Bemoles

textopan("Hoy se cumple  ","un mes          ");
  nota_sf(D2,c);
  nota( D2,c);
  nota(A_2,n);
  nota(A_2,n);
  nota(Fs2,n);
textopan("en que no me   ","ves...          ");
  nota_sf(D2,c);
  nota( D2,c);
  nota(A_2,n);
  nota(A_2,n);
  nota(Fs2,n+c);
}
void TeFuiste(){
  
textopan("Te fuiste nada ","mas             ");
  nota_sf(D2,c);
  nota( E2,n);
  nota(Fs2,c);
  nota(Fs2,c);
  nota( E2,c);
  nota(Fs2,n);
  }

void QuisisteRenunciar(){
  
textopan("quisiste       ","                ");
  nota_sf(D2,c);
  nota( E2,n);
  nota(Fs2,c);

textopan("renunciar a    ","quererme    :'( ");
  nota(Fs2,c);
  nota( E2,c);
  nota(Fs2,c);
  nota(Fs2,c);
  nota(A_2,c);
  nota(A_2,n);
  nota(Cs2,r);
  nota(Sil,2*c);
  
  }

  
void YComoDuele(){
  
textopan("Y como duele...","                ");


  nota(Cs2,c);
  nota(Fs2,n);
  nota(E2,n);
  nota(E2,n);
  nota(D2,n+c);

}

void Transicion(){
  
textopan("               ","            :(  ");


  nota(A_ ,b);
  nota(B_ ,b);
  nota(Cs,c);
}

//====================================================================================================

void MientrasPiensoEnti(){
// Bemoles

textopan("Mientras pienso","en ti           ");
  nota_sf(D2,c);
  nota( D2,c);
  nota(A_2,n);
  nota(A_2,n);
  nota(Fs2,n);
textopan("y en lo que    ","           perdi");
  nota_sf(D2,c);
  nota( D2,c);
  nota(A_2,n);
  nota(A_2,n);
  nota(Fs2,n+c);
}
void QuisieraEvitar(){
  
textopan("Quisiera evitar","                ");
  nota_sf(D2,c);
  nota( E2,n);
  nota(Fs2,c);
  nota(Fs2,c);
  nota( E2,c);
  nota(Fs2,n);
  }

void HabermePermitido(){
  
textopan("Haberme        ","                ");
  nota_sf(D2,c);
  nota( E2,n);
  nota(Fs2,c);

textopan("permitido      ","amarte      :'( ");
  nota(Fs2,c);
  nota( E2,c);
  nota(Fs2,c);
  nota(Fs2,c);
  nota(A_2,c);
  nota(A_2,n);
  nota(Cs2,r);
  nota(Sil,2*c);
  
  }

  
void ParaPerderte(){
  
textopan("Para perderte  ","             :( ");


  nota(Cs2,c);
  nota(Fs2,n);
  nota(E2,n);
  nota(E2,n);
  nota(D2,n+c);

}
void YMeDueles(){
  
textopan("Y me dueles... ","             :( ");
  nota(D2,c);
  nota(D2,c);
  nota_sf(E2,n);
  nota(Fs2,7*c);
  
  nota(E2,b);
  nota(D2,b);
  nota(Cs2,n+c+c+c);


  nota_sf(Fs2,c);    nota_sf(Cs2,c);
  nota_sf(Fs2,c);    nota_sf(Cs2,c);
  nota_sf(Fs2,c);    nota_sf(Cs2,c);
  nota_sf(Fs2,c);    nota_sf(A_2,c);

  
  }

void ComoDueles(){
  
textopan("Como dueles... ","            :'( ");
  nota(D2,c);
  nota(D2,c);
  nota(E2,n);
  nota(Fs2,7*c);
  
  nota(A_2,b);
  nota(D2,b);
  nota(Cs2,r);
  //nota(Cs_,b);
  
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
  
