// ZuzabrGames All rights reserved 2024


#include "ColorDayGameplayTags.h"

namespace ColorDayGameplayTags
{
	/**Input Tags**/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Crouch, "InputTag.Crouch");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Sprint, "InputTag.Sprint");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Equip, "InputTag.Equip");

	/**Input Weapon Tags**/	
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Unequip, "InputTag.Unequip");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Weapon_Fire, "InputTag.Weapon.Fire");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_SwitchAmmo, "InputTag.Weapon.SwitchAmmo");

	/**Player Ability**/
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Gun, "Player.Ability.Equip.Gun");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Gun, "Player.Ability.Unequip.Gun");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Weapon_Fire, "Player.Ability.Weapon.Fire");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Weapon_SwitchAmmo, "Player.Ability.Weapon.SwitchAmmo");

	/**Weapon Tags**/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Gun, "Player.Weapon.Gun");

	/**Player Event Tags**/
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Gun, "Player.Event.Equip.Gun");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Gun, "Player.Event.Unequip.Gun");
} 