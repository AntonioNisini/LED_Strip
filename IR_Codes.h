
// ----------------------------------------------

#ifdef CAR_MP3

#define KEY_CH_MINUS          0xFFA25D  // CH-
#define KEY_CH_PLUS           0xFFE21D  // CH+

#define KEY_SKIP_BACK         0xFF22DD  // |<<
#define KEY_SKIP_FORWARD      0xFF02FD  // >>|
#define KEY_PLAY_PAUSE        0xFFC23D  // |>|| 

#define KEY_VOL_DOWN          0xFFE01F  // -
#define KEY_VOL_UP            0xFFA857  // +
#define KEY_EQ                0xFF906F  // EQ

#define KEY_DIGIT_0           0xFF6897  // 0
#define KEY_CHAN_FORWARD_100  0xFF9867  // 100+
#define KEY_CHAN_FORWARD_200  0xFFB04F  // 200+ 

#define KEY_DIGIT_1           0xFF30CF  // 1       
#define KEY_DIGIT_2           0xFF18E7  // 2     
#define KEY_DIGIT_3           0xFF7A85  // 3

#define KEY_DIGIT_4           0xFF10EF  // 4 
#define KEY_DIGIT_5           0xFF38C7  // 5 
#define KEY_DIGIT_6           0xFF5AA5  // 6

#define KEY_DIGIT_7           0xFF42BD  // 7
#define KEY_DIGIT_8           0xFF4AB5  // 8
#define KEY_DIGIT_9           0xFF52AD  // 9  



// Application specific codes
#define KEY_SHRINK             0xFFA25D  // CH-
#define KEY_LED_COUNT          0xFFA25D  // CH-
#define KEY_ALL_LEDS           0xFF629D  // CH
#define KEY_ENLARGE            0xFFE21D  // CH+

#define KEY_MOVE_LEFT          0xFF22DD  // |<<
#define KEY_CENTER             0xFF02FD  // >>|
#define KEY_MOVE_RIGHT         0xFFC23D  // |>|| 

#define KEY_HUE_LEFT           0xFFE01F  // -
#define KEY_LESS_LEDS          0xFFE01F  // -
#define KEY_PREVIOUS_ANIMATION 0xFFE01F  // -
#define KEY_FULL_COLOR         0xFFA857  // +
#define KEY_MORE_LEDS          0xFFA857  // +
#define KEY_NEXT_ANIMATION     0xFFA857  // +
#define KEY_HUE_RIGHT          0xFF906F  // EQ
#define KEY_EXIT_SETTING       0xFF906F  // EQ
#define KEY_EXIT_DYNAMIC       0xFF906F  // EQ

#define KEY_DESATURATE         0xFF6897  // 0
#define KEY_WHITE              0xFF9867  // 100+
#define KEY_SATURATE           0xFFB04F  // 200+ 

#define KEY_BRIGHTER           0xFF30CF  // 1        
#define KEY_OFF                0xFF18E7  // 2      
#define KEY_DARKER             0xFF7A85  // 3

#define KEY_RED                0xFF10EF  // 4 
#define KEY_GREEN              0xFF38C7  // 5 
#define KEY_BLUE               0xFF5AA5  // 6

#define KEY_YELLOW             0xFF42BD  // 7
#define KEY_CYAN               0xFF4AB5  // 8
#define KEY_MAGENTA            0xFF52AD  // 9  

#endif
// ----------------------------------------------

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
#define KEY_SLOW_DOWN          0xFFE817  // C01
#define KEY_CENTER             0xFF48B7  // C02
#define KEY_MOVE_RIGHT         0xFF6897  // C03
#define KEY_SPEED_UP           0xFF6897  // C03
#define KEY_EXIT_SETTING       0xFFB24D  // FLSH
// Riga 4
#define KEY_HUE_LEFT           0xFF02FD  // C04
#define KEY_CYAN               0xFF32CD  // C05
#define KEY_HUE_RIGHT          0xFF20DF  // C06
#define KEY_MIXED              0xFF00FF  // STROBE
#define KEY_ALL_LEDS           0xFF00FF  // STROBE
// Riga 5
#define KEY_DESATURATE         0xFF50AF  // C07
#define KEY_FULL_COLOR         0xFF7887  // C08
#define KEY_SATURATE           0xFF708F  // C09
#define KEY_FADE               0xFF58A7  // FADE
// Riga 6
#define KEY_YELLOW             0xFF38C7  // C10
#define KEY_DARKER             0xFF28D7  // C11
#define KEY_MAGENTA            0xFFF00F  // C12
#define KEY_BRIGHTER           0xFF30CF  // SMOOTH

#endif
// ----------------------------------------------

       
#define KEY_REPEAT            0xFFFFFFFF 


// FUNCTIONS
#define DIRECT_FUNCTION    0
#define SET_CHANNEL        1

// ----------------------------------------------


#ifdef SCHAUB_LORENZ


#define KEY_DIGIT_1           0xFF32CD  // 1       
#define KEY_DIGIT_2           0xFF708F  // 2     
#define KEY_DIGIT_3           0xFFB24D  // 3
#define KEY_USB               0xFFF00F  // USB

#define KEY_DIGIT_4           0xFFF20D  // 4 
#define KEY_DIGIT_5           0xFF728D  // 5 
#define KEY_DIGIT_6           0xFFD02F  // 6
#define KEY_SUBTITLES         0xFFD22D  // SUB-T

#define KEY_DIGIT_7           0xFF52AD  // 7
#define KEY_DIGIT_8           0xFF12ED  // 8
#define KEY_DIGIT_9           0xFF50AF  // 9  
#define KEY_AUDIO             0xFF926D  // AUDIO

#define KEY_DIGIT_0           0xFF32CD  // 0       
#define KEY_GAME              0xFF30CF  // GAME
#define KEY_TEXT              0xFF10EF  // TEXT
#define KEY_TV_RADIO          0xFF906F  // TV/RADIO

#define KEY_MENU              0xFF22DD  // MENU
#define KEY_EXIT_RECALL       0xFFA05F  // EXIT/RECALL

#define KEY_CH_PLUS           0xFF629D  // CH+
#define KEY_CH_MINUS          0xFF6897  // CH-
#define KEY_VOL_MINUS         0xFFE21D  // VOL-
#define KEY_VOL_PLUS          0xFFA857  // VOL+
#define KEY_CENTER            0xFFAA55  // CENTER

#define KEY_FAVORITE          0xFFD827  // FAVORITE
#define KEY_NONAME            0xFFE01F  // NONAME
#define KEY_INFO              0xFF609F  // INFO
#define KEY_MUTE              0xFF18E7  // MUTE

#define KEY_VIEW_REC          0xFF5AA5  // VIEW REC
#define KEY_TIMER             0xFF9867  // TIMER

#define KEY_PLAY              0xFFC837  // PLAY
#define KEY_PAUSE             0xFF4887  // PAUSE
#define KEY_REC_STOP          0xFF827D  // REC/STOP
#define KEY_ZOOM              0xFF807F  // ZOOM

#define KEY_PREV              0xFF0AF5  // PREV
#define KEY_NEXT              0xFFCA35  // NEXT
#define KEY_REV               0xFF8A75  // REV
#define KEY_FWD               0xFF8877  // FWD

#define KEY_RED               0xFF2AD5  // RED
#define KEY_GREEN             0xFFEA15  // GREEN
#define KEY_YELLOW            0xFF4AB5  // YELLOW
#define KEY_BLUE              0xFF08F7  // BLUE

#endif
