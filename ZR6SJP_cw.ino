#include <MorseEnDecoder.h>
#include <LiquidCrystal_I2C.h>
#include <PS2Keyboard.h>
#include <avr/pgmspace.h>


const int DataPin = 8;
const int IRQpin =  3;
int rannum = 0;
const int speaker = 9;
int unit_delay = 300;
const byte morseInPin = 7;      
const byte morseOutPin = 13;

PS2Keyboard keyboard;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);
morseDecoder morseInput(morseInPin, MORSE_KEYER, MORSE_ACTIVE_LOW);
morseEncoder morseOutput(morseOutPin);


void setup() {
  Serial.begin(9600);
  delay(1000);
  keyboard.begin(DataPin, IRQpin);
  lcd.init();
  lcd.backlight();
  lcd.print("ZR6SJP CW Trainer");
  delay(1000);
  lcd.clear();
  lcd.home();
  morseInput.setspeed(10);
  morseOutput.setspeed(10);
 
  
}
void clear(){
  lcd.clear();
  lcd.home();
}


void loop() {
   morseInput.decode();
  morseOutput.encode();

  // SEND MORSE (OUTPUT)
  // Encode and send text received from the serial port (serial monitor)
  if (Serial.available() && morseOutput.available())
  {
    // Get character from serial and send as Morse code
    char sendMorse = Serial.read();
    morseOutput.write(sendMorse);
  }

  // RECEIVE MORSE (INPUT)
  // If a character is decoded from the input, write it to serial port
  if (morseInput.available())
  {
    char receivedMorse = morseInput.read();
    lcd.print(receivedMorse);
    
    // A little error checking    
    if (receivedMorse == '#') Serial.println("< ERROR:too many morse signals! >");
  }
  
  if (keyboard.available()) {

    char c = keyboard.read();
    lcd.print(c);
    if (c == 'a') {
      p();l();delay(300); clear();
    } else if (c == 'b') {
      l();p();p();p();delay(300); clear();
    } else if (c == 'c') {
      l();p();l();p();delay(300);clear();
    } else if (c == 'd') {
      l();p();p();delay(300);clear();
    } else if (c == 'e') {
      p();delay(300);clear();clear();
    } else if (c == 'f') {
      p();p();l();p();delay(300);clear();
    } else if (c == 'g') {
      l();l();p();delay(300);clear();
    } else if (c == 'h') {
      p();p();p();p();delay(300);clear();
    } else if (c == 'i') {
      p();p();delay(300);clear();
    } else if (c == 'j') {
      p();l();l();l();delay(300);clear();
    } else if (c == 'k') {
      l();p();l();delay(300);clear();
    } else if (c == 'l') {
      p();l();p();p();delay(300);clear();
    } else if (c == 'm') {
      l();l();delay(300);clear();
    } else if (c == 'n') {
      l();p();delay(300);clear();
    } else if (c == 'o') {
      l();l();l();delay(300);clear();
    } else if (c == 'p') {
      p();l();l();p();delay(300);clear();
    } else if (c == 'q') {
      l();l();p();l();;delay(300);clear();
    } else if (c == 'r') {
      p();l();p();delay(300);clear();
    } else if (c == 's') {
      p();p();p();delay(300);clear();
    } else if (c == 't') {
      l();delay(300);clear();
    } else if (c == 'u') {
      p();p();l();delay(300);clear();
    } else if (c == 'v') {
      p();p();p();l();delay(300);clear();
    } else if (c == 'w') {
      p();l();l();delay(300);clear();
    } else if (c == 'x') {
      l();p();p();l();delay(300);clear();
    } else if (c == 'y') {
      l();p();l();l();delay(300);clear();
    } else if (c == 'z') {
      l();l();p();p();delay(300);clear();
    } else if (c == '1') {
      p();l();l();l();l();delay(300);clear();
    } else if (c == '2') {
      p();p();l();l();l();delay(300);clear();
    } else if (c == '3') {
      p();p();p();l();l();delay(300);clear();
    } else if (c == '4') {
      p();p();p();p();l();delay(300);clear();
    } else if (c == '5') {
      p();p();p();p();p();delay(300);clear();
    } else if (c == '6') {
      l();p();p();p();p();delay(300);clear();
    } else if (c == '7') {
      l();l();p();p();p();delay(300);clear();
    } else if (c == '8') {
      l();l();l();p();p();delay(300);clear();
    } else if (c == '9') {
      l();l();l();l();p();delay(300);clear();
    } else if (c == '0') {
      l();l();l();l();l();delay(300);clear();
    } else if (c == ' ') {
      pausa();lcd.home();
    } else if (c == PS2_DELETE) {
        clear();
    } else if (c == PS2_F1) {
        randomnum();
        
        
    }else {
     tone(9, 300, 250); //error tone
     lcd.print("Error");
    }
    
  }

  
  if (rannum == 1){
    K(); delay(unit_delay);endtrans();
  }
  else if (rannum == 2){
    M();delay(unit_delay);endtrans();
  }
  else if (rannum == 3){
    R();delay(unit_delay);endtrans();
  }
  else if (rannum == 4){
    S();delay(unit_delay);endtrans();
  }
  else if (rannum == 5){
    U();delay(unit_delay);endtrans();
  }
  else if (rannum == 6){
    A();delay(unit_delay);endtrans();
  }
  else if (rannum == 7){
    P();delay(unit_delay);endtrans();
  }
  else if (rannum == 8){
    T();delay(unit_delay);endtrans();
  }
  else if (rannum == 9){
    L();delay(unit_delay);endtrans();
  }
  else if (rannum == 10){
    O();delay(unit_delay);endtrans();
  }
  else if (rannum == 11){
    W();delay(unit_delay);endtrans();
  }
  else if (rannum == 12){
    I();delay(unit_delay);endtrans();
  }
  else if (rannum == 13){
    fs();delay(unit_delay);endtrans();
  }
  else if (rannum == 14){
    N();delay(unit_delay);endtrans();
  }
  else if (rannum == 15){
    J();delay(unit_delay);endtrans();
  }
  else if (rannum == 16){
    E();delay(unit_delay);endtrans();
  }
  else if (rannum == 17){
    f();delay(unit_delay);endtrans();
  }
  else if (rannum == 18){
    zero();delay(unit_delay);endtrans();
  }
  else if (rannum == 19){
    Y();delay(unit_delay);endtrans();
  }
  else if (rannum == 20){
    V();delay(unit_delay);endtrans();
  }
  else if (rannum == 21){
    comma();delay(unit_delay);endtrans();
  }
  else if (rannum == 22){
    G();delay(unit_delay);endtrans();
  }
  else if (rannum == 23){
    five();delay(unit_delay);endtrans();
  }
  else if (rannum == 24){
    slash();delay(unit_delay);endtrans();
  }
  else if (rannum == 25){
    Q();delay(unit_delay);endtrans();
  }
  else if (rannum == 26){
    nine();delay(unit_delay);endtrans();
  }
  else if (rannum == 27){
    Z();delay(unit_delay);endtrans();
  }
  else if (rannum == 28){
    H();delay(unit_delay);endtrans();
  }
  else if (rannum == 29){
    three();delay(unit_delay);endtrans();
  }
  else if (rannum == 30){
    eight();delay(unit_delay);endtrans();
  }
  else if (rannum == 31){
    B();delay(unit_delay);endtrans();
  }
  else if (rannum == 32){
    qmark();delay(unit_delay);endtrans();
  }
  else if (rannum == 33){
    four();delay(unit_delay);endtrans();
  }
  else if (rannum == 34){
    two();delay(unit_delay);endtrans();
  }
  else if (rannum == 35){
    seven();delay(unit_delay);endtrans();
  }
  else if (rannum == 36){
    C();delay(unit_delay);endtrans();
  }
  else if (rannum == 37){
    one();delay(unit_delay);endtrans();
  }
  else if (rannum == 38){
    D(); delay(unit_delay);endtrans();
  }
  else if (rannum == 39){
    six();delay(unit_delay);endtrans();
  }
  else if (rannum == 40){
    X();delay(unit_delay); endtrans();
  }
  else{
    noTone(9);
  }
}


