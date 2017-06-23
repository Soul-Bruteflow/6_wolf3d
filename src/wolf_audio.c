#include "wolf3d.h"

void	wolf_audio_init(t_wolf *w)
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	w->step_1 = Mix_LoadWAV("./resources/sound/pl_metal1.wav");
	w->step_2 = Mix_LoadWAV("./resources/sound/pl_metal2.wav");
	w->theme_1 = Mix_LoadMUS("./resources/sound/theme.wav");
	w->step = 0;
	w->step_counter = 0;
	w->music_pause_flag = 0;
	Mix_Volume(1,MIX_MAX_VOLUME/20);
	Mix_Volume(2,MIX_MAX_VOLUME/20);
	Mix_VolumeMusic(5);
}
