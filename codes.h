// 3x7 Remote
// Riga 1
#define KEY_CH_PREV            0xFFA25D  // CH-
#define KEY_CHANNEL            0xFF629D  // CH
#define KEY_CH_NEXT            0xFFE21D  // CH+
// Riga 2
#define KEY_BWD                0xFF22DD  // |<<
#define KEY_FWD                0xFF02FD  // >>|
#define KEY_PLAY_STOP          0xFFC23D  // |>|| 
// Riga 3
#define KEY_PLUS               0xFFE01F  // -
#define KEY_MINUS              0xFFA857  // +
#define KEY_EQUAL              0xFF906F  // EQ
// Riga 4
#define KEY_ZERO               0xFF6897  // 0
#define KEY_ONE_UNDRED         0xFF9867  // 100+
#define KEY_TWO_UNDRED         0xFFB04F  // 200+ 
// Riga 5,6,7
#define KEY_ONE                0xFF30CF  // 1        
#define KEY_TWO                0xFF18E7  // 2      
#define KEY_THREE              0xFF7A85  // 3
#define KEY_FOUR               0xFF10EF  // 4 
#define KEY_FIVE               0xFF38C7  // 5 
#define KEY_SIX                0xFF5AA5  // 6
#define KEY_SEVEN              0xFF42BD  // 7
#define KEY_EIGHT              0xFF4AB5  // 8
#define KEY_NINE               0xFF52AD  // 9  

/*
// 4x6 Remote
// Riga 1
#define KEY_LUM_HIGH           0xFF906F  // ^
#define KEY_LUM_LOW            0xFFB847  // v
#define KEY_LUM_ON             0xFFF807  // OFF
#define KEY_LUM_OFF            0xFFB04F  // ON
// Riga 2
#define KEY_RED                0xFF9867  // RED
#define KEY_GREEN              0xFFD827  // GREEN
#define KEY_BLUE               0xFF8877  // BLUE
#define KEY_WHITE              0xFFA857  // WHITE
// Riga 3
#define KEY_COL01              0xFFE817  // C01
#define KEY_COL02              0xFF48B7  // C02
#define KEY_COL03              0xFF6897  // C03
#define KEY_FLASH              0xFFB24D  // FLSH
// Riga 4
#define KEY_COL04              0xFF02FD  // C04
#define KEY_COL05              0xFF32CD  // C05
#define KEY_COL06              0xFF20DF  // C06
#define KEY_STROBE             0xFF00FF  // STROBE
// Riga 5
#define KEY_COL07              0xFF50AF  // C07
#define KEY_COL08              0xFF7887  // C08
#define KEY_COL09              0xFF708F  // C09
#define KEY_FADE               0xFF58A7  // FADE
// Riga 6
#define KEY_COL10              0xFF38C7  // C10
#define KEY_COL11              0xFF28D7  // C11
#define KEY_COL12              0xFFF00F  // C12
#define KEY_SMOOTH             0xFF30CF  // SMOOTH
*/

#ifdef REMOTE_4x6
// 4x6 Remote
// Riga 1
#define KEY_PREVIOUS_ANIMATION 0xFF906F  // ^
#define KEY_SHRINK             0xFF906F  // ^
#define KEY_LESS_LEDS          0xFF906F  // ^
#define KEY_NEXT_ANIMATION     0xFFB847  // v
#define KEY_ENLARGE            0xFFB847  // v
#define KEY_MORE_LEDS          0xFFB847  // v
#define KEY_EXIT_DYNAMIC       0xFFF807  // OFF
#define KEY_OFF                0xFFF807  // OFF
#define KEY_ON                 0xFFB04F  // ON
#define KEY_ENTER_DYNAMIC      0xFFB04F  // ON
// Riga 2
#define KEY_RED                0xFF9867  // RED
#define KEY_GREEN              0xFFD827  // GREEN
#define KEY_BLUE               0xFF8877  // BLUE
#define KEY_WHITE              0xFFA857  // WHITE
// Riga 3
#define KEY_MOVE_LEFT          0xFFE817  // C01
#define KEY_CENTER             0xFF48B7  // C02
#define KEY_MOVE_RIGHT         0xFF6897  // C03
#define KEY_EXIT_SETTING       0xFFB24D  // FLSH
// Riga 4
#define KEY_HUE_LEFT           0xFF02FD  // C04
#define KEY_CYAN               0xFF32CD  // C05
#define KEY_HUE_RIGHT          0xFF20DF  // C06
#define KEY_ALL_LEDS           0xFF00FF  // STROBE
// Riga 5
#define KEY_DESATURATE         0xFF50AF  // C07
#define KEY_FULL_COLOR         0xFF7887  // C08
#define KEY_SATURATE           0xFF708F  // C09
#define KEY_FADE               0xFF58A7  // FADE
// Riga 6
#define KEY_YELLOW             0xFF38C7  // C10
#define KEY_BRIGHTER           0xFF28D7  // C11
#define KEY_MAGENTA            0xFFF00F  // C12
#define KEY_DARKER             0xFF30CF  // SMOOTH

#endif


       
#define KEY_REPEAT            0xFFFFFFFF 