void endtrans(){
  noTone(9);
  rannum = 0;
}
void p(){            //dot
  tone(9, 800,100);
  delay(unit_delay*2.5);
  noTone(9);
  lcd.print(".");
  
}

void l(){            //dash
  
  tone(9, 800,300);
  delay(unit_delay*2.5);
  noTone(9);
  lcd.print("-");

}

void pausa(){         //pause between two letters
  delay(1750);
  lcd.print(" ");
}

void randomnum(){
  rannum = random(1,40);
 
 
}
char new_char;


void dot()
{
lcd.print(".");
tone(speaker,800,100);
delay(unit_delay);
}
void dash()
{
lcd.print("-");
tone(speaker,800,300);

}
void A()
{
dot();
delay(unit_delay);
dash();
delay(unit_delay);
}
void B()
{
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void C()
{
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
}
void D()
{
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void E()
{
dot();
delay(unit_delay);
}
void f()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
}
void G()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
}
void H()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void I()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void J()
{
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void K()
{
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
}
void L()
{
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void M()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void N()
{
dash();
delay(unit_delay);
dot();
delay(unit_delay);
}
void O()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void P()
{
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
}
void Q()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
}
void R()
{
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
}
void S()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void T()
{
dash();
delay(unit_delay);
}
void U()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
}
void V()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
}
void W()
{
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void X()
{
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
}
void Y()
{
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void Z()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void one()
{
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void two()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void three()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void four()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
}
void five()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void six()
{
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void seven()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void eight()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}
void nine()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
}
void zero()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}
void fs () {
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void comma (){
  dash();
  dash();
  dot();
  dot();
  dash();
  dash();
  
} 

void slash(){
  dash();
  dot();
  dot();
  dash();
  dot();
}

void qmark(){
  dot();
  dot();
  dash();
  dash();
  dot();
  dot();
  
}
