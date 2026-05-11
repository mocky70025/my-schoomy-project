#include "mml_lib.h"


int main(void)
{
    char mml[] = "T120 q7.5 o3 G16 B16 o4 D16 F#16 q5 G4    G4. G16 G16 G4 G4 G4 F12 F12 F12 F12 F12  F12 q7.5    G4.   B8 o5 D2 o4    A4. A8 o5 F4. E16 E16 D2 o4 F4. E16 E16 D2 C6 o3 B6 o4 C6 G4. B8 o5 D2 o4 A2 o5 C6 o4 A6 o5 C6 D2 o4 F6 E6 C6 D2 r8 o3 B8 o4 C8 D8 G4. B8 o5 D2 o4 A4. A8 o5 F4. E16 E16 D2 o4 F4. E16 E16 D2 C6 o3 B6 o4 C6 G4. B8 o5 D2 o4 A2 o5 F6 E6 F6 G4. A#8 G1 A2 A#4. F8 F2 o4 F2 o5 A#4 B4 o6 C4. o5 G8 G2 o4 G2 o6 C4 C#4 D8 o5 D4 D4 D4 D16 D16 D8 D4 D8 o6 C6 C6 C#6 D8 o5 D4 D4 D4 D16 D16 D8 D4 D8 o6 C6 C6 o5 B6 G1";
    char mml1[] ="T120 V5 q7.5 o3 G16 B16 o4 D16 F#16 q5 G4 o3 B4. B16 B16 B4 B4 B4 A12 A12 A12 A12 A12 A#12 q7.5 o3 G4 o2 G4. o3 D8 G8 o2 G8 o3     F4 o2 F4 o3 C4 o2 F4 o3 G4 o2 G4 o3 F4 o2 F4 o3 G4 o2 G4 o2  o3  o2  o3 E6 D6 E6 G4 o2 G4. o3 G8 D8 o2 G8 o3 F4 o2 F4 o3 C4 o2 F4 o3 G4 o2 G4 o3 C6 C6 E6 o3 G4 o2 G4 o3 D2 G4 o2 G4. o3 G8 D8 o2 G8 o3 F4 o2 F4 o3 C4 o2 F4 o3 G4 o2 G4 o3 F4 o2 F4 o3 G4 o2 G4 o3 E6 D6 E6 G4 o2 G4. o3 G8 D8 o2 G8 o3 F4 o2 F4 o3 C4 o2 F4 o3 G4 o2 G4. G8 G8 G8 A8 A8 A8 A8 A8 A8 A8 A8 ";
   
    mml_to_wav(mml, "mml.wav");
    mml_to_wav(mml1, "mml1.wav");
    system("sox -m mml.wav mml1.wav mml_waon.wav");
    system("sox mml_waon.wav -d");
    return 0;
}



