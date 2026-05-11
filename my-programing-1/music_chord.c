#include <stdio.h>
#include <math.h>

// 2つの音（サンプル）をミキシングする関数
char mix(char melody_sound, char bass_sound) {
    int mixed = (int)(melody_sound * 0.6) + (int)(bass_sound * 0.6);
    if (mixed > 127) mixed = 127;
    if (mixed < -128) mixed = -128;
    return (char)mixed;
}

int main(void)
{
    // --- テンポ設定 (♩ = 80) ---
    int tempo_base = 12000;

    // --- 右手 (メロディ / ト音記号) ---
    // (調号: シ♭, ミ♭)
    char melody_takasa[] = 
        // --- 序奏 (Intro) ---
        "b b b_ d_ b_ " // 1-4
        "Z_ Y_ W_ _ " // 5-8
        "b b b_ d_ b_ " // 9-12
        "Z_ W_ Y_ _ " // 13-16
        // --- Aメロ (Main Theme) ---
        "PRSU W_Y_ Z_ _ " // 17-20
        "Y_Z_ W_P_ U_ _ " // 21-24
        "UW YW S_ _ " // 25-26
        "PRSU W_Y_ Z_ _ " // 27-30
        "Y_Z_ W_b_ Y_ _ " // 31-34
        "YZWY P_ _ " // 35-36
        // --- Bメロ (Bridge) ---
        "b_h_ j_h_ f_d_ h_ _ " // 37-40
        "d_b_ Z_Y_ WYZW U_ _ " // 41-44
        // --- Aメロ (Reprise) ---
        "PRSU W_Y_ Z_ _ " // 45-48
        "Y_Z_ W_b_ Y_ _ " // 49-52
        "YZWY P_ _ " // 53-54
        // --- Coda (Ending) ---
        "b_b_ b_db " // 55-56
        "Z_Y_ W_W_ " // 57-58
        "P_R_ U_W_ " // 59-60
        "Y_Z_ b_ _ _ _ " // 61-64
        ;

    // (音の長さ: 1=全, 2=2分, 4=4分, 8=8分)
    char melody_nagasa[] = 
        // --- 序奏 (Intro) ---
        "4 4 2 2 2 " // 1-4
        "2 2 1 " // 5-8
        "4 4 2 2 2 " // 9-12
        "2 2 1 " // 13-16
        // --- Aメロ (Main Theme) ---
        "4 4 4 4 2 2 1 " // 17-20
        "2 2 2 2 1 " // 21-24
        "4 4 4 4 2 2 " // 25-26
        "4 4 4 4 2 2 1 " // 27-30
        "2 2 2 2 1 " // 31-34
        "4 4 4 4 1 " // 35-36
        // --- Bメロ (Bridge) ---
        "2 2 2 2 2 2 1 " // 37-40
        "2 2 2 2 4 4 4 4 1 " // 41-44
        // --- Aメロ (Reprise) ---
        "4 4 4 4 2 2 1 " // 45-48
        "2 2 2 2 1 " // 49-52
        "4 4 4 4 1 " // 53-54
        // --- Coda (Ending) ---
        "2 2 4 4 2 " // 55-56
        "2 2 2 2 " // 57-58
        "2 2 2 2 " // 59-60
        "2 2 1 1 " // 61-64
        ;

    // --- 左手 (ベース / ヘ音記号) ---
    char bass_takasa[] = 
        // --- 序奏 (Intro) ---
        "U_ _ R_ _ N_ _ K_ _ " // 1-8
        "U_ _ R_ _ N_ _ P_ _ " // 9-16
        // --- Aメロ (Main Theme) ---
        "PRSU K_S_ P_ _ " // 17-20
        "U_N_ K_S_ P_ _ " // 21-24
        "U_ _ S_ _ " // 25-26
        "PRSU K_S_ P_ _ " // 27-30
        "U_N_ K_P_ R_ _ " // 31-34
        "N_ _ P_ _ " // 35-36
        // --- Bメロ (Bridge) ---
        "P_ _ U_ _ S_ _ U_ _ " // 37-40
        "R_ _ N_ _ K_ _ P_ _ " // 41-44
        // --- Aメロ (Reprise) ---
        "PRSU K_S_ P_ _ " // 45-48
        "U_N_ K_P_ R_ _ " // 49-52
        "N_ _ P_ _ " // 53-54
        // --- Coda (Ending) ---
        "U_ _ P_ _ " // 55-56
        "N_ _ K_ _ " // 57-58
        "S_ _ U_ _ " // 59-60
        "N_ _ U_ _ U_ _ " // 61-64 (U = シ♭)
        ;

    char bass_nagasa[] = 
        // --- 序奏 (Intro) ---
        "1 1 1 1 " // 1-8
        "1 1 1 1 " // 9-16
        // --- Aメロ (Main Theme) ---
        "4 4 4 4 2 2 1 " // 17-20
        "2 2 2 2 1 " // 21-24
        "1 1 " // 25-26
        "4 4 4 4 2 2 1 " // 27-30
        "2 2 2 2 1 " // 31-34
        "1 1 " // 35-36
        // --- Bメロ (Bridge) ---
        "1 1 1 1 " // 37-40
        "1 1 1 1 " // 41-44
        // --- Aメロ (Reprise) ---
        "4 4 4 4 2 2 1 " // 45-48
        "2 2 2 2 1 " // 49-52
        "1 1 " // 53-54
        // --- Coda (Ending) ---
        "1 1 " // 55-56
        "1 1 " // 57-58
        "1 1 " // 59-60
        "1 1 1 " // 61-64
        ;


    // --- 再生処理 (バグ修正済み・ポリリズム対応) ---
    
    int melody_idx = 0;
    int bass_idx = 0;
    
    int melody_remaining = 0;
    int bass_remaining = 0;

    char m_taka = '_'; // 最初は無音
    char b_taka = '_'; // 最初は無音

    // メロディのデータがなくなるまでループ
    while (melody_takasa[melody_idx] || melody_remaining > 0) {

        // --- メロディの音符を読み込む ---
        if (melody_remaining == 0) {
            // 空白を飛ばす
            while (melody_takasa[melody_idx] == ' ') { melody_idx++; }
            // 配列の最後に到達したらループを抜ける
            if (!melody_takasa[melody_idx]) break; 
            
            m_taka = melody_takasa[melody_idx];
            char m_naga = melody_nagasa[melody_idx];
            melody_remaining = tempo_base / (m_naga - '0');
            melody_idx++;
        }

        // --- ベースの音符を読み込む ---
        if (bass_remaining == 0) {
            // 空白を飛ばす
            while (bass_takasa[bass_idx] == ' ') { bass_idx++; }
            
            if (!bass_takasa[bass_idx]) {
                // ベースが先に終わったら、メロディの長さに合わせて無音を鳴らす
                b_taka = '_';
                bass_remaining = melody_remaining; // ズレ防止
            } else {
                b_taka = bass_takasa[bass_idx];
                char b_naga = bass_nagasa[bass_idx];
                bass_remaining = tempo_base / (b_naga - '0');
                bass_idx++;
            }
        }

        // --- 再生する長さを決定 ---
        // メロディとベースの「残り時間」のうち、短い方を採用
        int n = (melody_remaining < bass_remaining) ? melody_remaining : bass_remaining;
        if (n <= 0) n = 1; // 念のため

        // --- 周波数の計算 ---
        int t = 1;
        double x_melody = pow(1.05946309435931, m_taka - 52);
        double x_bass = pow(1.05946309435931, b_taka - 52);

        // --- 音の再生ループ ---
        for (int i = 0; i < n; i++, t++) {
            char y_melody = (m_taka == '_') ? 0 : (t * x_melody);
            char y_bass = (b_taka == '_') ? 0 : (t * x_bass);
            printf("%c", mix(y_melody, y_bass));
        }

        // --- 再生した分の時間を、各パートの「残り時間」から引く ---
        melody_remaining -= n;
        bass_remaining -= n;
    }
}

//実行手順
//gcc music_chord.c -lm -o music_chord
//./music_chord | sox -t raw -r 8000 -b 8 -e signed-integer -c 1 - music_chord.wav
//afplay music_chord.wav