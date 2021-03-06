class PromocodeUsageHandler
{
	void HandleChatMessage( int channel, string name, string text, string color, PlayerBase player )
    {
    	auto settings = GetPromocodeModServerSettings();
    	array<string> tokens = {};
    	text.Split( " ", tokens );
		if ( !( channel == 0 || channel & CCDirect) )
		{
			return;
		}
    	if ( tokens.Count() >= 2 ) 
    	{
    		if ( tokens.Get( 0 ) == settings.GetPromocodeCommand() )
    		{
    			HandlePromocodeCommand( player, tokens.Get( 1 ), false );
    		}
    	}

    }
	
	void HandleSpawnEvent( PlayerBase player, PromocodeSpawnSetEntrySettings spawn_set_entry )
	{
		if ( spawn_set_entry == NULL )
		{
			return;
		}
		foreach (auto promocode : spawn_set_entry.promocodes)
		{
			HandlePromocodeCommand( player, promocode, true );
		}
	}
	
	bool CanUse( PromocodeEntrySettings promocode_entry, PromocodePlayerEntry player_entry, PlayerBase player, bool on_spawn )
	{
		
		if ( player_entry.activation_date_unix + player_entry.GetPromocodeDays() > PMStatic.GetUnixNow() ) 
		{
			if ( !on_spawn )
				PMStatic.SendPlayerMessage(player, "Похоже, срок действия промокода закончился");
			
			return false;

		}
		if ( promocode_entry.GetMaxUsages() > 0 && player_entry.usages >= promocode_entry.GetMaxUsages() )
		{
			if ( !on_spawn )
				PMStatic.SendPlayerMessage(player, "Достигнуто макисмальное количество использований промокода");

			return false;
		}
		
		
		if ( player_entry.last_use_unix_ts + promocode_entry.GetDurationMinutes() * 60 * 1000 > PMStatic.GetUnixNow() )
		{
			if ( !on_spawn )
				PMStatic.SendPlayerMessage(player, "Вы не можете использовать этот промокод еще " + GetRemainingMinutesToUsePromocode( player_entry.last_use_unix_ts, promocode_entry.GetDurationMinutes() ) + " минут" );

			return false;
		}
		
		return true;
	}
	
	private int GetRemainingMinutesToUsePromocode( int last_use_unix, int duration_minutes )
	{
		int timeout_end_timestamp = last_use_unix + (duration_minutes * 60 * 1000);
		if ( PMStatic.GetUnixNow() >= timeout_end_timestamp ) 
		{
			return 0;
		}
		else
		{
			return (timeout_end_timestamp - PMStatic.GetUnixNow()) / 60 / 1000;
		}
	}
	
	private void Use( PromocodeEntrySettings promocode_entry, PromocodePlayerEntry player_entry, PlayerBase player )
	{
		promocode_entry.TryToGive( player );
		player_entry.usages += 1;
	    player_entry.last_use_unix_ts = PMStatic.GetUnixNow();
	    promocode_entry.Save();
	    PMStatic.SendPlayerMessage( player, "Промокод " + promocode_entry.GetEntryId() + " был успешно использован");
	}

    private void HandlePromocodeCommand( PlayerBase player, string promocode_id, bool on_spawn )
    {
    	auto entry = GetPromocodeEntrySettings( promocode_id );
    	if ( !entry )
    	{
			if ( !on_spawn ) 
				PMStatic.SendPlayerMessage(player, "Промокод " + promocode_id + " не существует");
			
    	} 
    	else
    	{
			if ( entry.OnlyOnRespawn() ) 
			{
				PMStatic.SendPlayerMessage(player, "Вы не можете использовать этот промокод");
				return;
			}
			auto player_entry = entry.GetPlayerEntry( player );
			if ( !player_entry ) 
			{
				if ( entry.IsPublic() ) 
				{
					auto new_player_entry = new PromocodePlayerEntry;
					new_player_entry.player_id = player.GetIdentity().GetPlainId();
					entry.players.Insert( new_player_entry );
					Use( entry, new_player_entry, player );
					return;
				} 
				else // access denied
				{
					if ( !on_spawn ) 
					
						PMStatic.SendPlayerMessage(player, "У Вас нет доступа к этому промокоду" );
					return;
					
				}
			}
			if ( CanUse( entry, player_entry, player, false ) )
   	    		Use( entry, player_entry, player );	
			
				
	   	}
    	
    }
}

static ref PromocodeUsageHandler g_PromocodeUsageHandler;
static ref PromocodeUsageHandler GetPromocodeUsageHandler() {
    if (!g_PromocodeUsageHandler) {
        g_PromocodeUsageHandler = new ref PromocodeUsageHandler;
		
    }
    return g_PromocodeUsageHandler;
}