int note_c=523;
int note_h=494;
int note_a=440;
int note_g=392;
int note_f=349;
int note_e=330;
int note_d=293;
int note_C=262;


const int tempo = 1024;
int ton_dauer[] = {tempo /*ganzton*/, tempo/2 /*halbton*/, tempo/4 /*viertelton*/ };


void play_tone(int note, int dauer)
{
  tone(11, note, dauer);
  delay(dauer);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Alarm!!!!!");

  play_tone(note_C, ton_dauer[2]);
  play_tone(note_d, ton_dauer[2]);
  play_tone(note_e, ton_dauer[2]);
  play_tone(note_f, ton_dauer[2]);
  play_tone(note_g, ton_dauer[1]);
  play_tone(note_g, ton_dauer[1]);

  play_tone(note_a, ton_dauer[2]);
  play_tone(note_a, ton_dauer[2]);
  play_tone(note_a, ton_dauer[2]);
  play_tone(note_a, ton_dauer[2]);
  play_tone(note_g, ton_dauer[0]);

  play_tone(note_a, ton_dauer[2]);
  play_tone(note_a, ton_dauer[2]);
  play_tone(note_a, ton_dauer[2]);
  play_tone(note_a, ton_dauer[2]);
  play_tone(note_g, ton_dauer[0]);

  play_tone(note_f, ton_dauer[2]);
  play_tone(note_f, ton_dauer[2]);
  play_tone(note_f, ton_dauer[2]);
  play_tone(note_f, ton_dauer[2]);
  play_tone(note_e, ton_dauer[1]);
  play_tone(note_e, ton_dauer[1]);

  play_tone(note_d, ton_dauer[2]);
  play_tone(note_d, ton_dauer[2]);
  play_tone(note_d, ton_dauer[2]);
  play_tone(note_d, ton_dauer[2]);
  play_tone(note_C, ton_dauer[0]);
}

void loop()
{
}
