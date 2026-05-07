// 基礎プログラミングII 第3回 Scrummyプロジェクト
#include <SchooMyUtilities.h>
SchooMyUtilities scmUtils = SchooMyUtilities();

void setup() { Serial.begin(9600); }

void loop() { Serial.println(analogRead(A1)); }
