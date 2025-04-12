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


	/**Character Ability**/
	UE_DEFINE_GAMEPLAY_TAG(Character_Ability_Death, "Character.Ability.Death");
	UE_DEFINE_GAMEPLAY_TAG(Character_Status_Dead, "Character.Status.Dead");
	UE_DEFINE_GAMEPLAY_TAG(Character_Damage, "Character.Damage");

	/**NPC Ability**/
	UE_DEFINE_GAMEPLAY_TAG(NPC_Ability_MeleeAttack, "NPC.Ability.MeleeAttack");
	UE_DEFINE_GAMEPLAY_TAG(NPC_Ability_RangeAttack, "NPC.Ability.RangeAttack");
	UE_DEFINE_GAMEPLAY_TAG(NPC_Ability_GotDamage, "NPC.Ability.GotDamage");

	/**NPC States**/
	UE_DEFINE_GAMEPLAY_TAG(NPC_State, "NPC.State");
	UE_DEFINE_GAMEPLAY_TAG(NPC_State_Passive, "NPC.State.Passive");
	UE_DEFINE_GAMEPLAY_TAG(NPC_State_Passive_Patrol, "NPC.State.Passive.Patrol");
	UE_DEFINE_GAMEPLAY_TAG(NPC_State_Passive_Hiding, "NPC.State.Passive.Hiding");
	UE_DEFINE_GAMEPLAY_TAG(NPC_State_Investigate, "NPC.State.Investigate");
	UE_DEFINE_GAMEPLAY_TAG(NPC_State_Dead, "NPC.State.Dead");
	UE_DEFINE_GAMEPLAY_TAG(NPC_State_Staggered, "NPC.State.Staggered");
	UE_DEFINE_GAMEPLAY_TAG(NPC_State_Attack, "NPC.State.Attack");
	UE_DEFINE_GAMEPLAY_TAG(NPC_State_Attack_MeleeAttack, "NPC.State.Attack.MeleeAttack");
	UE_DEFINE_GAMEPLAY_TAG(NPC_State_Attack_RangeAttack, "NPC.State.Attack.RangeAttack");

	/**Weapon Tags**/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Gun, "Player.Weapon.Gun");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Item, "PlayerPlayer.Weapon.Item");

	/**Player Event Tags**/
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Gun, "Player.Event.Equip.Gun");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Gun, "Player.Event.Unequip.Gun");


	/**Color Projectile Tag**/
	UE_DEFINE_GAMEPLAY_TAG(Projectile_Red, "Projectile.Red");
	UE_DEFINE_GAMEPLAY_TAG(Projectile_Grey, "Projectile.Grey");
	UE_DEFINE_GAMEPLAY_TAG(Projectile_Green, "Projectile.Green");
	UE_DEFINE_GAMEPLAY_TAG(Projectile_Blue, "Projectile.Blue");
	UE_DEFINE_GAMEPLAY_TAG(Projectile_Yellow, "Projectile.Yellow");

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
	UE_DEFINE_GAMEPLAY_TAG(ColorActor_Instigator_NPC, "ColorActor.Instigator.NPC");

	/**Process tags*/
	UE_DEFINE_GAMEPLAY_TAG(Process_NeedUnequip, "Process.NeedUnequip");
	UE_DEFINE_GAMEPLAY_TAG(Process_NeedEquipWeapon, "Process.NeedEquipWeapon");
	UE_DEFINE_GAMEPLAY_TAG(Process_NeedEquipItem, "Process.NeedEquipItem");

	/**Shared tags*/
	UE_DEFINE_GAMEPLAY_TAG(Shared_Damage, "Shared.Damage");
}