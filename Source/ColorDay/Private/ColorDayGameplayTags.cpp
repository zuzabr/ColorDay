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
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Weapon_SwitchAmmo, "InputTag.Weapon.SwitchAmmo");


	/**Item Input Tags**/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Item_PutDown, "InputTag.Item.PutDown");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Item_Throw, "InputTag.Item.Throw");

	/**Player Ability**/
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Gun, "Player.Ability.Equip.Gun");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Gun, "Player.Ability.Unequip.Gun");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Weapon_Fire, "Player.Ability.Weapon.Fire");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Weapon_SwitchAmmo, "Player.Ability.Weapon.SwitchAmmo");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Item_PutDown, "Player.Ability.Item.PutDown");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Item_Throw, "Player.Ability.Item.Throw");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Item_Grab, "Player.Ability.Item.Grab");

	/**Weapon Tags**/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Gun, "Player.Weapon.Gun");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Item, "Player.Weapon.Item");

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
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Ability_TakeItem, "ColorActor.Ability.TakeItem");
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Ability_Interact, "ColorActor.Ability.Interact");

	/**Interactive Actor Tags*/
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Status_Active, "ColorActor.Status.Active");
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Status_Explosive, "ColorActor.Status.Explosive");
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Status_HasPhysics, "ColorActor.Status.HasPhysics");
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Status_Grabbed, "ColorActor.Status.Grabbed");
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Status_Locked, "ColorActor.Status.Locked");
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Status_Opened, "ColorActor.Status.Opened");

	
	/**Interactive Actor Instigators*/
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Instigator_Player, "ColorActor.Instigator.Player");

	/**Process tags*/
	UE_DEFINE_GAMEPLAY_TAG(Process_NeedUnequip, "Process.NeedUnequip");
	UE_DEFINE_GAMEPLAY_TAG(Process_NeedEquipWeapon, "Process.NeedEquipWeapon");
	UE_DEFINE_GAMEPLAY_TAG(Process_NeedEquipItem, "Process.NeedEquipItem");
}