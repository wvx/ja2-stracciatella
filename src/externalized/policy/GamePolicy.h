#pragma once

#include <stdint.h>

#include <string>
#include <vector>

enum UIMode
{
  UI_Tactical,
  UI_Map
};

enum HotkeyModifier
{
  HKMOD_None,
  HKMOD_CTRL,
  HKMOD_SHIFT,
  HKMOD_ALT
};

#define gamepolicy(element) (GCM->getGamePolicy()->element)

class GamePolicy
{
public:
  /** Check if a hotkey is enabled. */
  virtual bool isHotkeyEnabled(UIMode mode, HotkeyModifier modifier, uint32_t key) const = 0;
  // this could be defaulted in C++11
  virtual ~GamePolicy() {}

  bool f_draw_item_shadow;              /**< Draw shadows from the inventory items. */

  int32_t ms_per_game_cycle;            /**< Milliseconds per game cycle. */

  int32_t starting_cash_easy;
  int32_t starting_cash_medium;
  int32_t starting_cash_hard;

  /* Battle */
  bool f_drop_everything;               /**< Enemy drop all equipment. */
  bool f_all_dropped_visible;           /**< All dropped equipment is visible right away. */

  bool multiple_interrupts;             // can interrupt more than once per turn

  int8_t enemy_weapon_minimal_status;   /**< Minimal status of the enemy weapon (0 - 100). */

  bool gui_extras;                      /* graphical user interface cosmetic mod */

  bool accurate_aim_circle;             // Aim circle size and colour corresponds to chance_to_hit, smaller is better.

  bool all_skilltraits_mode;            // Allow soldier to get every perk available
  bool all_skilltraits_just_ours;       // limit to player soldiers
  int8_t all_skilltraits_wisdom;        // Wisdom required to qualify. Above 100 disables
  int8_t all_skilltraits_level;         // Level required to qualify. Above 10 disables
  bool enemy_elite_all_traits;          // Elites from queen's army get all perks

  bool imp_load_saved_merc_by_nickname; // IMP merc is saved and can be loaded at IMP creation if has same nickname
  bool imp_load_keep_inventory;         // IMP merc gets inventory from last save game

  bool middle_mouse_look;               // Look cursor with middle mouse button
  bool can_enter_turnbased;             // 'd' can start turnbased if in real-time

  bool inventory_management_extras;     // 1.13 inventory management hotkeys, shift-f, etc.
  bool ime_detach_ammo;                 // hotkey detaches magazines from sector weapons
  bool ime_detach_attachments;          // hotkey removes removable attachments from sector weapons
  bool ime_refill_canteens;             // hotkey refill sector canteens, drinking does not deplete canteens out of combat
  bool vehicle_inventory;               // Vehicles have accessable inventories

  bool militia_use_sector_inventory;    // Militia are equiped from sector.inventory
  bool enemy_defenders_use_sector_inventory; // Enemies add equipment from sector.inventory, even from lockers

  bool militia_control;                 // 'q' hotkey to recruit militia/release/recruit best/nextbest
  int32_t militiamerc_salary;           // Daily salary of recruited milita merc

  bool perpetual_corpse_queen_crepitus; // Queen crepitus' corpse souvenir

  bool ironman_can_save_realtime;       // Save during real-time even when enemies present "clay-man"

  bool ai_better_aiming_choice;         // decide where to shoot depending on to-hit probability if random choice is being made
  bool ai_go_prone_more_often;          // especially when already facing the right direction
  int8_t threshold_cth_head;            // threshold AI always take head shots, increase game difficulty
  int8_t threshold_cth_legs;            // threshold AI switch to leg shots from torso
  int8_t enemy_elite_minimum_level;     // increase challenge: minimum experience level for enemy elite soldier
  int8_t enemy_elite_maximum_level;     // maximum experience level for enemy elite soldier

  bool pablo_wont_steal;                // Packages not stolen

  float critical_damage_head_multiplier;//Head damage multiplier. Vanilla 1.5
  float critical_damage_legs_multiplier;//Legs damage multiplier. Vanilla 0.5
  int8_t chance_to_hit_minimum;         //Minimum chance to hit (0 - chance_to_hit_maximum) vanilla 1
  int8_t chance_to_hit_maximum;         //Maximum chance to hit (chance_to_hit_minimum - 100) vanilla 99

  /* IMP */
  int8_t imp_attribute_max;             // IMP character attribute maximum 0 to 100, vanilla 85
  int8_t imp_attribute_min;             // IMP character attribute minimum 0 to imp_attribute_max, vanilla 35
  int32_t imp_attribute_bonus;          // IMP character attribute unallocated bonus points, vanilla 40
  int32_t imp_attribute_zero_bonus;     // IMP character attribute points given instead of imp_attribute_min, vanilla 15

  ////////////////////////////////////////////////////////////
  //
  ////////////////////////////////////////////////////////////
};
