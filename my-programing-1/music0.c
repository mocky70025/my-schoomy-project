

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double duration_beats(char code)
{
    switch (code) {
        case 'H': return 3.0;
        case 'h': return 2.0;
        case 'T': return 4.0 / 3.0;
        case 'Q': return 1.5;
        case 'q': return 1.0;
        case 't': return 2.0 / 3.0;
        case 'E': return 0.75;
        case 'e': return 0.5;
        case 'u': return 1.0 / 3.0;
        case 'S': return 0.375;
        case 's': return 0.25;
        case 'v': return 1.0 / 6.0;
        case 'W': return 4.0;
        case ' ': return 0.0;
        default: return 1.0;
    }
}

double ascii_to_frequency(char code)
{
    if (code == ' ' || code == '_' || code == '\0') {
        return 0.0;
    }
    const double base_freq = 261.625565;
    const double semitone = 1.05946309435931;
    return base_freq * pow(semitone, code - 52);
}

int main(void)
{
    const int sample_rate = 8000;
    const double amplitude = 0.35;

    int tempo = 120;                       
    char takasa[] =       "/36:;;;;;;;999999;?B==EDDB9886434;?B=@=@B9846_346;?B==EDDB9886434;?B=EDEGJGIJEE9JKLGG;LMNBBBBBBBBLLMNBBBBBBBBLLKG";
    char nagasa[] =       "ssssqQssqqquuuuuuQehQeQsshQsshtttQehhttthtttheeeeQehQeQsshQsshtttQehhtttQeWhQehhqqQehhqqeqqqsseqettteqqqsseqetttW";
    char articulation[] = "    SSSSSSSSSSSSS                                                                                                ";


    size_t note_count = strlen(takasa);

    for (size_t i = 0; i < note_count; ++i) {
        char pitch = takasa[i];
        char duration_code = nagasa[i];
        char art = articulation[i];

        if (pitch == ' ') {
            continue;
        }

        double beats = duration_beats(duration_code);
        double seconds = beats * 60.0 / tempo;
        int samples = (int)llround(seconds * sample_rate);
        if (samples <= 0) {
            continue;
        }

        double release_ratio = 0.1;
        if (art == 'S') {
            release_ratio = 0.4;
        }
        int release_samples = (int)llround(release_ratio * samples);
        if (release_samples > samples) {
            release_samples = samples;
        }
        int sustain_samples = samples - release_samples;

        double frequency = ascii_to_frequency(pitch);
        double phase = 0.0;
        double phase_increment = (frequency > 0.0) ? (2.0 * M_PI * frequency / sample_rate) : 0.0;

        for (int n = 0; n < sustain_samples; ++n) {
            double sample_value = 0.0;
            if (pitch == '_' || frequency == 0.0) {
                sample_value = 0.0;
            } else {
                sample_value = amplitude * sin(phase);
                phase += phase_increment;
            }
            int8_t pcm = (int8_t)(sample_value * 127.0);
            fputc((uint8_t)pcm, stdout);
        }

        for (int n = 0; n < release_samples; ++n) {
            double sample_value = 0.0;
            if (pitch == '_' || frequency == 0.0) {
                sample_value = 0.0;
            } else {
                double envelope = (release_samples > 0) ? (double)(release_samples - n) / release_samples : 0.0;
                sample_value = amplitude * envelope * sin(phase);
                phase += phase_increment;
            }
            int8_t pcm = (int8_t)(sample_value * 127.0);
            fputc((uint8_t)pcm, stdout);
        }
    }

    fflush(stdout);
    return 0;
}
/* 
gcc music0.c -lm -o music0       
./music0 | sox -t raw -r 8000 -b 8 -e signed-integer -c 1 - music0.wav
afplay music0.wav     
*/