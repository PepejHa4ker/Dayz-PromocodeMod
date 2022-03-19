modded class MissionServer
{

	override void OnInit()
	{
		super.OnInit();
		Print( "PromocodeMod server init" );
		

	}

	override PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx)
  	{
  		string characterType;
  		SyncRespawnModeInfo(identity);
  
  		if ( ProcessLoginData(ctx) && (m_RespawnMode == GameConstants.RESPAWN_MODE_CUSTOM) && !GetGame().GetMenuDefaultCharacterData(false).IsRandomCharacterForced() )
		{
			if (GetGame().ListAvailableCharacters().Find(GetGame().GetMenuDefaultCharacterData().GetCharacterType()) > -1)
				characterType = GetGame().GetMenuDefaultCharacterData().GetCharacterType();
  			else //random type
 				characterType = GetGame().CreateRandomPlayer();
  		}
  		else
  		{
 		    characterType = GetGame().CreateRandomPlayer();
            GetGame().GetMenuDefaultCharacterData().GenerateRandomEquip();
        }
  		auto spawn_set_entry = GetSpawnSetEntrySettings(identity.GetPlainId());
        if (CreateCharacter(identity, pos, ctx, characterType))
        {
			GetPromocodeUsageHandler().HandleSpawnEvent( m_player, spawn_set_entry );

  			if ( spawn_set_entry )
  			{
			
				if ( spawn_set_entry.HasAtLeastOneActiveSpawnSet( m_player )
				{
					return m_player;
				} 
			
			}
  			EquipCharacter(GetGame().GetMenuDefaultCharacterData());
			
  		}
  		return m_player;
  	}
  
	/*
	override PlayerBase OnClientNewEvent( PlayerIdentity identity, vector pos, ParamsReadContext ctx )
	{
		PlayerBase player = super.OnClientNewEvent( identity, pos, ctx );
		auto spawn_set_entry = GetSpawnSetEntrySettings(identity.GetPlainId());
		GetPromocodeUsageHandler().HandleSpawnEvent( player, spawn_set_entry );
		return player;
	}
	
	override void EquipCharacter(MenuDefaultCharacterData char_data) 
	{
		auto spawn_set_entry = GetSpawnSetEntrySettings(identity.GetPlainId());
		if ( spawn_set_entry ) 
		{
			array<PromocodeEntrySettings> promocodes = spawn_set_entry.Promocodes();
			
			if ( HasAtLeastOneActivePromocode( promocodes, m_Player.GetIdentity().GetPlainId() )
			{
				return;
			} 
			else 
			{
				super.EquipCharacter( chat_data );
			}
		}
	}
	*/
	


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