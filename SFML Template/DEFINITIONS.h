#pragma once

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

#define SPLASH_STATE_SHOW_TIME 2.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "res/img/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "res/img/sky.png"
#define GAME_BACKGROUND_FILEPATH "res/img/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "res/img/sky.png"

#define GAME_TITLE_FILEPATH "res/img/title.png"
#define PLAY_BUTTON_FILEPATH "res/img/PlayButton.png"

#define PIPE_UP_FILEPATH "res/img/PipeUp.png"
#define PIPE_DOWN_FILEPATH "res/img/PipeDown.png"
   
#define LAND_FILEPATH "res/img/Land.png"
// #define LAND_FILEPATH "res/img/land_of_tutorial.png"

#define VIRUS_FRAME_1_FILEPATH "res/img/virus_01.png"
#define VIRUS_FRAME_2_FILEPATH "res/img/virus_02.png"
#define VIRUS_FRAME_3_FILEPATH "res/img/virus_03.png"
#define VIRUS_FRAME_4_FILEPATH "res/img/virus_04.png"

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FRECUENCY 2.5f       // A menor valor, pipes aparecen más juntos

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