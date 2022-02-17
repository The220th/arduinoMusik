


// Кодирование нот: https://github.com/robsoncouto/arduino-songs
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262 // До
#define NOTE_CS4 277 // До-диез
#define NOTE_D4  294 // Ре
#define NOTE_DS4 311 // Ре-диез
#define NOTE_E4  330 // Ми
#define NOTE_F4  349 // Фа
#define NOTE_FS4 370 // Фа-диез
#define NOTE_G4  392 // Соль
#define NOTE_GS4 415 // Соль-диез
#define NOTE_A4  440 // Ля
#define NOTE_AS4 466 // Ля-диез
#define NOTE_B4  494 // Си
#define NOTE_C5  523 // До
#define NOTE_CS5 554 // До-диез
#define NOTE_D5  587 // Ре
#define NOTE_DS5 622 // Ре-диез
#define NOTE_E5  659 // Ми
#define NOTE_F5  698 // Фа
#define NOTE_FS5 740 // Фа-диез
#define NOTE_G5  784 // Соль
#define NOTE_GS5 831 // Соль-диез
#define NOTE_A5  880 // Ля
#define NOTE_AS5 932 // Ля-диез
#define NOTE_B5  988 // Си
#define NOTE_C6  1047 // До
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 1

// Тембр
int tempo=144; 

// Пин
int pinOut = 13;

// четные - ноты, нечетные - пауза
// Положительная:
// 4 - длительность 1/4
// 8 - длительность 1/8
// 16 - длительность 1/16 и т. д.
// Отрицательные - это для пауз:
// -4 - пауза 1/4
// -8 - пауза 1/8
// -16 - пауза 1/16
int melody[] = {
  NOTE_E5,4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4,4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4,-4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5,4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5,-4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5,-4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4,4,  NOTE_B4,8,  NOTE_C5,8,   NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5,4,  NOTE_A4,4,  NOTE_A4,4,   REST,4,

  NOTE_E5,4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4,4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4,-4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5,4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5,-4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5,-4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4,4,  NOTE_B4,8,  NOTE_C5,8,   NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5,4,  NOTE_A4,4,  NOTE_A4,4,   REST,4,

  NOTE_E5,2,  NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,2,   NOTE_A4,2,
  NOTE_GS4,2,  NOTE_B4,4,  REST,8, 
  NOTE_E5,2,   NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
  NOTE_GS5,2,
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notesNum = sizeof(melody)/sizeof(melody[0])/2; 


int wholenoteDur = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {pinMode(pinOut, OUTPUT);}

void playMusik()
{
  
    for (int thisNote = 0; thisNote < notesNum * 2; thisNote = thisNote + 2) {

      
      divider = melody[thisNote + 1];
      if (divider > 0)
      {
          noteDuration = (wholenoteDur) / divider;
      }
      else if (divider < 0)
      {
          noteDuration = (wholenoteDur) / abs(divider);
          noteDuration *= 1.5;
      }

      playNote(melody[thisNote], noteDuration*0.9);

      delay(noteDuration);
    }
}

void playNote(unsigned note, unsigned dur)
{
    unsigned durMicro = dur*1000;
    float fT = (1000000.0/(float)note); 
    unsigned T = (unsigned)(fT); // Весь пириод ноты в микросекундах
    unsigned hT = T/2;
    unsigned curDur = 0;
    do
    {
        digitalWrite(pinOut, HIGH);
        delayMicroseconds(hT);
        digitalWrite(pinOut, LOW);
        delayMicroseconds(hT);
        curDur += T;
    }while(curDur < durMicro);
}

void loop() {playMusik();}
