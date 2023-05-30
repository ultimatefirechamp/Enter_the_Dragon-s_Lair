#pragma once
#include "SDL.h"
#include "SDL_mixer.h"

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void cutscene_music();
	void intro_music();
	void stage_music();
	void ending_music();
	void gameover_music();
	void phase_transition_sound();
	void move_sound();
	void btn_click_sound();
	void btn_hold_sound();
	void player_atk_sound();
	void player_dmg_sound();
	void player_die_sound();
	void monster_atk_sound();
	void monster_dmg_sound();
	void monster_die_sound();
	void charge_sound();
	void skill1_sound();
	void skill2_sound();
	void skill3_sound();
private:
	Mix_Music* cutscene_bgm;
	Mix_Music* intro_bgm;
	Mix_Music* stage_bgm;
	Mix_Music* ending_bgm;
	Mix_Music* gameover_bgm;
	Mix_Chunk* phase_transition_se;
	Mix_Chunk* btn_click_se;
	Mix_Chunk* btn_hold_se;
	Mix_Chunk* move_se;
	Mix_Chunk* player_atk_se;
	Mix_Chunk* player_dmg_se;
	Mix_Chunk* player_die_se;
	Mix_Chunk* monster_atk_se;
	Mix_Chunk* monster_dmg_se;
	Mix_Chunk* monster_die_se;
	Mix_Chunk* charge_se;
	Mix_Chunk* skill1_se;
	Mix_Chunk* skill2_se;
	Mix_Chunk* skill3_se;
};