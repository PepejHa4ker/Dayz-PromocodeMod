class PromocodeSpawnSetEntrySettings
{
	private static string CONFIG_DIR = "$profile:PromocodeMod/SpawnSets";
	protected string entry_id;
	ref array<string> promocodes;
	
	
	
	bool HasAtLeastOneActiveSpawnSet( PlayerBase player )
	{
		foreach(auto promocode_id : promocodes  )
		{
			
			auto promocode_entry = GetPromocodeEntrySettings(promocode_id);

			if ( !promocode_entry ) continue;
			auto player_entry = promocode_entry.GetPlayerEntry( player );
			if ( !player_entry ) continue;
			if ( GetPromocodeUsageHandler().CanUse( promocode_entry, player_entry, NULL, true )
			{
				return true;
			}
		}
		return false;
	}
	
	void PromocodeSpawnSetEntrySettings( string id ) 
	{
		entry_id = id;
	}

	string GetPath() 
	{
		return CONFIG_DIR + "\\" + entry_id + ".json";
	}
	
	void Save() 
	{
        
        if ( !FileExist( CONFIG_DIR ) ) 
        {
            MakeDirectory ( CONFIG_DIR );
        }
        JsonFileLoader<PromocodeSpawnSetEntrySettings>.JsonSaveFile ( GetPath(), this );
        
    }

    bool Load()
    {

        if ( FileExist ( GetPath() ) ) 
        {
            JsonFileLoader<PromocodeSpawnSetEntrySettings>.JsonLoadFile ( GetPath(), this );
            return true;
		
        } 
        else 
        {
            return false;
        }

    }
}

static ref PromocodeSpawnSetEntrySettings GetSpawnSetEntrySettings( string id )
{
    
    auto entry = PromocodeSpawnSetEntrySettings( id );
    if ( entry.Load() )
    {
        return entry;
    }
    else
    {
        return NULL;
    }
}
