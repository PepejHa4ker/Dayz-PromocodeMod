class PromocodeEntrySettings 
{
	private static string CONFIG_DIR = "$profile:PromocodeMod/Promocodes";

   	protected string entry_id;
	protected int duration_minutes;
	protected bool public;
	protected bool spawn_on_ground;
	protected bool only_on_respawn;
	protected int max_usages;
	ref array<PromocodeItemEntry> items;
	ref array<PromocodeWeaponEntry> weapons;
	ref array<PromocodePlayerEntry> players;


	void PromocodeEntrySettings( string id ) 
	{
		entry_id = id;
	}

	string GetPath() 
	{
		return CONFIG_DIR + "\\" + entry_id + ".json";
	}
	
	bool SpawnOnGround()
	{
		return spawn_on_ground;
	}  

    string GetEntryId()
    {
        return entry_id;
    }

    int GetDurationMinutes()
    {
    	return duration_minutes;
    }

  
	bool IsPublic()
	{
		return public;
	}
	
	
	int GetMaxUsages()
	{
		return max_usages;
	}

    ref array<PromocodePlayerEntry> GetPlayers()
    {
    	return players;
    }

    PromocodePlayerEntry GetPlayerEntry( PlayerBase player ) 
    {
        foreach (auto entry : players )
        {
            if ( entry.GetPlayerId() == player.GetIdentity().GetPlainId() ) 
            {
                return entry;
            }
			
        }
        return NULL;
    }



    void TryToGive(PlayerBase player)  
    {
		foreach(auto item : items) 
		{
			for(int i = 0; i < item.amount; i++) 
			{
				CreateItem( item.class_name, spawn_on_ground, player );
			}
			
		}
		foreach(auto weapon : weapons )
		{
			weapon.SpawnWeapon ( player, spawn_on_ground );
		}

    }
	
	private static ItemBase CreateItem( string class_name, bool on_ground, PlayerBase player )
	{
		ItemBase item;
		if ( on_ground ) 
		{
			item = ItemBase.Cast( GetGame().CreateObject( class_name, player.GetPosition() ) );
		} 
		else 
		{
			item = ItemBase.Cast( player.GetInventory().CreateInInventory( class_name ) );
		}
		if ( item != NULL ) 
		{
			item.SetQuantity(item.GetQuantityMax());
		}
		return item;
	}


	void Save() 
	{
        
        if ( !FileExist( CONFIG_DIR ) ) 
        {
            MakeDirectory ( CONFIG_DIR );
        }
        JsonFileLoader<PromocodeEntrySettings>.JsonSaveFile ( GetPath(), this );
        
    }

    bool Load()
    {

        if ( FileExist ( GetPath() ) ) 
        {
            JsonFileLoader<PromocodeEntrySettings>.JsonLoadFile ( GetPath(), this );
            return true;
		
        } 
        else 
        {
            return false;
        }

    }
}

static ref PromocodeEntrySettings GetPromocodeEntrySettings( string id )
{
    
    auto entry = PromocodeEntrySettings( id );
    if ( entry.Load() )
    {
        return entry;
    }
    else
    {
        return NULL;
    }
}

