#pragma once

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

#define SPLASH_STATE_SHOW_TIME 2.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "sky.png"
#define GAME_BACKGROUND_FILEPATH "sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "sky.png"

#define GAME_TITLE_FILEPATH "title.png"
#define PLAY_BUTTON_FILEPATH "PlayButton.png"

#define PIPE_UP_FILEPATH "PipeUp.png"
#define PIPE_DOWN_FILEPATH "PipeDown.png"
   
#define LAND_FILEPATH "Land.png"

#define VIRUS_FRAME_1_FILEPATH "virus_01.png"
#define VIRUS_FRAME_2_FILEPATH "virus_02.png"
#define VIRUS_FRAME_3_FILEPATH "virus_03.png"
#define VIRUS_FRAME_4_FILEPATH "virus_04.png"

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FRECUENCY 0.5f
// #define PIPE_SPAWN_FRECUENCY 2.0f

#define VIRUS_ANIMATION_DURATION 0.7f  // Variar para lograr una mejor animation

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