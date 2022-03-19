modded class MissionServer
{

	override void OnInit()
	{
		super.OnInit();
		Print( "PromocodeMod server init" );
		

	}
	
	override PlayerBase OnClientNewEvent( PlayerIdentity identity, vector pos, ParamsReadContext ctx )
	{
		PlayerBase player = super.OnClientNewEvent( identity, pos, ctx );
		auto spawn_set_entry = GetSpawnSetEntrySettings(identity.GetPlainId());
		GetPromocodeUsageHandler().HandleSpawnEvent( player, spawn_set_entry );
		return player;
	}
	


	override void OnEvent( EventType eventTypeId, Param params ) 
	{
		switch ( eventTypeId )
		{
			case ChatMessageEventTypeID:
			ChatMessageEventParams chat_params = ChatMessageEventParams.Cast( params );
            GetPromocodeUsageHandler().HandleChatMessage( chat_params.param1, chat_params.param2, chat_params.param3, chat_params.param4, GetPlayerFromName( chat_params.param2 ) );
			break;
						
		}
		super.OnEvent( eventTypeId, params );
	}

    

    private PlayerBase GetPlayerFromName( string name )
    {
        foreach ( PlayerBase player: m_Players )
        {
            if ( player.GetIdentity().GetName() == name )
                return player;
        }
        return NULL;
    }

	
}