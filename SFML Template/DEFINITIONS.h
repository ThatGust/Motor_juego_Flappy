#pragma once

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

#define SPLASH_STATE_SHOW_TIME 2.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "res/img/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "res/img/sky1.png"
#define GAME_BACKGROUND_FILEPATH "res/img/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "res/img/sky.png"
#define GAME_TWO_BACKGROUND_FILEPATH "res/img/skyTwo.png"

#define GAME_TITLE_FILEPATH "res/img/title.png"
#define PLAY_BUTTON_FILEPATH "res/img/PlayButton.png"
#define PLAY_BUTTON_TWO_FILEPATH "res/img/PlayButtonTwo.png"

#define PIPE_UP_FILEPATH "res/img/PipeUp.png"
#define PIPE_DOWN_FILEPATH "res/img/PipeDown.png"
#define PIPE_UP_TWO_FILEPATH "res/img/PipeUpTwo.png"
#define PIPE_DOWN_TWO_FILEPATH "res/img/PipeDownTwo.png"

#define SCORING_PIPE_FILEPATH "res/img/InvisibleScoringPipe.png"


#define LAND_FILEPATH "res/img/Land.png"
//#define LAND_FILEPATH "res/img/land_of_tutorial.png"

#define VIRUS_FRAME_1_FILEPATH "res/img/virus_01.png"
#define VIRUS_FRAME_2_FILEPATH "res/img/virus_02.png"
#define VIRUS_FRAME_3_FILEPATH "res/img/virus_03.png"
#define VIRUS_FRAME_4_FILEPATH "res/img/virus_04.png"


#define FLAPPY_FONT_FILEPATH "fonts/FlappyFont.ttf"

#define GAME_OVER_TITLE_FILEPATH "res/img/Game-Over-Title.png"

#define GAME_OVER_BODY_FILEPATH "res/img/Game-Over-Body.png"



#define HIT_SOUND_FILEPATH "Audio/Hit.wav"
#define POINT_SOUND_FILEPATH "Audio/Point.wav"
#define WING_SOUND_FILEPATH "Audio/Wing.wav"





#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_TWO_MOVEMENT_SPEED 600.0f
#define PIPE_SPAWN_FRECUENCY 2.5f       // A menor valor, pipes aparecen más juntos
#define PIPE_TWO_SPAWN_FRECUENCY 0.50f   

#define VIRUS_ANIMATION_DURATION 0.7f  // Variar para lograr una mejor animation del virus

#define VIRUS_STATE_STILL 1
#define VIRUS_STATE_FALLING 2
#define VIRUS_STATE_FLAYING 3

#define GRAVITY 350.0f

#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f

#define ROTATION_SPEED 100.0f

enum GameStates
{
    eReady,
    ePlaying,
    eGameOver
};


#define FLASH_SPEED 1500.0f

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f 