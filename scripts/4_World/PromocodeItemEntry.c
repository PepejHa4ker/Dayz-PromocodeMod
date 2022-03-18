class PromocodeItemEntry 
{

	ref array<PromocodeItemEntry> attachments = NULL;
	string class_name;
	int amount = 1;

}

class PromocodeWeaponEntry
{
	ref array<PromocodeItemEntry> attachments = NULL;
	string class_name;
	bool change_fire_mode;
	int fire_mode;
	bool attach_magazine;
	string magazine_class_name;
	
	
	void SpawnWeapon( PlayerBase player, bool on_ground ); 
	{
		Weapon_Base weapon;
		if ( on_ground ) 
		{
			weapon = Weapon_Base.Cast( GetGame().CreateObject( class_name, player.GetPosition() ) );
		} 
		else 
		{
			weapon = Weapon_Base.Cast( player.GetInventory().CreateInInventory( class_name ));
		}
		if ( weapon == NULL ) 
		{
			return;
		}
		if ( change_fire_mode ) 
		{
			weapon.OnFireModeChange( fire_mode );
		}
		if ( attach_magazine ) 
		{
			weapon.SpawnAttachedMagazine( magazine_class_name );
					
		}
		if ( attachments != NULL )
		{
			foreach(auto attachment : attachments )
			{
				weapon.GetInventory().CreateAttachment( attachment.class_name );
				
			} 
		}
    
	}
}