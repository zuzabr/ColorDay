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
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Interact, "InputTag.Interact");

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


	/**Color Projectile Tag**/
	UE_DEFINE_GAMEPLAY_TAG(Projectile_Red, "Projectile.Red");
	UE_DEFINE_GAMEPLAY_TAG(Projectile_Grey, "Projectile.Grey");
	UE_DEFINE_GAMEPLAY_TAG(Projectile_Green, "Projectile.Green");
	UE_DEFINE_GAMEPLAY_TAG(Projectile_Blue, "Projectile.Blue");

	/**Interactive Actor Ability*/
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Ability_Activate, "ColorActor.Ability.Activate");
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Ability_Deactivate, "ColorActor.Ability.Deactivate");
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Ability_BecomeExplosive, "ColorActor.Ability.BecomeExplosive");

	/**Interactive Actor Tags*/
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Status_Active, "ColorActor.Status.Active");
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Status_Explosive, "ColorActor.Status.Explosive");
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Status_HasPhysics, "ColorActor.Status.HasPhysics");
	
	/**Interactive Actor Instigators*/
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Instigator_Player, "ColorActor.Instigator.Player");
}